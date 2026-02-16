# learnSTM32
learning embedded programming using an STM32F413ZH on a nucleo 144 developer board

## initialization of the repo
git clone https://github.com/mihai-demian/learnSTM32.git

git submodule add https://github.com/libopencm3/libopencm3.git

mkdir inc src bin

download ``rules.md`` and ``my-project/Makefile`` from https://github.com/libopencm3/libopencm3-template.git and copied them to current directory, then added them to git

## electrical connections
The PCB has 3 LEDs
- $${\color{green}green}$$ on PB0
- $${\color{blue}blue}$$ on PB7
- $${\color{red}red}$$ on PB14
and a user button on PC13.

## pll config
- cpu freq=100MHz, AHB=100MHz, APB=50MHz
- pll & plli2s with 8MHz HSE
- plli2s enabled, set as USB clock source

## small tests
- while counting ticks every cpu cycle, there are 3196800 cpu cycles for a 1Hz toggling freq 
- after enablig systick with 1000Hz freq and generating an interrupt (when?) and using that interrupt to toggle the $${\color{blue}LED}$$, the measured freq of the led is 500.0Hz.

## setting TIM12
- setting TIM12_CH1 as a driver for the $${\color{red}LED}$$ (AF9) failed at first try. Reason: may have forgotten to enable systick.
### Take 2
- enable systick
- enable periph TIM12
- set $${\color{red}LED}$$ (AF9)
- set up TIM12 OC1 
[x] FAILED! looks like it's not possible to convert from float to uint32_t.
[x] reading and writing to external variables in multiple locations does not work as expected!
- setting the oc value to between 0 and arr value gives a duty cycle between 9.9% to 99.8% (:manshrug:)
- external variable don't work as expeted!
- set the $${\color{red}LED}$$ with 4kHz 50% static duty cycle. [X] Confirmed with multimeter.