/*
 * Copyright (C) James R. Wylder
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <linux/delay.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>

static int brdm4371_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	uint32_t count = 7;
pr_info("JRW: %s <- %pS\n", __func__, __builtin_return_address(0));
	if (np) {
		of_property_read_u32(np, "count", &count);
	}
pr_info("JRW: %s count = %u\n", __func__, count);

	return 0;
}

static int brdm4371_remove(struct platform_device *pdev)
{
pr_info("JRW: %s <- %pS\n", __func__, __builtin_return_address(0));

	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id brdm4371_of_ids[] = {
	{ .compatible = "jrw,brdm4371" },
	{},
};
#endif

static struct platform_driver brdm4371_driver = {
	.probe   = brdm4371_probe,
	.remove  = brdm4371_remove,
	.driver  = {
		.owner = THIS_MODULE,
		.name = "brdm4371",
		.of_match_table = of_match_ptr(brdm4371_of_ids),
	},
};

#ifndef CONFIG_OF
static struct platform_device brdm4371_device = {
    .name           = "brdm4371",
    .id             = 0,
    .num_resources  = 0,
};
#endif


static int __init brdm4371_init(void)
{
    int rv;

pr_info("JRW: %s <- %pS\n", __func__, __builtin_return_address(0));
    rv = platform_driver_register(&brdm4371_driver);
    if (rv < 0) {
        pr_err("brdm4371 failed to register\n");
        return rv;
    }

#ifndef CONFIG_OF
    pr_info("JRW: %s load without of\n", __func__);
    rv = platform_device_register(&brdm4371_device);
    if (rv < 0) {
        pr_err("brdm4371 failed to register\n");
        platform_driver_unregister(&brdm4371_driver);
        return rv;
    }
#endif

    return 0;
}

static void __exit brdm4371_exit(void)
{
	pr_info("JRW: %s <- %pS\n", __func__, __builtin_return_address(0));
    platform_driver_unregister(&brdm4371_driver);
}

module_init(brdm4371_init);
module_exit(brdm4371_exit);

MODULE_AUTHOR("James R. Wylder");
MODULE_DESCRIPTION("Example Driver Using Overlays");
MODULE_LICENSE("GPL");
