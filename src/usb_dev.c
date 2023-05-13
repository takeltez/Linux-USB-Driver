#include "usb_dev.h"

struct proc_dir_entry *proc_file;
struct usb_device *usb_dev;

 ssize_t usb_read(struct file *File, char *user_buffer, size_t count, loff_t *offs)
 {
	char text[32];
	int to_copy, not_copied, delta, status;
	u8 val;

	to_copy = min(count, sizeof(text));

	status = usb_control_msg_recv(usb_dev, usb_rcvctrlpipe(usb_dev, 0), 0x2, 0xC0, 0, 0, (unsigned char *) &val, 1, 100, GFP_KERNEL);
	
	if(status < 0)
	{
		printk(KERN_ERR "%s: Error during read control message (code %d)\n", module_name(THIS_MODULE), status);

		return -1;
	}

	sprintf(text, "0x%x\n", val);

	not_copied = copy_to_user(user_buffer, text, to_copy);

	delta = to_copy - not_copied;

	return delta;
}

ssize_t usb_write(struct file *File, const char *user_buffer, size_t count, loff_t *offs)
{
	char text[255];
	int to_copy, not_copied, delta, status;
	long val;
	u16 seg_val;

	memset(text, 0, sizeof(text));

	to_copy = min(count, sizeof(text));

	not_copied = copy_from_user(text, user_buffer, to_copy);

	if(kstrtol(text, 0, &val) != 0)
	{
		printk(KERN_ERR "%s: Error converting input\n", module_name(THIS_MODULE));

		return -1;
	}

	seg_val = (u16)val;

	status = usb_control_msg(usb_dev, usb_sndctrlpipe(usb_dev, 0), 0x1, 0x40, seg_val, 0, NULL, 0, 100);

	if(status < 0)
	{
		printk(KERN_ERR "%s: Error during write control message (code %d)\n", module_name(THIS_MODULE), status);

		return -1;
	}

	delta = to_copy - not_copied;

	return delta;
}

struct proc_ops fops = {
	.proc_read = usb_read,
	.proc_write = usb_write,
};

int usb_plug(struct usb_interface *intf, const struct usb_device_id *id)
{
	printk(KERN_INFO "%s: USB device %d is plugged: [%04X:%04X]\n",
	                                                          module_name(THIS_MODULE),
	                                                          intf->cur_altsetting->desc.bInterfaceNumber,
	                                                          id->idVendor,
	                                                          id->idProduct);

	usb_dev = interface_to_usbdev(intf);

	if(usb_dev == NULL)
	{
		printk(KERN_ERR "%s: Error getting device from interface\n", module_name(THIS_MODULE));

		return -1;
	}

	proc_file = proc_create("usb_dev", 0666, NULL, &fops);

	if(proc_file == NULL)
	{
		printk(KERN_ERR "%s: Error creating /proc/usb_dev\n", module_name(THIS_MODULE));

		return -ENOMEM;
	}

	return 0;
}

void usb_unplug(struct usb_interface *intf)
{
	proc_remove(proc_file);

	printk(KERN_INFO "%s: USB device %d is unplugged\n",  module_name(THIS_MODULE), intf->cur_altsetting->desc.bInterfaceNumber);
}
