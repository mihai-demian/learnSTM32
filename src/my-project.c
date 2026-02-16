#include <stdint.h>

#include "my-projec.h"
#include "my-io-setup.h"
#include "my-timer-setup.h"
uint16_t dc = 0;

int main(void) {
	/* add your own code */
	while (1)
	{
		if (my_button_pressed()) {
			my_gpio_toggle ();
			dc += 10;
			if (dc > 100) dc = 0;
			tim12_set_duty_cycle (dc);
		}
	}
	
}


	