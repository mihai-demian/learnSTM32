# learnSTM32
learning embedded programming using an STM32F413ZH on a nucleo 144 developer board

## initialization of the repo
git clone https://github.com/mihai-demian/learnSTM32.git

git submodule add https://github.com/libopencm3/libopencm3.git

mkdir inc src bin

download (single backtick)(`rules.md`) and (double backtick)(``my-project/Makefile``) from (link:) [libopencm3-templates](https://github.com/libopencm3/libopencm3-template.git) and copied them to current directory, then added them to git

## electrical connections
The PCB has 3 LEDs
- green on PB0
- blue on PB7
- $red on PB14

and a user button on PC13.

Table 6-1 in OTG and EH Supliment defines the OTG descriptor
|   Offset  |   Field   |   Size    |   Value   |   Description |
|-----------|-----------|-----------|-----------|---------------|
|   0       |bLength    | 1         | Number (5)|Size of descriptor |
