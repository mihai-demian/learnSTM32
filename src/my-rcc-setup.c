#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>

#include "my-rcc-setup.h"

#define RCC_PLLI2SCFGR_PLLI2SM_MASK		0x3F
#define RCC_PLLI2SCFGR_PLLI2SM_SHIFT	0
#define RCC_PLLI2SCFGR_PLI2SSRC_MASK	0x1
#define RCC_PLLI2SCFGR_PLI2SSRC_SHIFT	22


const struct rcc_clock_scale my_rcc_hse_8mhz_3v3 = {
    .pllm = 4,
    .plln = 100,
    .pllp = 2,
    .pllq = 5,
    .pllr = 5,
	.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
	.hpre = RCC_CFGR_HPRE_DIV_NONE,
	.ppre1 = RCC_CFGR_PPRE_DIV_2,
	.ppre2 = RCC_CFGR_PPRE_DIV_NONE,
	.voltage_scale = PWR_SCALE1,
	.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN | FLASH_ACR_LATENCY_3WS,
	.ahb_frequency  = 100000000,
	.apb1_frequency =  50000000,
	.apb2_frequency = 100000000
};


/**
 * @brief set up PLLI2S
 * 
 * @param m 	division factor for the audio PLL (PLLI2S) input clock, 2 <= m <= 63
 * @param n 	PLLI2S multiplicaton facutor for VCO, 50 <= n <= 432
 * @param q 	PLLI2S division factor for USB OTG, FS/SDIO/RNG, 2 <= q <= 15
 * @param r 	PLLI2S division factor for I2S clock, 2 <= r <= 7 (max freq 192MHz)
 * @param src	PLLI2S entry clock source; 0=PLLSRC, 1=CK_I2S_EXT
 */
static void my_pll2_conf (uint16_t m, uint16_t n, uint16_t q, uint16_t r, uint8_t src)
{
	RCC_PLLI2SCFGR = (
	  ((m & RCC_PLLI2SCFGR_PLLI2SM_MASK) << RCC_PLLI2SCFGR_PLLI2SM_SHIFT) |
	  ((n & RCC_PLLI2SCFGR_PLLI2SN_MASK) << RCC_PLLI2SCFGR_PLLI2SN_SHIFT) |
	  ((q & RCC_PLLI2SCFGR_PLLI2SQ_MASK) << RCC_PLLI2SCFGR_PLLI2SQ_SHIFT) |
	  ((r & RCC_PLLI2SCFGR_PLLI2SR_MASK) << RCC_PLLI2SCFGR_PLLI2SR_SHIFT) |
	  ((src & RCC_PLLI2SCFGR_PLI2SSRC_MASK) << RCC_PLLI2SCFGR_PLI2SSRC_SHIFT));
}

static void my_set_48mhz_source (void)
{
	RCC_DCKCFGR2 |= RCC_DCKCFGR_48MSEL;
}

static void my_setup_mco (uint8_t mco1_src, uint8_t mco1_pre, uint8_t mco2_src, uint8_t mco2_pre)
{
	uint32_t reg = RCC_CFGR;
	reg &= ~((RCC_CFGR_MCO1_MASK << RCC_CFGR_MCO1_SHIFT) | 
			 (RCC_CFGR_MCO1PRE_MASK << RCC_CFGR_MCO1PRE_SHIFT) |
			 (RCC_CFGR_MCO2_MASK << RCC_CFGR_MCO2_SHIFT) |
			 (RCC_CFGR_MCO2PRE_MASK << RCC_CFGR_MCO2PRE_SHIFT));
	uint32_t tmp = ((mco1_src & RCC_CFGR_MCO1_MASK) << RCC_CFGR_MCO1_SHIFT) | 
				   ((mco1_pre & RCC_CFGR_MCO1PRE_MASK) << RCC_CFGR_MCO1PRE_SHIFT) |
				   ((mco2_src & RCC_CFGR_MCO2_MASK) << RCC_CFGR_MCO2_SHIFT) |
				   ((mco2_pre & RCC_CFGR_MCO2PRE_MASK) << RCC_CFGR_MCO2PRE_SHIFT);
	reg |= tmp;
	RCC_CFGR = reg;
}
void my_setup_pll (void)
{
	my_pll2_conf (4, 192, 8, 6, 0);
	my_set_48mhz_source ();
    rcc_clock_setup_pll (&my_rcc_hse_8mhz_3v3);
	rcc_osc_on (RCC_PLLI2S);
	rcc_wait_for_osc_ready (RCC_PLLI2S);
	my_setup_mco (RCC_CFGR_MCO1_PLL, RCC_CFGR_MCOPRE_DIV_5, RCC_CFGR_MCO2_PLLI2S, RCC_CFGR_MCOPRE_DIV_4);
	rcc_periph_clock_enable (RCC_GPIOA);
	rcc_periph_clock_enable (RCC_GPIOB);
	rcc_periph_clock_enable (RCC_GPIOC);
	//rcc_periph_clock_enable (RCC_TIM1);
}
