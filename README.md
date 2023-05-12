# Linux USB Driver

## About
Linux USB driver for *Kingston Technology Company Inc. USB DISK 2.0* device.

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

## Usage
- upload driver into kernel:<br>
`$ sudo insmod ./modules/usb_dev.ko`

- attatch and detatch USB device

- remove driver from kernel:<br>
`$ sudo rmmod usb_dev`

- check log file:<br>
`$ tail -n [number of lines] /var/log/syslog`

<details>
<summary><i>/var/log/syslog</i></summary>

	...
	usb_dev: Function usb_driver_load is being execute
	...
	usb_dev: Function usb_probe is being executed
	usb_dev: usb_probe func: USB device [13FE:4300] plugged
	...
	usb_dev: Function usb_detatch is being executed
	...
	usb_dev: Function usb_driver_remove is being executed
	...
</details>
