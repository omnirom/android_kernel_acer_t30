/*
 * Regulator driver for tps65090 power management chip.
 *
 * Copyright (c) 2012, NVIDIA CORPORATION.  All rights reserved.

 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.

 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/mfd/tps65090.h>
#include <linux/regulator/tps65090-regulator.h>

struct tps65090_regulator_info {
	int		id;
	/* Regulator register address.*/
	u8		reg_en_reg;
	u8		en_bit;

	/* used by regulator core */
	struct regulator_desc	desc;
};

struct tps65090_regulator {
	struct tps65090_regulator_info	*rinfo;
	struct device			*dev;
	struct regulator_dev		*rdev;
};

static inline struct device *to_tps65090_dev(struct regulator_dev *rdev)
{
	return rdev_get_dev(rdev)->parent->parent;
}

static int tps65090_reg_is_enabled(struct regulator_dev *rdev)
{
	struct tps65090_regulator *ri = rdev_get_drvdata(rdev);
	struct device *parent = to_tps65090_dev(rdev);
	uint8_t control;
	int ret;

	ret = tps65090_read(parent, ri->rinfo->reg_en_reg, &control);
	if (ret < 0) {
		dev_err(&rdev->dev, "Error in reading reg 0x%x\n",
			ri->rinfo->reg_en_reg);
		return ret;
	}
	return (((control >> ri->rinfo->en_bit) & 1) == 1);
}

static int tps65090_reg_enable(struct regulator_dev *rdev)
{
	struct tps65090_regulator *ri = rdev_get_drvdata(rdev);
	struct device *parent = to_tps65090_dev(rdev);
	int ret;

	ret = tps65090_set_bits(parent, ri->rinfo->reg_en_reg,
				ri->rinfo->en_bit);
	if (ret < 0)
		dev_err(&rdev->dev, "Error in updating reg 0x%x\n",
			ri->rinfo->reg_en_reg);
	return ret;
}

static int tps65090_reg_disable(struct regulator_dev *rdev)
{
	struct tps65090_regulator *ri = rdev_get_drvdata(rdev);
	struct device *parent = to_tps65090_dev(rdev);
	int ret;

	ret = tps65090_clr_bits(parent, ri->rinfo->reg_en_reg,
				ri->rinfo->en_bit);
	if (ret < 0)
		dev_err(&rdev->dev, "Error in updating reg 0x%x\n",
			ri->rinfo->reg_en_reg);

	return ret;
}

static struct regulator_ops tps65090_ops = {
	.enable		= tps65090_reg_enable,
	.disable	= tps65090_reg_disable,
	.is_enabled	= tps65090_reg_is_enabled,
};

#define tps65090_REG(_id, _en_reg, _en_bit, _ops)	\
{							\
	.reg_en_reg	= _en_reg,			\
	.en_bit		= _en_bit,			\
	.id		= TPS65090_REGULATOR_##_id,	\
	.desc = {					\
		.name = tps65090_rails(_id),		\
		.id = TPS65090_REGULATOR_##_id,		\
		.ops = &_ops,				\
		.type = REGULATOR_VOLTAGE,		\
		.owner = THIS_MODULE,			\
	},						\
}

static struct tps65090_regulator_info TPS65090_regulator_info[] = {
	tps65090_REG(DCDC1, 12, 0, tps65090_ops),
	tps65090_REG(DCDC2, 13, 0, tps65090_ops),
	tps65090_REG(DCDC3, 14, 0, tps65090_ops),
	tps65090_REG(FET1,  15, 0, tps65090_ops),
	tps65090_REG(FET2,  16, 0, tps65090_ops),
	tps65090_REG(FET3,  17, 0, tps65090_ops),
	tps65090_REG(FET4,  18, 0, tps65090_ops),
	tps65090_REG(FET5,  19, 0, tps65090_ops),
	tps65090_REG(FET6,  20, 0, tps65090_ops),
	tps65090_REG(FET7,  21, 0, tps65090_ops),
};

static inline struct tps65090_regulator_info *find_regulator_info(int id)
{
	struct tps65090_regulator_info *rinfo;
	int i;

	for (i = 0; i < ARRAY_SIZE(TPS65090_regulator_info); i++) {
		rinfo = &TPS65090_regulator_info[i];
		if (rinfo->desc.id == id)
			return rinfo;
	}
	return NULL;
}

static int __devinit tps65090_regulator_probe(struct platform_device *pdev)
{
	struct tps65090_regulator_info *rinfo = NULL;
	struct tps65090_regulator *ri = NULL;
	struct regulator_dev *rdev;
	struct tps65090_regulator_platform_data *tps_pdata;
	int id = pdev->id;

	dev_dbg(&pdev->dev, "Probing regulator %d\n", id);

	rinfo = find_regulator_info(id);
	if (rinfo == NULL) {
		dev_err(&pdev->dev, "invalid regulator ID specified\n");
		return -EINVAL;
	}
	tps_pdata = pdev->dev.platform_data;

	ri = devm_kzalloc(&pdev->dev, sizeof(*ri), GFP_KERNEL);
	if (!ri) {
		dev_err(&pdev->dev, "mem alloc for ri failed\n");
		return -ENOMEM;
	}

	ri->dev = &pdev->dev;
	ri->rinfo = rinfo;

	rdev = regulator_register(&ri->rinfo->desc, &pdev->dev,
				tps_pdata->reg_init_data, ri);
	if (IS_ERR(rdev)) {
		dev_err(&pdev->dev, "failed to register regulator %s\n",
				ri->rinfo->desc.name);
		return PTR_ERR(rdev);
	}
	ri->rdev = rdev;

	platform_set_drvdata(pdev, ri);
	return 0;
}

static int __devexit tps65090_regulator_remove(struct platform_device *pdev)
{
	struct tps65090_regulator *ri = platform_get_drvdata(pdev);

	regulator_unregister(ri->rdev);
	return 0;
}

static struct platform_driver tps65090_regulator_driver = {
	.driver	= {
		.name	= "tps65090-pmic",
		.owner	= THIS_MODULE,
	},
	.probe		= tps65090_regulator_probe,
	.remove		= __devexit_p(tps65090_regulator_remove),
};

static int __init tps65090_regulator_init(void)
{
	return platform_driver_register(&tps65090_regulator_driver);
}
subsys_initcall(tps65090_regulator_init);

static void __exit tps65090_regulator_exit(void)
{
	platform_driver_unregister(&tps65090_regulator_driver);
}
module_exit(tps65090_regulator_exit);

MODULE_DESCRIPTION("tps65090 regulator driver");
MODULE_AUTHOR("Venu Byravarasu <vbyravarasu@nvidia.com>");
MODULE_LICENSE("GPL v2");
