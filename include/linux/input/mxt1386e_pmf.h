#ifndef _LINUX_MXT1386E_PMF_H
#define _LINUX_MXT1386E_PMF_H

#define X_MAX                                 1919
#define Y_MAX                                 1199

#define ConfigChecksum                        16159579 /* F6935B */
#define ConfigVersion                         1181442  /* 120702 */

/* GEN_ACQUISITIONCONFIG_T8 INSTANCE 0 */
u8 T08OBJ[10] = {  26,   0,  10,  10,   0,   0,   5,  17,  15,   0};

/* TOUCH_MULTITOUCHSCREEN_T9 INSTATNCE 0 */
u8 T09OBJ[35] = { 131,   0,   0,  30,  42,   0,  16,  70,   2,   5,
                   10,   5,   8,   0,  10,  15,  15,  10, 175,   4,
                  127,   7,   0,   0,   0,   0,   0,   0,  64,   0,
                   15,  25,   0,   0,   0};

/* SPT_SELFTEST_T25 INSTATNCE 0 */
u8 T25OBJ[6]  = {   0,   0,   0,   0,   0,   0};

/* SPT_PROTOTYPE_T35 INSTANCE 0 */
u8 T35OBJ[12] = {   1, 170,   0,   0, 255,   0, 255,   0, 255,   0,
                  255, 150};

/* SPT_USERDATA_T38 INSTATNCE 0 */
u8 T38OBJ[64] = {   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0};

/* PROCI_TOUCHSUPPRESSION_T42 INSTATNCE 0 */
u8 T42OBJ[10] = {  33,  40,  80,  80,   0,   3,   0,   0,  10,   3};

/* SPT_DIGITIZER_T43 INSTANCE 0 */
u8 T43OBJ[11] = {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0};

/* SPT_CTECONFIG_T46 INSTANCE 0 */
u8 T46OBJ_0[9]= {  64,   0,  16,  32,   0,   0,   1,   0,   0};

/* PROCG_NOISESUPPRESSION_T48 INSTATNCE 0 */
u8 T48OBJ[54] = {   1, 128,   2,   0,   0,   0,   0,   0,   0,   0,
                   16,  55,   0,  10,   0,   0,   0,  63,   0,   0,
                   10,   0,  20,   0,   0,   0,   0,  16,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0};

/* PROCI_SHIELDLESS_T56 INSTATNCE 0  */
u8 T56OBJ[51] = {   1,   0,   1,  48,  21,  21,  21,  21,  21,  21,
                   21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
                   21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
                   21,  21,  21,  21,   0,   0,   0,   0,   0,   0,
                    1,   6,   6,   0,   0,   0,   0,   0,   0,   0,
                    0};

/* PROCI_LENSBENDING_T65 INSTATNCE 0 */
u8 T65OBJ[17] = {   0,  75,   0,   0,   0,   0,   0,   0,   0,   0,
                   55,   0,   0,   0,   0,   0,   0};

#endif /* _LINUX_MXT1386E_PMF_H */
