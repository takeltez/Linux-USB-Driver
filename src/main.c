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

static int __init module_upload(void)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	int res;

	res = usb_register(&usb_desc);

	if(res)
	{
		printk(KERN_ERR "unable to register USB-device!\n");

		return -res;
	}

	return 0;
}

static void __exit module_extract(void)
{
	printk(KERN_INFO "Function %s is being executed\n", __FUNCTION__);

	usb_deregister(&usb_desc);
}

module_init(module_upload);
module_exit(module_extract);
