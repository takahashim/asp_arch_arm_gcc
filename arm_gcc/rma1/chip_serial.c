/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: chip_serial.c 2494 2013-03-25 14:14:50Z ertl-honda $
 */

/*
 *  ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�RMA1�ѡ�
 */

#include <kernel.h>
#include <t_syslog.h>
#include "chip_serial.h"

static INTNO const intno_sio[TNUM_SIOP] = {
#ifdef USE_SCIFA0
	SCIFA0_INTNO,
#endif /* USE_SCIFA0 */
#ifdef USE_SCIFA1
	SCIFA1_INTNO,
#endif /* USE_SCIFA1 */
#ifdef USE_SCIFA2
	SCIFA2_INTNO,
#endif /* USE_SCIFA2 */
#ifdef USE_SCIFA3
	SCIFA3_INTNO,
#endif /* USE_SCIFA3 */
#ifdef USE_SCIFA4
	SCIFA4_INTNO,
#endif /* USE_SCIFA4 */
#ifdef USE_SCIFA5
	SCIFA5_INTNO,
#endif /* USE_SCIFA5 */
#ifdef USE_SCIFA6
	SCIFA6_INTNO,
#endif /* USE_SCIFA6 */
#ifdef USE_SCIFA7
	SCIFA7_INTNO,
#endif /* USE_SCIFA7 */
#ifdef USE_SCIFB
	SCIFB_INTNO,
#endif /* USE_SCIFB */
}; 

/* 
 *  ���ꥢ��I/O�ݡ���ID���������ֹ����Ф�����Υޥ��� 
 */ 
#define INDEX_SIOP(siopid)           ((uint_t)((siopid) - 1)) 
#define get_intno_sio(siopid)        (intno_sio[INDEX_SIOP(siopid)]) 

/*
 *  SIO�ɥ饤�Фν����
 */
void
sio_initialize(intptr_t exinf)
{
	scif_initialize();    
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB    *p_siopcb;
	ER        ercd;

	/*
	 *  ���ꥢ��I/O����ߤ�ޥ������롥
	 */
	ercd = dis_int(get_intno_sio(siopid));
	assert(ercd == E_OK);

	/*
	 *  �ǥХ�����¸�Υ����ץ������
	 */
	p_siopcb = scif_opn_por(siopid, exinf);

	/*
	 *  ���ꥢ��I/O����ߤΥޥ����������롥
	 */
	ercd = ena_int(get_intno_sio(siopid));
	assert(ercd == E_OK);

	return(p_siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	ER ercd;
	ID siopid; 

	/* 
	 *  ���ꥢ��I/O�ݡ���ID�μ��� 
	 */ 
	siopid = scif_get_siopid(p_siopcb);

	/*
	 *  �ǥХ�����¸�Υ�����������
	 */
	scif_cls_por(p_siopcb);

	/*
	 *  ���ꥢ��I/O����ߤ�ޥ������롥
	 */
	ercd = dis_int(intno_sio[siopid]);
	assert(ercd == E_OK);
}

/*
 *  SIO�γ���ߥϥ�ɥ�
 */
void
sio_isr(intptr_t exinf)
{
	scif_tx_isr(exinf);
	scif_rx_isr(exinf);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char c)
{
	return(scif_snd_chr(siopcb, c));
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
sio_rcv_chr(SIOPCB *siopcb)
{
	return(scif_rcv_chr(siopcb));
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	scif_ena_cbr(siopcb, cbrtn);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
	scif_dis_cbr(siopcb, cbrtn);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
void
scif_irdy_snd(intptr_t exinf)
{
	sio_irdy_snd(exinf);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
void
scif_irdy_rcv(intptr_t exinf)
{
	sio_irdy_rcv(exinf);
}
