#define LINUX

#ifdef WINDOWS
#include "libusb.h"
#endif
#ifdef LINUX
#include <libusb-1.0/libusb.h>
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DEV_VID 0x16c0
#define DEV_PID 0x05df
#define DEV_CONFIG 1
#define DEV_INTF 0
#define EP_IN 0x81
#define EP_OUT 0x01
unsigned char COMMAND_1[8] = {0x63,0x00,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_2[8] = {0x63,0x01,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_3[8] = {0x63,0x02,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_4[8] = {0x63,0x03,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_5[8] = {0x63,0x04,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_6[8] = {0x63,0x05,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_7[8] = {0x63,0x06,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_8[8] = {0x63,0x07,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_9[8] = {0x63,0x08,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_10[8] = {0x63,0x09,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_11[8] = {0x63,0x0a,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_12[8] = {0x63,0x0b,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_13[8] = {0x63,0x0c,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_14[8] = {0x63,0x0d,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_15[8] = {0x63,0x0e,0x00,0x00,0x08,0xff,0x08,0xff};
unsigned char COMMAND_16[8] = {0x63,0x0f,0x00,0x00,0x08,0xff,0x08,0xff};
int main(int argc, char * argv[])
{
  libusb_device_handle * handle;
	int ret;
	int i;
	char port;
	unsigned char buf[65];
	if (argc != 2) {
		printf("Укажите номер порта который вы хотите выключить (1...16)\n", argv[0]);
		return -1;
	}
	port = atoi(argv[1]);

	libusb_init(NULL);
	libusb_set_debug(NULL, 3);
	handle = libusb_open_device_with_vid_pid(NULL, DEV_VID, DEV_PID);
	if (handle == NULL) {
	    printf("Не удалось найти устройство\n");
	    libusb_exit(NULL);
	    return 0;
	}
	if (libusb_kernel_driver_active(handle,DEV_INTF))
		libusb_detach_kernel_driver(handle, DEV_INTF);
	if ((ret = libusb_set_configuration(handle, DEV_CONFIG)) < 0)
	{
		printf("Ошибка конфигурации\n");
		libusb_close(handle);
		libusb_exit(NULL);
		if (ret == LIBUSB_ERROR_BUSY)
		    printf("B\n");
		printf("ret:%i\n", ret);    
		return 0;
	}
	if (libusb_claim_interface(handle,  DEV_INTF) < 0)
	{
		printf("Ошибка интерфейса\n");
		libusb_close(handle);
		libusb_exit(NULL);
		return 0;
	}
	if (port == 1){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_1, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);
	}
	else if (port == 2){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_2, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 3){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_3, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 4){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_4, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 5){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_5, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 6){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_6, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 7){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_7, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 8){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_8, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 9){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_9, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 10){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_10, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 11){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_11, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 12){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_12, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 13){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_13, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 14){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_14, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 15){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_15, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	else if (port == 16){
	ret = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE|LIBUSB_ENDPOINT_OUT, 0x9, 0x300, 0, COMMAND_16, 8, 100);
	libusb_interrupt_transfer(handle, EP_IN, buf, 8, &ret, 100);	
	}
	
	libusb_attach_kernel_driver(handle, DEV_INTF);
	libusb_close(handle);
	libusb_exit(NULL);
	return 0;
}
