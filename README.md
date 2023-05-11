# Linux USB Driver

## About
Linux USB driver for Kingston Technology Company Inc. USB DISK 2.0

## How to use
<details>
<summary><i>see all Makefile features</i></summary>

	make/make all - build driver
	make dir - create build/modules directories
	make rdir - remove build/modules directories
	make clean - cleanup build/modules directories
	make install - copy driver into modules directory
</details>

- build project:<br>
`make`

- upload driver `usb_dev.ko` into kernel:<br>
`sudo insmod ./modules/usb_dev.ko`

## Usage
- attatch and detatch USB device
- check `/var/log/syslog`<br>
`tail -n [number of lines] /var/log/syslog`

<details>
<summary><i>/var/log/syslog</i></summary>

	...
	Function module_upload is being executed
	...
	Function usb_probe is being executed
	...
	Function usb_detatch is being executed
	...
	Function module_extract is being executed
	...
</details>
