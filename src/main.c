#include "usb_dev.h"

struct usb_device_id usb_table[] = {
	{USB_DEVICE(VID, PID)},
	{},
};

MODULE_DEVICE_TABLE(usb, usb_table);

struct usb_driver usb_desc = {
	.name = "usb_dev",
	.id_table = usb_table,
	.probe = usb_plug,
	.disconnect = usb_unplug,
};

static int __init usb_driver_load(void)
{
	int res;

	printk(KERN_INFO "%s: driver is loaded\n",  module_name(THIS_MODULE));

	if((res = usb_register(&usb_desc)))
	{
		printk(KERN_ERR "%s: unable to register USB device!\n",  module_name(THIS_MODULE));

		return -res;
	}

	return 0;
}

static void __exit usb_driver_remove(void)
{
	printk(KERN_INFO "%s: driver is unloaded\n",  module_name(THIS_MODULE));

	usb_deregister(&usb_desc);
}

module_init(usb_driver_load);
module_exit(usb_driver_remove);
