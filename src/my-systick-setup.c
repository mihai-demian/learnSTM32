#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/rcc.h>

#include "my-systick-setup.h"

#define CPU_FREQ    (100000000)
#define TICK_FREQ   (1000)

extern struct rcc_clock_scale my_rcc_hse_8mhz_3v3;

void my_systick_setup (void)
{
    systick_set_frequency (TICK_FREQ, my_rcc_hse_8mhz_3v3.ahb_frequency);
    systick_counter_enable ();
    systick_interrupt_enable ();
}