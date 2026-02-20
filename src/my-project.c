#include <stdint.h>
#include <libopencm3/usb/usbd.h>


#include "my-projec.h"
#include "my-io-setup.h"
#include "my-timer-setup.h"
#include "my-usb-setup.h"

uint16_t dc;
uint16_t in, mem;
uint32_t count;
usbd_device *usbdev;

int main(void) {
	/* add your own code */
	mem = 0;
	dc = 0;
	count = 0;
	usbdev = my_usb_dev_init();
	while (1)
	{
		in = my_button_pressed ();
		if (in & !mem) {
			my_gpio_toggle ();
			dc += 10;
			if (dc > 100) dc = 0;
			tim12_set_duty_cycle (dc);
			count++;
			
		}
		mem =  in;
		usbd_poll(usbdev);
	}
	
}


	