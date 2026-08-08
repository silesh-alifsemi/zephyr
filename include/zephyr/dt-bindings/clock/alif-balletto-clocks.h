/*
 * SPDX-FileCopyrightText: Copyright Alif Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_ALIF_BALLETTO_CLOCKS_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_ALIF_BALLETTO_CLOCKS_H_

/**
 * @file
 * @brief Clock IDs for Alif Balletto SoC family
 *
 * Defines peripheral clock identifiers for the Alif Balletto family.
 * Each clock ID is encoded using ALIF_CLK_CFG() macro from alif-clocks-common.h.
 */

#include "alif-clocks-common.h"

/**
 * @name Register offsets
 * @{
 */

/** UART control register offset in CLKCTL_PER_SLV */
#define ALIF_UART_CTRL_REG		0x08U

/** LPTIMER clock select register offset in VBAT */
#define ALIF_TIMER_CLKSEL_REG		0x04U

/** @} */

/**
 * @name UART peripheral clocks
 * @{
 */

/** UART0 clock sourced from system PCLK */
#define ALIF_UART0_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 0U, 1U, 1U, 1U, 8U, ALIF_PARENT_CLK_SYST_PCLK)
/** UART1 clock sourced from system PCLK */
#define ALIF_UART1_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 1U, 1U, 1U, 1U, 9U, ALIF_PARENT_CLK_SYST_PCLK)
/** UART2 clock sourced from system PCLK */
#define ALIF_UART2_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 2U, 1U, 1U, 1U, 10U, ALIF_PARENT_CLK_SYST_PCLK)
/** UART3 clock sourced from system PCLK */
#define ALIF_UART3_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 3U, 1U, 1U, 1U, 11U, ALIF_PARENT_CLK_SYST_PCLK)
/** UART4 clock sourced from system PCLK */
#define ALIF_UART4_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 4U, 1U, 1U, 1U, 12U, ALIF_PARENT_CLK_SYST_PCLK)
/** UART5 clock sourced from system PCLK */
#define ALIF_UART5_SYST_PCLK        \
	ALIF_CLK_CFG(CLKCTL_PER_SLV, UART_CTRL, 5U, 1U, 1U, 1U, 13U, ALIF_PARENT_CLK_SYST_PCLK)

/** @} */

/**
 * @name LPTIMER peripheral clocks
 *
 * Each LPTIMER channel has a two-bit clock source selector in the VBAT
 * TIMER_CLKSEL register (SEL1 at bit 0 and SEL2 at bit 4). Only the two
 * SoC-internal sources are described here: S32K_CLK (selector value 0, the
 * reset default) and 128K_CLK (value 1). The remaining selector values route
 * an external clock from the LPTMRn_CLK_IO pin or cascade LPTIMER1 with
 * LPTIMER0.
 *
 * The channels have no clock enable bit, so these clocks are always on and
 * only the source selection is programmed.
 *
 * @{
 */

/** LPTIMER0 clock sourced from S32K_CLK */
#define ALIF_LPTIMER0_S32K_CLK      \
	ALIF_CLK_CFG(VBAT, TIMER_CLKSEL, 0U, 0U, 0U, 2U, 0U, ALIF_PARENT_CLK_S32K)
/** LPTIMER0 clock sourced from 128K_CLK */
#define ALIF_LPTIMER0_128K_CLK      \
	ALIF_CLK_CFG(VBAT, TIMER_CLKSEL, 0U, 0U, 1U, 2U, 0U, ALIF_PARENT_CLK_128K)
/** LPTIMER1 clock sourced from S32K_CLK */
#define ALIF_LPTIMER1_S32K_CLK      \
	ALIF_CLK_CFG(VBAT, TIMER_CLKSEL, 0U, 0U, 0U, 2U, 4U, ALIF_PARENT_CLK_S32K)
/** LPTIMER1 clock sourced from 128K_CLK */
#define ALIF_LPTIMER1_128K_CLK      \
	ALIF_CLK_CFG(VBAT, TIMER_CLKSEL, 0U, 0U, 1U, 2U, 4U, ALIF_PARENT_CLK_128K)

/** @} */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_ALIF_BALLETTO_CLOCKS_H_ */
