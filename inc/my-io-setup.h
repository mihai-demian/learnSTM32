#ifndef MY_IO_SETUP_H
#define MY_IO_SETUP_H

#include <stdint.h>

void my_gpio_setup (void);
void my_gpio_toggle (uint32_t port, uint16_t gpios);

#endif /* MY_IO_SETUP_H */