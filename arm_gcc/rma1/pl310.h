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
 *  @(#) $Id: pl310.h 2496 2013-03-31 13:19:15Z ertl-honda $
 */

/*
 * R-Mobile-A1��L2�L���b�V���R���g���[��PL310������`
 */
#ifndef PL310_H
#define PL310_H

#include <sil.h>

#define RMA1_L2CACHE_BASE	0xF0100000

#define PL310_CACHE_ID			0x000
#define PL310_CACHE_ID_PART_MASK	(0xf << 6)
#define PL310_CACHE_ID_PART_L210	(1 << 6)
#define PL310_CACHE_ID_PART_L310	(3 << 6)
#define PL310_CACHE_TYPE			0x004
#define PL310_CTRL			0x100
#define PL310_AUX_CTRL			0x104
#define PL310_TAG_LATENCY_CTRL		0x108
#define PL310_DATA_LATENCY_CTRL		0x10C
#define PL310_EVENT_CNT_CTRL		0x200
#define PL310_EVENT_CNT1_CFG		0x204
#define PL310_EVENT_CNT0_CFG		0x208
#define PL310_EVENT_CNT1_VAL		0x20C
#define PL310_EVENT_CNT0_VAL		0x210
#define PL310_INTR_MASK			0x214
#define PL310_MASKED_INTR_STAT		0x218
#define PL310_RAW_INTR_STAT		0x21C
#define PL310_INTR_CLEAR			0x220
#define PL310_CACHE_SYNC			0x730
#define PL310_INV_LINE_PA		0x770
#define PL310_INV_WAY			0x77C
#define PL310_CLEAN_LINE_PA		0x7B0
#define PL310_CLEAN_LINE_IDX		0x7B8
#define PL310_CLEAN_WAY			0x7BC
#define PL310_CLEAN_INV_LINE_PA		0x7F0
#define PL310_CLEAN_INV_LINE_IDX		0x7F8
#define PL310_CLEAN_INV_WAY		0x7FC
#define PL310_LOCKDOWN_WAY_D		0x900
#define PL310_LOCKDOWN_WAY_I		0x904
#define PL310_TEST_OPERATION		0xF00
#define PL310_LINE_DATA			0xF10
#define PL310_LINE_TAG			0xF30
#define PL310_DEBUG_CTRL			0xF40
#define PL310_PREFETCH_CTRL		0xF60
#define PL310_POWER_CTRL			0xF80

#ifndef TOPPERS_MACRO_ONLY
extern void pl310_init(uint32_t aux_val, uint32_t aux_mask);
extern void pl310_debug_set(uint32_t val);
#endif /* TOPPERS_MACRO_ONLY */

#endif /* PL310_H */
