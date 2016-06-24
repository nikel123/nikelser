#include <linux/usb/ch9.h>
#include <linux/usb/cdc.h>

struct usb_device_descriptor
device_descriptor = {
  .bLength            = sizeof(device_descriptor),
  .bDescriptorType    = USB_DT_DEVICE,

  .bcdUSB             = 0x200,

  .bDeviceClass       = USB_CLASS_COMM,
  .bDeviceSubClass    = USB_CDC_SUBCLASS_ACM,

  .bMaxPacketSize0    = 64,

  .idVendor           = 0x27dd,
  .idProduct          = 0x16c0,
  .bcdDevice          = 1,

  .iManufacturer      = 1,
  .iProduct           = 2,

  .bNumConfigurations = 1
};

struct {

  struct usb_config_descriptor config_descriptor;

} __attribute__((packed))
full_config_descriptor = {

  .config_descriptor = {
    .bLength             = sizeof(full_config_descriptor.config_descriptor),
    .bDescriptorType     = USB_DT_CONFIG,

    .wTotalLength        = sizeof(full_config_descriptor),

    .bNumInterfaces      = 1,
    .bConfigurationValue = 0,
    .iConfiguration      = 0,
    .bmAttrubutes        = USB_CONFIG_ATT_ONE,

    .bMaxPower           = 50

  },



};
