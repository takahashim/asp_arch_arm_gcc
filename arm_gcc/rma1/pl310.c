/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2013 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: pl310.c 2496 2013-03-31 13:19:15Z ertl-honda $
 */

#include "pl310.h"

/* Bitmask of active ways */
static uint32_t pl310_way_mask;  

static inline void cache_wait_way(uint32_t *reg, unsigned long mask)
{
	/* wait for cache operation by line or way to complete */
	while ( sil_rew_mem((void*)(reg)) & mask );
}

static inline void cache_sync(void)
{
	sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_CACHE_SYNC), 0);
}

static inline void pl310_inv_all(void)
{
	/* invalidate all ways */
	sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_INV_WAY), pl310_way_mask);
	cache_wait_way((uint32_t *)(RMA1_L2CACHE_BASE+PL310_INV_WAY), pl310_way_mask);
	cache_sync();
}

void
pl310_init(uint32_t aux_val, uint32_t aux_mask)
{
	uint32_t tmp;
	uint32_t aux;
	uint32_t cache_id;
	uint32_t prefetch;
	uint32_t prefetch_val = 0;    
	uint32_t power;
	int ways;

	/* L2�L���b�V�������łɃI���ɂȂ��Ă��邩�m�F���� */
	tmp = sil_rew_mem((void*)(RMA1_L2CACHE_BASE + PL310_CTRL));

	/* L2�L���b�V���������̏ꍇ�̂ݏ����������{���� */
	if ( !(tmp & 1) ) {
		cache_id = sil_rew_mem((void*)(RMA1_L2CACHE_BASE + PL310_CACHE_ID));
		aux = sil_rew_mem((void*)(RMA1_L2CACHE_BASE + PL310_AUX_CTRL));
		prefetch = sil_rew_mem((void*)(RMA1_L2CACHE_BASE + PL310_PREFETCH_CTRL));
		power = sil_rew_mem((void*)(RMA1_L2CACHE_BASE + PL310_POWER_CTRL));

		if (aux & (1 << 16)) {
			ways = 16;
		}
		else {
			ways = 8;
		}

		aux_val |= 1 << 22;
        
		aux_val |= 1 << 29;
		prefetch_val |= 1 << 29;

		aux_val |= 1 << 28;
		prefetch_val |= 1 << 28;


		if ((cache_id & 0x3f) > 0x6) {
			prefetch_val |= 1 << 30;
		}
                
		pl310_way_mask = (1 << ways) - 1;

		aux &= aux_mask;
		aux |= aux_val;
		prefetch |= prefetch_val;

		sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_AUX_CTRL), aux);
		sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_PREFETCH_CTRL), prefetch);
		sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_POWER_CTRL), power);
        
		pl310_inv_all();
        
		sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_CTRL), 1);
	}    
}

void
pl310_debug_set(uint32_t val)
{
	sil_wrw_mem((void*)(RMA1_L2CACHE_BASE + PL310_DEBUG_CTRL), val);
}
