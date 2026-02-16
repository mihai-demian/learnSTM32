#ifndef MY_TIMER_SETUP_H
#define MY_TIMER_SETUP_H

#include <stdint.h>

extern uint16_t tim12_dc;

void my_tim12_setup (void);
void tim12_set_duty_cycle (uint16_t dc);

#endif /* MY_TIMER_SETUP_H */