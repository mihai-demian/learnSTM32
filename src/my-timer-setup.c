#include <libopencm3/stm32/timer.h>

#include "my-timer-setup.h"

/* tim_freq = sys_freq / ((p
sc - 1) * (arr - 1))*/
#define TIM12_PSC_VAL   (100)
#define TIM12_ARR_VAL   (250) // 1000 = 1kHz; 500 = 2kHz; 250 = 4kHz etc
#define TIM12_OC_VAL    (TIM12_ARR_VAL / 2)

uint16_t tim12_dc;

void my_tim12_setup (void)
{
    /* TIM12 CR1 bits[4:6] must be kept at reset value: only EDGE_ALLIGNED and UP-COUNTING */
    timer_set_mode (TIM12, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
    timer_set_oc_mode (TIM12, TIM_OC1, TIM_OCM_PWM1);
    timer_enable_counter (TIM12);
    timer_enable_oc_output (TIM12, TIM_OC1);
    timer_set_prescaler (TIM12, TIM12_PSC_VAL - 1);
    timer_set_period (TIM12, TIM12_ARR_VAL - 1);
    timer_set_oc_value (TIM12, TIM_OC1, TIM12_OC_VAL + 1);
}

void tim12_set_duty_cycle (uint16_t dc)
{

    /* duty_cycle = ccr / arr * 100 
     * ccr = arr * duty_cycle / 100
     */
    uint16_t val = TIM12_ARR_VAL * dc / 100 + 1;
    timer_set_oc_value (TIM12, TIM_OC1, val);
}