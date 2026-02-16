/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>,
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */
#include <libopencm3/cm3/vector.h>

#include "my-rcc-setup.h"
#include "my-io-setup.h"
#include "my-systick-setup.h"
#include "my-timer-setup.h"
#include "my-projec.h"
#include "my-vector.h"

uint32_t tick_irq = 0;


void reset_handler(void)
{
	
	my_setup_pll ();
	my_gpio_setup ();
	my_systick_setup ();
	my_tim12_setup ();
	/* Call the application's entry point. */
	(void)main();
}

void sys_tick_handler(void)
{
	;
}
