# Linux USB Driver

## About
Linux USB driver for *Kingston Technology Company Inc. USB DISK 2.0* with user-kernel interraction support.

## How to use
<details>
<summary><i>see all Makefile features</i></summary>

	make/make all - build driver
	make dir - create build/modules directories
	make rdir - remove build/modules directories
	make clean - cleanup build/modules directories
	make install - copy driver into modules directory
</details>

- build driver:<br>
`$ make`

- check whether default usb driver is enabled:<br>
`$ lsmod | grep usb_storage`

- disable default usb driver and all it's dependencies in case it is running:<br>
`$ sudo rmmod uas usb_storage`

*Note that name of default usb driver and it's dependencies might be different for your system!*

- upload driver into kernel:<br>
`$ sudo insmod ./modules/usb_dev.ko`

- plug USB device

## Usage
	$ echo 0x15 > /proc/usb_dev
	$ cat /proc/usb_dev
	$ 0x15
	$ echo 0xF8 > /proc/usb_dev
	$ cat /proc/usb_dev
	$ 0xF8
