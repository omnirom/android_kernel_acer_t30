#ifndef _LINUX_MXT1386E_P_H
#define _LINUX_MXT1386E_P_H

#include "../../../arch/arm/mach-tegra/board-acer-t30.h"

#define X_MIN                                 0x00
#define Y_MIN                                 0x00
#define MXT_MAX_REPORTED_PRESSURE             255
#define MXT_MAX_TOUCH_SIZE                    255

#define Chip_Vendor                           "AT"
#define Reseved_Chip_Vendor                   "0"
#define Reseved_Firmware_Info                 0
#define Reseved_ConfigVersion                 0
#define Reservedinfo                          0

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

// Stock: high = 65, medium = 70, low = 75
#define TOUCH_SENSITIVITY_MIN 45
#define TOUCH_SENSITIVITY_MAX 75
#define TOUCH_SENSITIVITY_DEFAULT 70

/* GEN_POWERCONFIG_T7 INSTANCE 0 */
u8 T07OBJ[3]  = {  15, 255,  10};

/* SPT_COMMSCONFIG_T18 INSTANCE 0 */
u8 T18OBJ[2]  = {   0,   0};

/* PROCI_ONETOUCHGESTUREPROCESSOR_T24 INSTATNCE 0 */
u8 T24OBJ[19] = {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0};

/* PROCI_TWOTOUCHGESTUREPROCESSOR_T27 INSTATNCE 0 */
u8 T27OBJ[7]  = {   0,   0,   0,   0,   0,   0,   0};

/* PROCI_GRIPSUPPRESSION_T40 INSTATNCE 0 */
u8 T40OBJ[5]  = {   0,   0,   0,   0,   0};

/* SPT_CTECONFIG_T46 INSTANCE 0 */
u8 T46OBJ[9]  = {  64,   0,  16,  32,   0,   0,   1,   0,   0};

/* PROCI_STYLUS_T47 INSTATNCE 0 */
u8 T47OBJ[10] = {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

#endif /* _LINUX_MXT1386E_P_H */
