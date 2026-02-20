PROJECT = learn
BUILD_DIR = ../bin

SHARED_DIR = ../inc
CFILES = my-project.c
CFILES += my-vector.c
CFILES += my-rcc-setup.c
CFILES += my-io-setup.c
CFILES += my-systick-setup.c
CFILES += my-timer-setup.c
CFILES += my-usb-setup.c


# AFILES += api-asm.S

# TODO - you will need to edit these two lines!
DEVICE=stm32f413zht6
OOCD_FILE = board/st_nucleo_f4.cfg

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
