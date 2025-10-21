/*
 * Copyright (c) 2025 Alif Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/arch/arm/mpu/arm_mpu_mem_cfg.h>

/*
 * Peripheral region starting at 0x1A000000 (32MB)
 * This region hosts various peripheral subsystems including
 * the pin control logic and clock control registers.
 */
#define PERIPHERAL_BASE    0x1A000000U
#define PERIPHERAL_SIZE    (32 * 1024 * 1024)

static const struct arm_mpu_region mpu_regions[] = {
	MPU_REGION_ENTRY("FLASH", CONFIG_FLASH_BASE_ADDRESS,
			REGION_FLASH_ATTR(CONFIG_FLASH_BASE_ADDRESS, CONFIG_FLASH_SIZE * 1024)),

	MPU_REGION_ENTRY("SRAM", CONFIG_SRAM_BASE_ADDRESS,
			REGION_RAM_ATTR(CONFIG_SRAM_BASE_ADDRESS, CONFIG_SRAM_SIZE * 1024)),

	MPU_REGION_ENTRY("PERIPHERALS", PERIPHERAL_BASE,
			REGION_DEVICE_ATTR(PERIPHERAL_BASE, PERIPHERAL_SIZE)),
};

const struct arm_mpu_config mpu_config = {
	.num_regions = ARRAY_SIZE(mpu_regions),
	.mpu_regions = mpu_regions,
};
