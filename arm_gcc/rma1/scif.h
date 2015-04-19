/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2007-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2001-2011 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: scif.h 2494 2013-03-25 14:14:50Z ertl-honda $
 */

/*
 *   SH SCIF�� �ʰ�SIO�ɥ饤��
 */

#ifndef TOPPERS_SCIF_H
#define TOPPERS_SCIF_H

#include <kernel.h>

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_RDY_SND    1U        /* ������ǽ������Хå� */
#define SIO_RDY_RCV    2U        /* �������Υ�����Хå� */

#ifdef USE_SCIFA0
#define SCIFA0_PORTID 1
#else /* !USE_SCIFA0 */
#define SCIFA0_PORTID 0
#endif /* USE_SCIFA0 */

#ifdef USE_SCIFA1
#define SCIFA1_PORTID (SCIFA0_PORTID + 1)
#else /* !USE_SCIFA1 */
#define SCIFA1_PORTID (SCIFA0_PORTID)
#endif /* USE_SCIFA1 */

#ifdef USE_SCIFA2
#define SCIFA2_PORTID (SCIFA1_PORTID + 1)
#else /* !USE_SCIFA1 */
#define SCIFA2_PORTID (SCIFA1_PORTID)
#endif /* USE_SCIFA1 */

#ifdef USE_SCIFA3
#define SCIFA3_PORTID (SCIFA2_PORTID + 1)
#else /* !USE_SCIFA3 */
#define SCIFA3_PORTID (SCIFA2_PORTID)
#endif /* USE_SCIFA3 */

#ifdef USE_SCIFA4
#define SCIFA4_PORTID (SCIFA3_PORTID + 1)
#else /* !USE_SCIFA4 */
#define SCIFA4_PORTID (SCIFA3_PORTID)
#endif /* USE_SCIFA4 */

#ifdef USE_SCIFA5
#define SCIFA5_PORTID (SCIFA4_PORTID + 1)
#else /* !USE_SCIFA5 */
#define SCIFA5_PORTID (SCIFA4_PORTID)
#endif /* USE_SCIFA5 */

#ifdef USE_SCIFA6
#define SCIFA6_PORTID (SCIFA5_PORTID + 1)
#else /* !USE_SCIFA6 */
#define SCIFA6_PORTID (SCIFA5_PORTID)
#endif /* USE_SCIFA6 */

#ifdef USE_SCIFA7
#define SCIFA7_PORTID (SCIFA6_PORTID + 1)
#else /* !USE_SCIFA7 */
#define SCIFA7_PORTID (SCIFA6_PORTID)
#endif /* USE_SCIFA7 */

#ifdef USE_SCIFB
#define SCIFB_PORTID (SCIFA7_PORTID + 1)
#else /* !USE_SCIFA7 */
#define SCIFB_PORTID (SCIFA7_PORTID)
#endif /* USE_SCIFB */

/*
 *  ���Ѥ���SCIF�Υݡ��ȿ�(1��4)
 */
#define TNUM_SIOP   SCIFB_PORTID

#if TNUM_SIOP > 4
#error Serial driver support up to 4 port
#endif /* TNUM_SIOP > 4 */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
typedef struct sio_port_control_block	SIOPCB;

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
extern void scif_initialize(void);

/*
 * �����ͥ뵯ư���ΥС��ʽ����Ѥν����
 */
extern void scif_init(ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��ȤؤΥݡ���󥰤Ǥν���
 */
extern void scif_pol_putc(char c, ID siopid);

/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
extern bool_t scif_openflag_id(ID siopid);			/*  �ݡ���ID  */
extern bool_t scif_openflag_cb(SIOPCB *p_siopcb);	/*  �����֥�å�����Ƭ����  */

/* 
 *  �ݡ���ID�μ��� 
 */ 
extern ID scif_get_siopid(SIOPCB *p_siopcb);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *scif_opn_por(ID siopid, intptr_t exinf);

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void scif_cls_por(SIOPCB *p_siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern bool_t scif_snd_chr(SIOPCB *p_siopcb, char c);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern int_t scif_rcv_chr(SIOPCB *p_siopcb);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void  scif_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void scif_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn);

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
extern void scif_tx_isr(ID siopid);
extern void scif_rx_isr(ID siopid);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void scif_irdy_snd(intptr_t exinf);

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void scif_irdy_rcv(intptr_t exinf);


/*
 *  �ݡ����ֹ椫������֥�å�����Ƭ���Ϥؤ��Ѵ�
 */
extern SIOPCB *scif_get_siopcb(ID siopid);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_SCIF_H */
