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
 *  @(#) $Id: chip_config.h 2480 2013-02-21 13:15:21Z ertl-honda $
 */

/*
 *  ���åװ�¸�⥸�塼���RMA1�ѡ�
 *
 *  �����ͥ�Υ��åװ�¸���Υ��󥯥롼�ɥե����롥kernel_impl.h�Υ���
 *  ���åȰ�¸���ΰ����դ��Ȥʤ롥
 */

#ifndef TOPPERS_CHIP_CONFIG_H
#define TOPPERS_CHIP_CONFIG_H

#include "rma1.h"
#include "gic.h"

/*
 *  ����ߥϥ�ɥ��ֹ�ȳ�����ֹ�˴ؤ������
 */
#define TMIN_INTNO  GIC_TMIN_INTNO 
#define TMAX_INTNO  GIC_TMAX_INTNO
#define TNUM_INT    GIC_TNUM_INT  

#define TMIN_INHNO  GIC_TMIN_INTNO 
#define TMAX_INHNO  GIC_TMAX_INTNO
#define TNUM_INH    GIC_TNUM_INT

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ������ֹ���ϰϤ�Ƚ��
 */
#define VALID_INTNO(intno) (TMIN_INTNO <= (intno) && (intno) <= TMAX_INTNO)
#define VALID_INTNO_DISINT(intno)    VALID_INTNO(intno)
#define VALID_INTNO_CFGINT(intno)    VALID_INTNO(intno)
#define VALID_INTNO_ATTISR(intno)    VALID_INTNO(intno)

/*
 *  ����ߥϥ�ɥ����Ͽ�ѥơ��֥�
 */
extern const FP inh_tbl[TNUM_INH];

/*
 *  ����ߥϥ�ɥ������
 * 
 *  ����ߥϥ�ɥ��ֹ�inhno�γ���ߥϥ�ɥ�ε�ư���Ϥ�inthdr�����ꤹ��
 */
Inline void
x_define_inh(INHNO inhno, FP int_entry)
{
	assert(TMIN_INHNO <= inhno && inhno <= TMAX_INHNO);
}

/*
 *  ����ߥϥ�ɥ�ν����������������ޥ���
 *
 */
#define INT_ENTRY(inhno, inthdr)    inthdr
#define INTHDR_ENTRY(inhno, inhno_num, inthdr) extern void inthdr(void);

#endif /* TOPPERS_MACRO_ONLY */  

/*
 *  �����ͥ���٥ޥ������饤�֥���PL390��GIC���ѡ�
 *
 *  GIC�Ǥϡ�GIC���ͥ���٥쥸������CPU�γ����ͥ���٥ޥ�����IPM�ˤ����ꤹ�롥  
 *  �����ͥ���٥ޥ������ͤ��礭���ۤ���ͥ���٤Ǥ��롥
 *  �����ͥ���٥ޥ������ʳ���GIC�μ������Υѥ�᡼���ˤ�ꡤ256,64,32,16 ����
 *  �����ǽ�Ǥ��롥 
 * 
 *  IPM����¸���Ƥ�������ˡ������ͥ���٤γ���ɽ����-1����Ϣ³��������͡�
 *  ��Ȥ����Ȥ��ǽ�Ǥ��뤬��;�פʷ׻���ɬ�פˤʤ롥������򤱤뤿�ᡤIPM��
 *  ��¸������ˤϡ�GIC�ǰ���ͥ���٤η����Ȥ��롥�����ͤ�����ͥ���٥ޥ���
 *  ������ɽ���ȸƤӡ�IIPM�Ƚ񤯤��Ȥˤ��롥 
 */

/*
 *  �����ͥ���٥ޥ����γ���ɽ��������ɽ�����Ѵ�
 *
 *  ������֥����Υ������ե����뤫�饤�󥯥롼�ɤ�����Τ���ˡ���
 *  ���㥹�Ȥ��ʤ�������Ѱդ��Ƥ��롥
 */
#ifndef TOPPERS_MACRO_ONLY
#define EXT_IPM(iipm)    ((PRI)(iipm - GICC_PMR_MASK))    /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)    ((uint8_t)(ipm + GICC_PMR_MASK))  /* ����ɽ��������ɽ���� */
#else /* TOPPERS_MACRO_ONLY */
#define EXT_IPM(iipm)    (iipm - GICC_PMR_MASK)           /* ����ɽ������ɽ���� */
#define INT_IPM(ipm)    (ipm + GICC_PMR_MASK)             /* ����ɽ��������ɽ���� */
#endif /* TOPPERS_MACRO_ONLY */

/*
 *  TIPM_ENAALL�ʳ����ͥ���٥ޥ���������ˤ�����ɽ��
 */
#define IIPM_ENAALL        (INT_IPM(TIPM_ENAALL))

#ifndef TOPPERS_MACRO_ONLY

/*
 *  IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ���ˤθ����ͤ��ɽФ�
 */
Inline uint8_t
current_iipm(void)
{
	return(gicc_current_priority());
}

/*
 *  IPM�ʥϡ��ɥ������γ����ͥ���٥ޥ���������ɽ���ˤθ����ͤ�����
 */
Inline void
set_iipm(uint8_t iipm)
{
	gicc_set_priority(iipm);
}

/*
 * (��ǥ���)�����ͥ���٥ޥ���������
 */
Inline void
x_set_ipm(PRI intpri)
{
	set_iipm(INT_IPM(intpri));
}

#define t_set_ipm(intpri) x_set_ipm(intpri)
#define i_set_ipm(intpri) x_set_ipm(intpri)

/*
 *  (��ǥ���)�����ͥ���٥ޥ����λ���
 */
Inline PRI
x_get_ipm(void)
{
	return(EXT_IPM(current_iipm()));
}

#define t_get_ipm() x_get_ipm()
#define i_get_ipm() x_get_ipm()

/*
 *  �����°���ơ��֥�
 * 
 *  �����°�������ꤵ��Ƥ����"1"�����ꤵ��Ƥ��ʤ����"0"�Ȥʤ�
 */
extern const uint8_t cfgint_tbl[TNUM_INT];

/*
 * �ʥ�ǥ��Ρ˳�����׵�ػߥե饰�Υ��å�
 *
 *  ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��åȤ��ơ�����ߤ�
 *  �ػߤ��롥
 *    
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���  
 */
Inline bool_t
x_disable_int(INTNO intno)
{
	if (cfgint_tbl[intno] == 0){
		return(false);
	}
    
	gicd_disable_int(intno);
	return(true);
}

#define t_disable_int(intno)  x_disable_int(intno)
#define i_disable_int(intno)  t_disable_int(intno)

/* 
 *  (��ǥ���)����׵�ػߥե饰�β��
 *
 *  ���ꤵ�줿��������ֹ�γ�����׵�ػߥե饰�Υ��ꥢ���ơ�����ߤ�
 *  ���Ĥ��롥
 *
 *  �����°�������ꤵ��Ƥ��ʤ�������׵�饤����Ф��Ƴ�����׵�ػ�
 *  �ե饰�򥯥ꥢ���褦�Ȥ������ˤϡ�false���֤���
 */
Inline bool_t
x_enable_int(INTNO intno)
{
	if (cfgint_tbl[intno] == 0){
		return(false);
	}
	gicd_enable_int(intno);
	return(true);
}

#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)

/*
 * ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
	gicd_clear_pending(intno);
}

#define t_clear_int(intno) x_clear_int(intno) 
#define i_clear_int(intno) x_clear_int(intno) 

/*
 *  ������׵�Υ����å�
 */
Inline bool_t
x_probe_int(INTNO intno)
{
	return(gicd_probe_int(intno));
}

#define t_probe_int(intno) x_probe_int(intno)
#define i_probe_int(intno) x_probe_int(intno)

/*
 *  ������׵�饤���°��������
 *
 */
extern void x_config_int(INTNO intno, ATR intatr, PRI intpri);

/*
 * ����ߥϥ�ɥ���������ɬ�פ�IRC���
 *
 */
Inline void
i_begin_int(INTNO intno)
{    
}

/*
 * ����ߥϥ�ɥ�νи���ɬ�פ�IRC���
 */
Inline void
i_end_int(INTNO intno)
{
}

/*
 *  ���åװ�¸�ν����
 */
extern void chip_initialize(void);

/*
 *  ���åװ�¸���ν�λ
 *
 *  �����ƥ��λ������˻Ȥ���
 */
extern void chip_exit(void);

/*
 *  ����ߥϥ�ɥ��chip_support.S��
 */
extern void interrupt_handler(void);

/*
 *  ̤����γ���ߤ����ä����ν���
 */
extern void default_int_handler(void);


#endif /* TOPPERS_MACRO_ONLY */

/*
 *  ARM��¸�⥸�塼��
 */
#include "arm_gcc/common/core_config.h"

#endif /* TOPPERS_CHIP_CONFIG_H */
