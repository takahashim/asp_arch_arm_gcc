/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: chip_timer.c 2495 2013-03-30 02:22:13Z ertl-honda $
 */

/*
 *  �����ޥɥ饤�С�ARM PrimeCell Timer Module�ѡ�
 */

#include "kernel_impl.h"
#include "time_event.h"
#include <sil.h>
#include "target_timer.h"

/*
 *  �����ޤΥ���å����ݻ������ѿ�
 *  target_initialize() �ǽ��������롥
 */
uint32_t timer_clock;

/*
 *  �����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
	CLOCK    cyc = TO_CLOCK(TIC_NUME, TIC_DENO);

#ifdef USE_CMT4
	/* 32-bit, free-running, enable interrupt, RCLK/1 */
	sil_wrh_mem((void*)CM4CSR, (CMxCSR_CMM|0x27));
	sil_wrw_mem((void*)CM4COR, cyc);
	sil_wrw_mem((void*)CM4CNT, 0);
	sil_wrh_mem((void*)CM4STR, CMxSTR_STR5);
#else /* !USE_CMT4 */
	/*
	 *  �����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	sil_wrb_mem((void*)TMU_TSTR,
				(sil_reb_mem((void*)TMU_TSTR) & ~TMU_STR));  /* ��������� */
	assert(cyc <= MAX_CLOCK);             /* �����޾���ͤΥ����å� */

	sil_wrh_mem((void*)TMU_TCR, (TCR_UNIE | TCR_TPSC_4)); /* ʬ�������ꡢ�����ߵ��� */
	sil_wrw_mem((void*)TMU_TCOR, cyc); /* timer constant�쥸�����򥻥å� */
	sil_wrw_mem((void*)TMU_TCNT, cyc); /* �����󥿡��򥻥å� */

	/* �������׵�򥯥ꥢ */
	sil_wrh_mem((void*)TMU_TCR,
				(sil_reh_mem((void*)TMU_TCR) & ~TCR_UNF));

	/* �����ޥ������� */
	sil_wrb_mem((void*)TMU_TSTR,
				(sil_reb_mem((void*)TMU_TSTR) | TMU_STR));
#endif /* USE_CMT4 */
}

/*
 *  �����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
#ifdef USE_CMT4
	/* Stop timer */
	sil_wrh_mem((void*)CM4STR, 0);
	/* Clear interrupt request */
	sil_wrh_mem((void*)CM4CSR,
				sil_reh_mem((void*)CM4CSR) & ~(CMxCSR_CMF|CMxCSR_OVF));
#else /* !USE_CMT4 */
	/* �����ޤ���� */
	sil_wrb_mem((void*)TMU_TSTR,
				(sil_reb_mem((void*)TMU_TSTR) & ~TMU_STR));
	/* �������׵�򥯥ꥢ */
	sil_wrh_mem((void*)TMU_TCR,0);
#endif /* USE_CMT4 */
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
#ifdef USE_CMT4
	/* Clear interrupt request */
	sil_wrh_mem((void*)CM4CSR,
				sil_reh_mem((void*)CM4CSR) & ~(CMxCSR_CMF|CMxCSR_OVF));
#else /* !USE_CMT4 */
	/* �������׵�򥯥ꥢ */
	sil_wrh_mem((void*)TMU_TCR,
				(sil_reh_mem((void*)TMU_TCR) & ~TCR_UNF));
#endif /* USE_CMT4 */

	i_begin_int(INTNO_TIMER);
	signal_time();                    /* ������ƥ��å��ζ��� */
	i_end_int(INTNO_TIMER);
}
