/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2011 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id:
 */

#ifndef TOPPERS_RMA1_H
#define TOPPERS_RMA1_H

/*
 *  �T�|�[�g����@�\�̒�`
 */
#define TOPPERS_TARGET_SUPPORT_ENA_INT		/* ena_int���T�|�[�g���� */
#define TOPPERS_TARGET_SUPPORT_DIS_INT		/* dis_int���T�|�[�g���� */
#define TOPPERS_TARGET_SUPPORT_GET_UTM		/* get_utm���T�|�[�g���� */

/*
 *  SCIF�̃x�[�X�A�h���X
 */
#define SCIFA0_BASE  0xE6C40000
#define SCIFA1_BASE  0xE6C50000
#define SCIFA2_BASE  0xE6C60000
#define SCIFA3_BASE  0xE6C70000
#define SCIFA4_BASE  0xE6C80000
#define SCIFA5_BASE  0xE6CB0000
#define SCIFA6_BASE  0xE6CC0000
#define SCIFA7_BASE  0xE6CD0000
#define SCIFB_BASE   0xE6C30000

/*
 *  SCIF�̊����ݔԍ�
 */
#define SCIFA0_INTNO 132
#define SCIFA1_INTNO 133
#define SCIFA2_INTNO 134
#define SCIFA3_INTNO 135
#define SCIFA4_INTNO 136
#define SCIFA5_INTNO 137
#define SCIFA6_INTNO 138
#define SCIFA7_INTNO 139
#define SCIFB_INTNO  140

/*
 *  GIC�Ɋւ���ݒ�
 */
#define GICC_BASE     0xC2000000 //CPU�C���^�t�F�[�X�x�[�X�A�h���X
#define GICD_BASE     0xC2800000 //DIST�C���^�t�F�[�X�x�[�X�A�h���X

#define GIC_PRI_LEVEL         16 //�D��x�̌�,256,128,64,32,16
#define GIC_TNUM_INT         352 //�����ݐ�

/*
 *  �����ݗD��x�Ɋւ���ݒ�
 */
#define TMIN_INTPRI   (-(GIC_PRI_LEVEL - 1))   /* �����ݗD��x�̍ŏ��l�i�ō��l�j*/
#define TMAX_INTPRI   (-1)    /* �����ݗD��x�̍ő�l�i�Œ�l�j*/

/*
 *  reset/wdt
 */
#define MODEMR           0xFFCC0020
#define MODEMR_MD11      (1 << 11)
#define MODEMR_MD12      (1 << 12)

/*
 *  �^�C���e�B�b�N�̒�`
 */
#define TIC_NUME     1U            /* �^�C���e�B�b�N�̎����̕��q */
#define TIC_DENO     1U            /* �^�C���e�B�b�N�̎����̕��� */

#endif /* TOPPERS_RMA1_H */
