#include <libopencm3/stm32/gpio.h>

#include "my-io-setup.h"

/* user leds and button */
#define LED_PORT	GPIOB
#define GREEN_PIN	GPIO0
#define BLUE_PIN	GPIO7
#define RED_PIN		GPIO14
#define BUT_PORT	GPIOC
#define BUT_PIN		GPIO13

/* MCO functions */
#define MCO1_PORT	GPIOA
#define MCO1_PIN	GPIO8
#define MCO2_PORT	GPIOC
#define MCO2_PIN	GPIO9

#define USB_PORT	GPIOA
#define USB_VBUS	GPIO9
#define USB_ID		GPIO10
#define USB_DM		GPIO11
#define USB_DP		GPIO12


void my_gpio_setup (void)
{
	gpio_mode_setup (LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, GREEN_PIN | BLUE_PIN);
	gpio_mode_setup (MCO1_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, MCO1_PIN);
	gpio_set_af (MCO1_PORT, GPIO_AF0, MCO1_PIN);
	gpio_mode_setup (MCO2_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, MCO2_PIN);
	gpio_set_af (MCO2_PORT, GPIO_AF0, MCO2_PIN);
	gpio_mode_setup (LED_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, RED_PIN);
	gpio_set_af (LED_PORT, GPIO_AF9, RED_PIN);
	gpio_mode_setup (BUT_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, BUT_PIN);

	/* USB port settings */
	gpio_mode_setup (USB_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE, USB_DM | USB_DP);
	gpio_set_af (USB_PORT, GPIO_AF9, USB_DM | USB_DP);
	

	//gpio_set(LED_PORT, GREEN_PIN);
}

void my_gpio_toggle (void)
{
	gpio_toggle (LED_PORT, BLUE_PIN);
}

uint16_t my_button_pressed (void)
{
	volatile uint16_t reg;
	reg = gpio_port_read (BUT_PORT) & BUT_PIN;
	return reg == BUT_PIN;
}