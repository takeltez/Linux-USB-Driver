#ifndef USB_DEV_H
#define USB_DEV_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/proc_fs.h>

#define VID 0x13fe
#define PID 0x4300

extern struct usb_device_id usb_table[];
extern struct usb_driver usb_desc;
extern struct proc_dir_entry *proc_file;
extern struct usb_device *usb_dev;
extern struct proc_ops fops;

int usb_plug(struct usb_interface *intf, const struct usb_device_id *id);
void usb_unplug(struct usb_interface *intf);

ssize_t usb_read(struct file *f, char __user *buf, size_t cnt, loff_t *off);
ssize_t usb_write(struct file *f, const char __user *buf, size_t cnt, loff_t *off);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aleksei Karasev");
MODULE_DESCRIPTION("USB driver for Kingston Technology Company Inc. USB DISK 2.0");

#endif
