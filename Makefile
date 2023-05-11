TARGET := usb_dev

SRC_DIR := src/
BUILD_DIR := build/
OBJ_DIR := obj/
MOD_DIR := modules/

MOD_EXT := .ko

KDIR := /lib/modules/$(shell uname -r)/build

SRCS := $(wildcard $(PWD)/$(SRC_DIR)*.c)
OBJS := $(patsubst $(PWD)/$(SRC_DIR)%.c, $(SRC_DIR)%.o, $(SRCS))

obj-m := $(OBJ_DIR)$(TARGET).o
$(OBJ_DIR)$(TARGET)-objs := $(OBJS)

.PHONY: all clean install dir rdir

all: dir $(TARGET) install

$(TARGET):
	$(MAKE) -C $(KDIR) M=$(PWD)/$(BUILD_DIR) src=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD)/$(BUILD_DIR) src=$(PWD) clean
	rm -f $(MOD_DIR)$(TARGET)$(MOD_EXT)
	rm -rf $(BUILD_DIR)*

install:
	install $(BUILD_DIR)$(OBJ_DIR)$(TARGET)$(MOD_EXT) $(MOD_DIR)
	rm -f $(BUILD_DIR)$(OBJ_DIR)$(TARGET)$(MOD_EXT)

dir:
	mkdir -p $(MOD_DIR)
	mkdir -p $(BUILD_DIR)

rdir:
	rm -rf $(MOD_DIR)
	rm -rf $(BUILD_DIR)
