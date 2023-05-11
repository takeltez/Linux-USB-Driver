#ifndef USB_DEV_H
#define USB_DEV_H

#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

#define VID 0x13fe
#define PID 0x4300

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aleksei Karasev");
MODULE_DESCRIPTION("USB driver for Kingston Technology Company Inc. USB DISK 2.0");

extern struct usb_device_id usb_table[];
extern struct usb_driver usb_desc;

int usb_probe(struct usb_interface *intf, const struct usb_device_id *id);
void usb_detatch(struct usb_interface *intf);

#endif
