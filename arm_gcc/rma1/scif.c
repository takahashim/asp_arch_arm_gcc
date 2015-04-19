/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: scif.c 2494 2013-03-25 14:14:50Z ertl-honda $
 */

/*
 *   SH SCIF�� �ʰ�SIO�ɥ饤��
 */

#include <sil.h>
#include "target_syssvc.h"
#include "scif.h"

/*
 * SH SCIF�Υ쥸��������
 */

/*
 * �ƥ쥸�����Υ��ե��å�
 */
#define SCIFA_SCSMR   0x0000U  /* H */
#define SCIFA_SCBRR   0x0004U  /* B */
#define SCIFA_SCSCR   0x0008U  /* H */
#define SCIFA_SCFSR   0x0014U  /* H */
#define SCIFA_SCFCR   0x0018U  /* H */
#define SCIFA_SCFDR   0x001cU  /* H */
#define SCIFA_SCFTDR  0x0020U  /* B */
#define SCIFA_SCFRDR  0x0024U  /* B */


#define SCIFB_SCSMR   0x0000U  /* H */
#define SCIFB_SCBRR   0x0004U  /* B */
#define SCIFB_SCSCR   0x0008U  /* H */
#define SCIFB_SCFSR   0x0014U  /* H */
#define SCIFB_SCFCR   0x0018U  /* H */
#define SCIFB_SCFDR   0x003cU  /* H */
#define SCIFB_SCFTDR  0x0040U  /* B */
#define SCIFB_SCFRDR  0x0060U  /* B */

/*
 * �ƥ쥸������������
 */
#define SCSMR_CHR    0x0040U
#define SCSMR_PE     0x0020U
#define SCSMR_OE     0x0010U
#define SCSMR_STOP   0x0008U
#define SCSMR_CKS1   0x0002U
#define SCSMR_CKS0   0x0001U

#define SCSCR_TIE    0x0080U
#define SCSCR_RIE    0x0040U
#define SCSCR_TE     0x0020U
#define SCSCR_RE     0x0010U
#define SCSCR_CKE1   0x0002U
#define SCSCR_CKE0   0x0001U

#define SCFSR_ER     0x0080U
#define SCFSR_TEND   0x0040U
#define SCFSR_TDFE   0x0020U
#define SCFSR_BRK    0x0010U
#define SCFSR_FER    0x0008U
#define SCFSR_PER    0x0004U
#define SCFSR_RDF    0x0002U
#define SCFSR_DR     0x0001U

#define SCFCR_RTRG1  0x0080U
#define SCFCR_RTRG0  0x0040U
#define SCFCR_TTRG1  0x0020U
#define SCFCR_TTRG0  0x0010U
#define SCFCR_MCE    0x0008U
#define SCFCR_TFRST  0x0004U
#define SCFCR_RFRST  0x0002U
#define SCFCR_LOOP   0x0001U

#define SIO_INIT_DLY    5000U /* 1�ӥå�ʬ���褯ʬ����ʤ��Τǻ����� */

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 */
typedef struct sio_port_initialization_block {
	uint16_t *scsmr_h;   /* ���ꥢ��⡼�ɥ쥸���� */
	uint8_t  *scbrr_b;   /* �ӥåȥ졼�ȥ쥸���� */
	uint16_t *scscr_h;   /* ���ꥢ�륳��ȥ���쥸���� */
	uint16_t *scfsr_h;   /* ���ꥢ�륹�ơ������쥸���� */
	uint16_t *scfcr_h;   /* FIFO����ȥ���쥸���� */
	uint16_t *scfdr_h;   /* �쥷����FIFO�ǡ������쥸���� */
	uint8_t  *scftdr_b;  /* �ȥ�󥹥ߥå�FIFO�ǡ����쥸���� */
	uint8_t  *scfrdr_b;  /* �쥷����FIFO�ǡ����쥸���� */
	uint32_t bps_setting; /* �ܡ��졼�Ȥ������� */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
struct sio_port_control_block {
	const SIOPINIB  *p_siopinib;  /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
	intptr_t  exinf;              /* ��ĥ���� */
	bool_t    openflag;           /* �����ץ�Ѥߥե饰 */
	bool_t    sendflag;           /* ��������ߥ��͡��֥�ե饰 */
	bool_t    getready;           /* ʸ��������������� */
	bool_t    putready;           /* ʸ���������Ǥ������ */
	bool_t    is_initialized;     /* �ǥХ���������Ѥߥե饰 */
};

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å�
 */
static const SIOPINIB siopinib_table[TNUM_SIOP] = {
#ifdef USE_SCIFA0
	{
		(uint16_t *)(SCIFA0_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA0_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA0_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA0_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA0_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA0_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA0_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA0_BASE + SCIFA_SCFRDR),
		SCIFA0_BPS_SETTING,
	},
#endif /*  USE_SCIFA0 */
#ifdef USE_SCIFA1
	{        
		(uint16_t *)(SCIFA1_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA1_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA1_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA1_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA1_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA1_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA1_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA1_BASE + SCIFA_SCFRDR),
		SCIFA1_BPS_SETTING,
	},
#endif /* USE_SCIFA1 */
#ifdef USE_SCIFA2
	{
		(uint16_t *)(SCIFA2_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA2_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA2_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA2_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA2_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA2_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA2_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA2_BASE + SCIFA_SCFRDR),
		SCIFA2_BPS_SETTING,
	},
#endif /* USE_SCIFA2 */
#ifdef USE_SCIFA3
	{
		(uint16_t *)(SCIFA3_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA3_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA3_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA3_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA3_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA3_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA3_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA3_BASE + SCIFA_SCFRDR),
		SCIFA3_BPS_SETTING,
	},
#endif /* USE_SCIFA3 */
#ifdef USE_SCIFA4
	{
		(uint16_t *)(SCIFA4_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA4_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA4_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA4_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA4_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA4_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA4_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA4_BASE + SCIFA_SCFRDR),
		SCIFA4_BPS_SETTING,
	},
#endif /* USE_SCIFA4 */
#ifdef USE_SCIFA5
	{
		(uint16_t *)(SCIFA5_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA5_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA5_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA5_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA5_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA5_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA5_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA5_BASE + SCIFA_SCFRDR),
		SCIFA5_BPS_SETTING,
	},
#endif /* USE_SCIFA5 */
#ifdef USE_SCIFA6
	{
		(uint16_t *)(SCIFA6_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA6_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA6_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA6_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA6_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA6_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA6_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA6_BASE + SCIFA_SCFRDR),
		SCIFA6_BPS_SETTING,
	},
#endif /* USE_SCIFA6 */
#ifdef USE_SCIFA7
	{
		(uint16_t *)(SCIFA7_BASE + SCIFA_SCSMR),
		(uint8_t  *)(SCIFA7_BASE + SCIFA_SCBRR),
		(uint16_t *)(SCIFA7_BASE + SCIFA_SCSCR),
		(uint16_t *)(SCIFA7_BASE + SCIFA_SCFSR),
		(uint16_t *)(SCIFA7_BASE + SCIFA_SCFCR),
		(uint16_t *)(SCIFA7_BASE + SCIFA_SCFDR),
		(uint8_t  *)(SCIFA7_BASE + SCIFA_SCFTDR),
		(uint8_t  *)(SCIFA7_BASE + SCIFA_SCFRDR),
		SCIFA7_BPS_SETTING,
	},
#endif /* USE_SCIFA7 */
#ifdef USE_SCIFB
	{
		(uint16_t *)(SCIFB_BASE + SCIFB_SCSMR),
		(uint8_t  *)(SCIFB_BASE + SCIFB_SCBRR),
		(uint16_t *)(SCIFB_BASE + SCIFB_SCSCR),
		(uint16_t *)(SCIFB_BASE + SCIFB_SCFSR),
		(uint16_t *)(SCIFB_BASE + SCIFB_SCFCR),
		(uint16_t *)(SCIFB_BASE + SCIFB_SCFDR),
		(uint8_t  *)(SCIFB_BASE + SCIFB_SCFTDR),
		(uint8_t  *)(SCIFB_BASE + SCIFB_SCFRDR),
		SCIFB_BPS_SETTING,
	},
#endif /* USE_SCIFB */
};


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	 ((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	 (&(siopcb_table[INDEX_SIOP(siopid)]))
#define get_siopinib(siopid) (&(siopinib_table[INDEX_SIOP(siopid)]))

/* 
 *  �����֥�å��ؤΥݥ��󥿤��饷�ꥢ��I/O�ݡ���ID����Ф�����Υޥ��� 
 */ 
#define SIOPID(p_siopcb)    ((ID)((p_siopcb) - siopcb_table))

/*
 *  ʸ���������������
 */
Inline bool_t
scif_getready(SIOPCB *p_siopcb)
{
    return((sil_reh_mem(p_siopcb->p_siopinib->scfsr_h) & SCFSR_RDF) != 0);
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline bool_t
scif_putready(SIOPCB *p_siopcb)
{
    return((sil_reh_mem(p_siopcb->p_siopinib->scfsr_h) & SCFSR_TDFE) != 0);
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
scif_getchar(SIOPCB *p_siopcb)
{
    uint8_t c;
    c = sil_reb_mem(p_siopcb->p_siopinib->scfrdr_b);
    sil_wrh_mem(p_siopcb->p_siopinib->scfsr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scfsr_h) & ~SCFSR_RDF));
    return(c);
}

/*
 *  ��������ʸ���ν����
 */
Inline void
scif_putchar(SIOPCB *p_siopcb, char c)
{
    sil_wrb_mem(p_siopcb->p_siopinib->scftdr_b, (uint8_t)c);
    sil_wrh_mem(p_siopcb->p_siopinib->scfsr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scfsr_h) & ~(SCFSR_TDFE)));
}

/*
 *  ��������ߵ���
 */
Inline void
scif_enable_send(SIOPCB *p_siopcb)
{
    sil_wrh_mem(p_siopcb->p_siopinib->scscr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scscr_h) | SCSCR_TIE));
}

/*
 *  ��������߶ػ�
 */
Inline void
scif_disable_send(SIOPCB *p_siopcb)
{
    sil_wrh_mem(p_siopcb->p_siopinib->scscr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scscr_h) & ~SCSCR_TIE));
}


/*
 *  ��������ߵ���
 */
Inline void
scif_enable_rcv(SIOPCB *p_siopcb)
{
    sil_wrh_mem(p_siopcb->p_siopinib->scscr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scscr_h) | SCSCR_RIE));    
}

/*
 *  ��������߶ػ�
 */
Inline void
scif_disable_rcv(SIOPCB *p_siopcb)
{
    sil_wrh_mem(p_siopcb->p_siopinib->scscr_h,
                (sil_reh_mem(p_siopcb->p_siopinib->scscr_h) & ~SCSCR_RIE));
}

/*
 *  SIO�ɥ饤�Фν����
 */
void
scif_initialize(void)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->openflag = false;
		p_siopcb->sendflag = false;
	}
}


/*
 * �ϡ��ɥ������ν��������
 */
static void
scif_init_siopinib(const SIOPINIB *p_siopinib)
{
    /* UART��� */
	sil_wrh_mem(p_siopinib->scscr_h, 0x00U);    

    /* ��������FIFO�򥯥ꥢ */   
	sil_wrh_mem(p_siopinib->scfcr_h, (SCFCR_TFRST|SCFCR_RFRST));

	/*  8�ǡ���,1���ȥåץӥå�,no parity */
	sil_wrh_mem(p_siopinib->scsmr_h, 0x0000U);

	/*  ^RTS2 �˽��� */
	//sil_wrh_mem(p_siopinib->scsptr_h, SCSPTR_RTSIO);

#ifndef USE_SCIF_CLK_EXT
	/* �ܡ��졼�Ȥ����� */
	//sil_wrb_mem(p_siopinib->scbrr_b, p_siopinib->bps_setting);
	//sil_wrb_mem(p_siopinib->scbrr_b, 0x1a);	
	sil_wrb_mem(p_siopinib->scbrr_b, (uint16_t)((50 * 1000000 / (16 * 1 * (p_siopinib->bps_setting))) - 1));
	/* 1�ӥå�ʬ�Ԥ�ɬ�פ����� */
	sil_dly_nse(SIO_INIT_DLY);
#else /* USE_SCIF_CLK_EXT */
	sil_wrh_mem(p_siopinib->cks_h, CKS_EXTERNAL);
	sil_wrh_mem(p_siopinib->dl_h, SCIF_CLK / p_siopinib->bps_setting / 16);
	sil_dly_nse((1000000 * 2 * 16 / SCIF_CLK) * 1000 + 1);
#endif /* USE_SCIF_CLK_EXT */

	/* �����Хåե��Υ��ꥢ */
	while((sil_reh_mem(p_siopinib->scfsr_h) & SCFSR_RDF) == SCFSR_RDF) {
		sil_reb_mem(p_siopinib->scfrdr_b);
		sil_wrh_mem(p_siopinib->scfsr_h,
					(sil_reh_mem(p_siopinib->scfsr_h) & ~SCFSR_RDF));
	}

	/* ���ơ������Υ��ꥢ */
	sil_wrh_mem(p_siopinib->scfsr_h,
				sil_reh_mem(p_siopinib->scfsr_h) & ~(SCFSR_TEND|SCFSR_TDFE));
    
	/* �ȥꥬ������ R-FIFO=1,T-FIFO=1 */
	sil_wrh_mem(p_siopinib->scfcr_h, (SCFCR_TTRG1|SCFCR_TTRG0));

	/* UART���� */
#ifndef USE_SCIF_CLK_EXT
	sil_wrh_mem(p_siopinib->scscr_h, (SCSCR_TE|SCSCR_RE));
#else /* USE_SCIF_CLK_EXT */
	sil_wrh_mem(p_siopinib->scscr_h, (SCSCR_TE|SCSCR_RE|SCSCR_CKE1));
#endif /* USE_SCIF_CLK_EXT */
}


/*
 * �����ͥ뵯ư���ΥС��ʽ����Ѥν����
 */
void
scif_init(ID siopid)
{
	SIOPCB          *p_siopcb   = get_siopcb(siopid);
	const SIOPINIB  *p_siopinib = get_siopinib(siopid);
	/*  ���λ����Ǥϡ�p_siopcb->p_siopinib�Ͻ��������Ƥ��ʤ�  */
    
	/*  ��Ž�������ɻ�  */
	p_siopcb->is_initialized = true;

	/*  �ϡ��ɥ������ν��������  */
	scif_init_siopinib(p_siopinib);
}

/*
 *  �ݡ���n�������ץ�Ѥߤ����ʥݡ���ID��������
 */
bool_t
scif_openflag_id(ID siopid)
{
	return(get_siopcb(siopid)->openflag);
}

/*
 *  �ݡ���n�������ץ�Ѥߤ���
 *  �ʡ֥��ꥢ��I/O�ݡ��ȴ����֥�å��פ���Ƭ���Ϥ�������
 */
bool_t
scif_openflag_cb(SIOPCB *p_siopcb)
{
	return(p_siopcb->openflag);
}

/* 
 *  �ݡ���ID�μ��� 
 */ 
ID 
scif_get_siopid(SIOPCB *p_siopcb) 
{ 
	return(SIOPID(p_siopcb)); 
} 

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
scif_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB          *p_siopcb;
	const SIOPINIB  *p_siopinib;
      
	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;

	/*
	 * �ϡ��ɥ������ν����     
	 * �����˽�������Ƥ�����ϡ���Ť˽�������ʤ���
	 */
	if (!(p_siopcb->is_initialized)) {
		scif_init_siopinib(p_siopinib);
		p_siopcb->is_initialized = true;
	}

	p_siopcb->exinf = exinf;
	p_siopcb->getready = p_siopcb->putready = false;
	p_siopcb->openflag = true;

	return(p_siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
scif_cls_por(SIOPCB *p_siopcb)
{
	/*
	 * UART���
	 */
	sil_wrh_mem(p_siopcb->p_siopinib->scscr_h, 0x00);
	p_siopcb->openflag = false;
	p_siopcb->is_initialized = false;
}


/*
 *  ���ꥢ��I/O�ݡ��ȤؤΥݡ���󥰤Ǥν���
 */
void
scif_pol_putc(char c, ID siopid)
{
	const SIOPINIB *p_siopinib;
	uint32_t scfsr;
	void *p_scfsr;
	SIL_PRE_LOC;
    
	p_siopinib = get_siopinib(siopid);
	p_scfsr = p_siopinib->scfsr_h;
    
	while(1) {
		/*
		 *  �ꥨ��ȥ��Ȥˤ��뤿�ᡢ������ߥ�å����֤ˤ��롣
		 */
		SIL_LOC_INT();
		scfsr = sil_reh_mem(p_scfsr);
		
		if ((scfsr & SCFSR_TDFE) == 0) {
			/*
			 *  ������������ߥ�å��������ơ�����ߤ�����դ��롣
			 */
			SIL_UNL_INT();
		} else {
			sil_wrb_mem(p_siopinib->scftdr_b, (uint8_t)c);
			scfsr = sil_reh_mem(p_scfsr);
			sil_wrh_mem(p_scfsr, scfsr & ~SCFSR_TDFE);
			/*
			 *  �꥿���󤹤�����������ߥ�å��ե饰�򸵤ξ��֤��᤹��
			 */
			SIL_UNL_INT();
			return;
		}
	}
}


/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
scif_snd_chr(SIOPCB *p_siopcb, char c)
{
	if (scif_putready(p_siopcb)){
		scif_putchar(p_siopcb, c);
		return(true);
	}
	return(false);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
scif_rcv_chr(SIOPCB *p_siopcb)
{
	if (scif_getready(p_siopcb)) {
		return((int_t)scif_getchar(p_siopcb));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
scif_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	  case SIO_RDY_SND:
		scif_enable_send(p_siopcb);
		break;
	  case SIO_RDY_RCV:
		scif_enable_rcv(p_siopcb);
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
scif_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	  case SIO_RDY_SND:
		scif_disable_send(p_siopcb);
		break;
	  case SIO_RDY_RCV:
		scif_disable_rcv(p_siopcb);
		break;
	}
}

/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
void
scif_tx_isr(ID siopid)
{
	SIOPCB	*p_siopcb = get_siopcb(siopid);

	if (scif_putready(p_siopcb)) {
		/*
		 *  ������ǽ������Хå��롼�����ƤӽФ���
		 */
		scif_irdy_snd(p_siopcb->exinf);
	}
}


/*
 *  SIO�γ���ߥ����ӥ��롼����
 */
void
scif_rx_isr(ID siopid)
{
	SIOPCB	*p_siopcb = get_siopcb(siopid);
    
	if (scif_getready(p_siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		scif_irdy_rcv(p_siopcb->exinf);
	}
}
