# learnSTM32
learning embedded programming using an STM32F413ZH on a nucleo 144 developer board

## initialization of the repo
Download newly created repo
```
git clone https://github.com/mihai-demian/learnSTM32.git
```
Add libopencm3 as a submodule
```
git submodule add https://github.com/libopencm3/libopencm3.git
```
Create required subdirectories
```
mkdir inc src bin
```

download `rules.md` and `my-project/Makefile` [libopencm3-templates](https://github.com/libopencm3/libopencm3-template.git) and copy them to current directory, then added them to git

## electrical connections
The PCB has 3 LEDs
- green on PB0
- blue on PB7
- red on PB14

and a user button on PC13.

Table 6-1 in OTG and EH Supliment defines the OTG descriptor
|   Offset  |   Field   |   Size    |   Value   |   Description |
|-----------|-----------|-----------|-----------|---------------|
|   0       |bLength    | 1         | Number (5)|Size of descriptor |

| DC | U $_{t}$   | U ~m~  |
|----|--------|-------|
|  5 | 0.165  | 0.165 |

&plusmn;
