
#include <libusbp.hpp>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

const uint16_t vendor_id = 0x1a86;
const uint16_t product_id = 0x7523;
const uint8_t interface_number = 0;
const bool composite = true;

int main()
{
    // Get device path name from vid & pid
    libusbp::device device = libusbp::find_device_with_vid_pid(vendor_id, product_id);
    if (!device)
    {
        std::cerr << "Device not found." << std::endl;
        return 1;
    }

    libusbp::serial_port port(device, interface_number, composite);
    std::string port_name = port.get_name();
    std::cout << port_name << std::endl;

    char port_name_arr[port_name.size() + 1];
    strcpy(port_name_arr, port_name.c_str());

    // Open serial port
    int serial_port = open(port_name_arr, O_RDWR);

    if (serial_port < 0) {
        printf("Error %i from open: %s\n", errno, strerror(errno));
    }

    return 0;
}
