/*
 * arch/arm/mach-tegra/board-acer-t30.h
 *
 * Copyright (c) 2011, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _MACH_TEGRA_BOARD_ACER_T30_H
#define _MACH_TEGRA_BOARD_ACER_T30_H

#include <mach/gpio.h>
#include <mach/irqs.h>
#include <linux/mfd/tps6591x.h>

#define SKU_DCDC_TPS62361_SUPPORT	0x1

/* External peripheral act as gpio */
/* TPS6591x GPIOs */
#define TPS6591X_GPIO_BASE	TEGRA_NR_GPIOS
#define TPS6591X_GPIO_0		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP0)
#define TPS6591X_GPIO_1		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP1)
#define TPS6591X_GPIO_2		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP2)
#define TPS6591X_GPIO_3		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP3)
#define TPS6591X_GPIO_4		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP4)
#define TPS6591X_GPIO_5		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP5)
#define TPS6591X_GPIO_6		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP6)
#define TPS6591X_GPIO_7		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP7)
#define TPS6591X_GPIO_8		(TPS6591X_GPIO_BASE + TPS6591X_GPIO_GP8)
#define TPS6591X_GPIO_END	(TPS6591X_GPIO_BASE + TPS6591X_GPIO_NR)

/* WM8903 GPIOs */
#define CARDHU_GPIO_WM8903(_x_)		(TPS6591X_GPIO_END + (_x_))
#define CARDHU_GPIO_WM8903_END		CARDHU_GPIO_WM8903(4)

/* Audio-related GPIOs */
#define TEGRA_GPIO_CDC_IRQ		TEGRA_GPIO_PW3
#define TEGRA_GPIO_SPKR_EN		CARDHU_GPIO_WM8903(2)
#define TEGRA_GPIO_HP_DET		TEGRA_GPIO_PW2
#define TEGRA_GPIO_BYPASS_SWITCH_EN	TEGRA_GPIO_PN3
#define TEGRA_GPIO_DEBUG_SWITCH_EN	TEGRA_GPIO_PR5

/* Sensor GPIOs*/
#define SENSOR_3V3			TEGRA_GPIO_PH7
#define SENSOR_3V3_2			TEGRA_GPIO_PP3
#define EN_SENSOR_VLOGIC		TEGRA_GPIO_PY3
#define GYRO_INT_R			TEGRA_GPIO_PX1
#define G_ACC_INT			TEGRA_GPIO_PS5
#define COMPASS_DRDY			TEGRA_GPIO_PX7

#define AC_PRESENT_GPIO		TPS6591X_GPIO_4

/*****************Interrupt tables ******************/
/* External peripheral act as interrupt controller */
/* TPS6591x IRQs */
#define TPS6591X_IRQ_BASE	TEGRA_NR_IRQS
#define TPS6591X_IRQ_END	(TPS6591X_IRQ_BASE + 18)

int cardhu_charge_init(void);
int cardhu_regulator_init(void);
int cardhu_suspend_init(void);
int cardhu_sdhci_init(void);
int cardhu_pinmux_init(void);
int acer_panel_init(void);
int cardhu_sensors_init(void);
int cardhu_kbc_init(void);
int cardhu_scroll_init(void);
int cardhu_keys_init(void);
int cardhu_emc_init(void);
int cardhu_edp_init(void);
int acer_keys_init(void);
int cardhu_pmon_init(void);
int cardhu_pm298_gpio_switch_regulator_init(void);
int cardhu_pm298_regulator_init(void);
int cardhu_pm299_gpio_switch_regulator_init(void);
int cardhu_pm299_regulator_init(void);

#define TDIODE_OFFSET	(10000)	/* in millicelsius */

/* Board Type */
#define BOARD_PICASSO_M  1
#define BOARD_PICASSO_MF 2

/* Board ID */
#define BOARD_EVT       0
#define BOARD_DVT1      1
#define BOARD_DVT2      2
#define BOARD_PVT1      3
#define BOARD_PVT2      4
#define BOARD_PRE_MP    5

/* SKU type */
#define BOARD_SKU_WIFI  0
#define BOARD_SKU_3G    1
#define BOARD_SKU_LTE   2

/* Wifi module */
#define BOARD_WIFI_AH663 0
#define BOARD_WIFI_NH660 1
#endif
