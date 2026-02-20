#ifndef MY_USB_SETUP_H
#define MY_USB_SETUP_H

/*
 * NU mai sunt necesare
extern struct usb_device_descriptor dev;
extern struct usb_endpoint_descriptor comm_endp[];
extern struct usb_endpoint_descriptor data_endp[];
extern struct cdcacm_functional_descriptors;
extern struct usb_interface_descriptor comm_iface[];
extern struct usb_interface_descriptor data_iface[];
extern struct usb_interface ifaces[];
extern struct usb_config_descriptor config;
*/

/* 
 * NU se mai prototipeaza!
enum usbd_request_return_codes cdcacm_control_request(usbd_device *usbd_dev,
	struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
	void (**complete)(usbd_device *usbd_dev, struct usb_setup_data *req));
void cdcacm_data_rx_cb(usbd_device *usbd_dev, uint8_t ep);
void cdcacm_set_config(usbd_device *usbd_dev, uint16_t wValue);
*/

usbd_device * my_usb_dev_init (void);

#endif /* MY_USB_SETUP_H */