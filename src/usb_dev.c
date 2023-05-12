#include "usb_dev.h"

int usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	printk(KERN_INFO "%s: Function %s is being executed\n",  module_name(THIS_MODULE), __FUNCTION__);

	printk(KERN_INFO "%s: %s func: USB device [%04X:%04X] plugged\n",  module_name(THIS_MODULE), __FUNCTION__, id->idVendor,id->idProduct);

	return 0;
}

void usb_detatch(struct usb_interface *intf)
{
	printk(KERN_INFO "%s: Function %s is being executed\n",  module_name(THIS_MODULE), __FUNCTION__);
}
