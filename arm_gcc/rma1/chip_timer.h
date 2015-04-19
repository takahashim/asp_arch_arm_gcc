/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: chip_timer.h 2495 2013-03-30 02:22:13Z ertl-honda $
 */

/*
 *  �����ޥɥ饤�С�CMT4 or TMU�ѡ�
 *  ����ͥ�0,1,2�Τ����줫�����
 */

#ifndef TOPPERS_CHIP_TIMER_H
#define TOPPERS_CHIP_TIMER_H

#include <sil.h>

/*
 * CM4�쥸����
 */
#define CM4STR  0xe6148000
#define CM4CSR  0xe6148040
#define CM4CNT  0xe6148044
#define CM4COR  0xe6148048

#define CMxSTR_STR5 0x0020
#define CMxCSR_CMF  0x8000
#define CMxCSR_OVF  0x4000
#define CMxCSR_CMM  0x0100

/*
 * TMU�쥸����
 */
#if USE_TMU_ID == 0
#define TMU_BASE  0xFFF80000
#define TMU_IRQ_BASE  (198 + 32)
#else /* USE_TMU_ID == 1 */
#define TMU_BASE  0xFFF90000
#define TMU_IRQ_BASE  (170 + 32)
#endif /* USE_TMU_ID == 0 */

#define TMU_TSTR  (TMU_BASE + 0x0004)  /* B */

#if USE_TMU_CH == 0
#define TMU_TCOR  (TMU_BASE + 0x0008)  /* W */
#define TMU_TCNT  (TMU_BASE + 0x000C)  /* W */
#define TMU_TCR   (TMU_BASE + 0x0010)  /* H */
#define TMU_STR   0x01
#define GIC_IRQNO_TMU (TMU_IRQ_BASE + 0)
#elif USE_TMU_CH == 1
#define TMU_TCOR  (TMU_BASE + 0x0014)  /* W */
#define TMU_TCNT  (TMU_BASE + 0x0018)  /* W */
#define TMU_TCR   (TMU_BASE + 0x001C)  /* H */
#define TMU_STR   0x02
#define GIC_IRQNO_TMU (TMU_IRQ_BASE + 1)
#elif USE_TMU_CH == 2
#define TMU_TCOR  (TMU_BASE + 0x0020)  /* W */
#define TMU_TCNT  (TMU_BASE + 0x0024)  /* W */
#define TMU_TCR   (TMU_BASE + 0x0028)  /* H */
#define TMU_STR   0x04
#define GIC_IRQNO_TMU (TMU_IRQ_BASE + 2)
#else /* USE_TMU_CH == 2 */
#error
#endif /* USE_TMU_CH == 0 */

/*
 *  TCR�Υӥå����
 */
#define TCR_UNF        0x0100
#define TCR_UNIE       0x0020
#define TCR_TPSC_4     0x0000
#define TCR_TPSC_16    0x0001
#define TCR_TPSC_64    0x0002
#define TCR_TPSC_256   0x0003
#define TCR_TPSC_1024  0x0004

#ifdef USE_CMT4

/*
 *  �����޳���ߥϥ�ɥ���Ͽ�Τ�������
 */
#define INHNO_TIMER     (169+32) /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_TIMER     (169+32) /* ������ֹ� */

#else /* !USE_CMT4 */

/*
 *  �����޳���ߥϥ�ɥ���Ͽ�Τ�������
 */
#define INHNO_TIMER     GIC_IRQNO_TMU /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_TIMER     GIC_IRQNO_TMU /* ������ֹ� */

#endif /* USE_CMT4 */

#ifndef INTPRI_TIMER
#define INTPRI_TIMER    -6            /* �����ͥ���� */
#endif /* INTPRI_TIMER */

#define INTATR_TIMER    0U            /* �����°�� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �������ͤ�����ɽ���η�
 */
typedef uint32_t    CLOCK;

/*
 *  �����ޤΥ���å����ݻ������ѿ�  
 */
extern uint32_t timer_clock;

/*
 *  �������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 */
#define TO_CLOCK(nume, deno) (timer_clock * (nume) / (deno))
#define TO_USEC(clock)       (((SYSUTM) clock) * 1000U / timer_clock)


/*
 *  ����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK        ((CLOCK) 0xffffffffU)

/*
 *  �����ޤθ����ͤ�����ȯ�������ͤȤߤʤ�����Ƚ��
 */
#define GET_TOLERANCE    100U    /* �����٤�θ��Ѥ��͡�ñ�̤�����ɽ����*/
#define BEFORE_IREQ(clock) \
            ((clock) >= TO_CLOCK(TIC_NUME, TIC_DENO) - GET_TOLERANCE)

/*
 *  �����ޤε�ư����
 *
 *  �����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
extern void    target_timer_initialize(intptr_t exinf);

/*
 *  �����ޤ���߽���
 *
 *  �����ޤ�ư�����ߤ����롥
 */
extern void    target_timer_terminate(intptr_t exinf);

/*
 *  �����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
target_timer_get_current(void)
{
#ifdef USE_CMT4
	return(sil_rew_mem((void*)CM4CNT));
#else  /* !USE_CMT4 */
	return(TO_CLOCK(TIC_NUME, TIC_DENO) - sil_rew_mem((void*)TMU_TCNT));
#endif /* USE_CMT4 */
}

/*
 *  �����޳�����׵�Υ����å�
 */
Inline bool_t
target_timer_probe_int(void)
{
#ifdef USE_CMT4
	return(sil_reh_mem((void*)CM4CSR) & CMxCSR_CMF);
#else  /* !USE_CMT4 */
	return(sil_reh_mem((void*)TMU_TCR) & TCR_UNF);
#endif /* USE_CMT4 */
}

/*
 *  �����޳���ߥϥ�ɥ�
 */
extern void    target_timer_handler(void);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_CHIP_TIMER_H */
