#include "usb_dev.h"

int usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	return 0;
}

void usb_detatch(struct usb_interface *intf)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);
}
