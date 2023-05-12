#include "usb_dev.h"

struct usb_device_id usb_table[] = {
	{USB_DEVICE(VID, PID)},
	{},
};

MODULE_DEVICE_TABLE(usb, usb_table);

struct usb_driver usb_desc = {
	.name = "usb_dev",
	.id_table = usb_table,
	.probe = usb_probe,
	.disconnect = usb_detatch,
};

static int __init usb_driver_load(void)
{
	printk(KERN_INFO "%s: Function %s is being executed\n",  module_name(THIS_MODULE), __FUNCTION__);

	int res;

	res = usb_register(&usb_desc);

	if(res)
	{
		printk(KERN_ERR "%s: unable to register USB-device!\n",  module_name(THIS_MODULE));

		return -res;
	}

	return 0;
}

static void __exit usb_driver_remove(void)
{
	printk(KERN_INFO "%s: Function %s is being executed\n",  module_name(THIS_MODULE), __FUNCTION__);

	usb_deregister(&usb_desc);
}

module_init(usb_driver_load);
module_exit(usb_driver_remove);
