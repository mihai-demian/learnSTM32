# learnSTM32
learning embedded programming using an STM32F413ZH on a nucleo 144 developer board

## initialization of the repo
git clone https://github.com/mihai-demian/learnSTM32.git

git submodule add https://github.com/libopencm3/libopencm3.git

mkdir inc src bin

download ``rules.md`` and ``my-project/Makefile`` from https://github.com/libopencm3/libopencm3-template.git and copied them to current directory, then added them to git

## electrical connections
The PCB has 3 LEDs
- $${\color{green}green on PB0
- $${\color{blue}blue} on PB7
- $${\color{red}red} on PB14
and a user button on PC13.

## pll config
- cpu freq=100MHz, AHB=100MHz, APB=50MHz
- pll & plli2s with 8MHz HSE
- plli2s enabled, set as USB clock source

## small tests
- while counting ticks every cpu cycle, there are 3196800 cpu cycles for a 1Hz toggling freq 
- after enablig systick with 1000Hz freq and generating an interrupt (when?) and using that interrupt to toggle the $${\color{blue}LED}, the measured freq of the led is 500.0Hz.

## setting TIM12
- setting TIM12_CH1 as a driver for the $${\color{red}red} LED (AF9) failed at first try. Reason: 