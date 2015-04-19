/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: chip_config.c 2496 2013-03-31 13:19:15Z ertl-honda $
 */

/*
 * �������åȰ�¸�⥸�塼���RMA1�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>
#include "pl310.h"
#ifdef TOPPERS_SAFEG_SECURE
#include "syscalls_api.h"
#endif /* TOPPERS_SAFEG_SECURE */

#ifdef TOPPERS_SAFEG_SECURE
/*
 * L2����å���ν����
 */
uint32_t l2cache_init(const uint32_t core_id,
					  const uint32_t ns,
					  const uint32_t a,
					  const uint32_t b,
					  const uint32_t c)
{
	pl310_init(0x82000fff, 0x4c440000);
	return SAFEG_OK(SAFEG_SYSCALL_RET__DONT_SWITCH);
}

struct safeg_syscall l2init_call = {
	.is_t_callable  = 1,
	.is_nt_callable = 1,
	.name = "l2init",
	.function = l2cache_init,
};

/*
 * L2����å���ǥХå��쥸�����񤭹���
 */
uint32_t l2cache_debug_set(const uint32_t core_id,
					  const uint32_t ns,
					  const uint32_t a,
					  const uint32_t b,
					  const uint32_t c)
{
	pl310_debug_set(a);
	return SAFEG_OK(SAFEG_SYSCALL_RET__DONT_SWITCH);
}

struct safeg_syscall l2debug_set_call = {
	.is_t_callable  = 1,
	.is_nt_callable = 1,
	.name = "l2debug",
	.function = l2cache_debug_set,
};

#endif /* TOPPERS_SAFEG_SECURE */

/*
 *  ���åװ�¸�ν����
 */
void
chip_initialize(void)
{
	/*
	 * ARM��¸�ν����
	 */
	core_initialize();

	/*
	 * GIC Distributor�����
	 */
	gicd_init();

	/*
	 * GIC CPU���󥿥ե����������
	 */
	gicc_init();

	/*
	 * ����å����̵����
	 */
	cache_disable();
    
	/*
	 * MMU��ͭ����
	 */
	mmu_init();

	/*
	 * ����å����ͭ����
	 */
	cache_enable();

#if defined(TOPPERS_SAFEG_SECURE) || defined(TOPPERS_SAFEG_NONSECURE)
	/*
	 * ����ߥ٥����ơ��֥�� VECTOR_TABLE_BASE �쥸���������ꤹ��
	 */
	extern void *vector_table;
	CP15_SET_VBAR((uint32_t) &vector_table);
#endif /* defined(TOPPERS_SAFEG_SECURE) || defined(TOPPERS_SAFEG_NONSECURE) */

#ifdef TOPPERS_SAFEG_SECURE
	/*
	 * L2����å��������ؿ���SafeG����Ͽ
	 */
	uint32_t id;
	safeg_syscall_regdyn(&l2init_call, &id);

	/*
	 * L2����å���ǥХå��쥸�����񤭹��ߴؿ���SafeG����Ͽ
	 */
	safeg_syscall_regdyn(&l2debug_set_call, &id);
#endif /*  TOPPERS_SAFEG_SECURE */
}

/*
 *  ���åװ�¸�ν�λ����
 */
void
chip_exit(void)
{
	extern void    software_term_hook(void);
	void (*volatile fp)(void) = software_term_hook;

	/*
	 *  software_term_hook�ؤΥݥ��󥿤򡤰�övolatile����Τ���fp����
	 *  �����Ƥ���Ȥ��Τϡ�0�Ȥ���Ӥ���Ŭ���Ǻ������ʤ��褦�ˤ��뤿
	 *  ��Ǥ��롥
	 */
	if (fp != 0) {
		(*fp)();
	}

	/*
	 *  ARM��¸�ν�λ����
	 */
	core_terminate();

	/*
	 *  GIC��CPU���󥿥ե����������
	 */
	gicc_stop();

	/*
	 *  GIC Distributor�����
	 */
	gicd_stop();
}

/*
 *  ������׵�饤���°��������
 *
 *  ASP�����ͥ�Ǥ����Ѥ����ꤷ�ơ��ѥ�᡼�����顼�ϥ����������ǥ�����
 *  �����Ƥ��롥FI4�����ͥ�����Ѥ�����ˤϡ����顼���֤��褦�ˤ��٤�
 *  �Ǥ�����
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
	assert(VALID_INTNO(intno));
	assert(TMIN_INTPRI <= intpri && intpri <= TMAX_INTPRI);

	/*
	 *  ������׵�Υޥ���
	 *
	 *  ����ߤ�����դ����ޤޡ���٥�ȥꥬ�����å��ȥꥬ������䡤��
	 *  ����ͥ���٤������Ԥ��Τϴ��ʤ��ᡤ�����°���ˤ�����餺��
	 *  ��ö�ޥ������롥
	 */    
	x_disable_int(intno);

	/*
	 * °��������
	 */
	if ((intatr & TA_EDGE) != 0U) {
		gicd_config(intno, true, true);
		x_clear_int(intno);
	}
	else {
		gicd_config(intno, false, true);
	}

	/*
	 * �����ͥ���٥ޥ���������
	 */
	gicd_set_priority(intno, INT_IPM(intpri));    
	gicd_set_target(intno, 1);
    
	/*
	 * ����ߤ����
	 */
	if ((intatr & TA_ENAINT) != 0U){
		(void)x_enable_int(intno);
	} 
}

#ifndef OMIT_DEFAULT_INT_HANDLER

/*
 *  ̤����γ���ߤ����ä����ν���
 */
void
default_int_handler(void){
	syslog_0(LOG_EMERG, "Unregistered Interrupt occurs.");
	exit_kernel();
}

#endif /* OMIT_DEFAULT_INT_HANDLER */
