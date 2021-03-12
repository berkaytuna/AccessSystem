#include <libusbp.hpp>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

//const uint16_t vendor_id = 0x1a86;
const uint16_t vendor_id = 0x0403;
//const uint16_t product_id = 0x7523;
const uint16_t product_id = 0x6001;
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

    struct termios tty;
    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ECHONL;
    tty.c_lflag &= ~ISIG;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 0;
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }

    while (1) {
        char read_buf [256];
        int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
        if (num_bytes < 0) {
              printf("Error reading: %s", strerror(errno));
              return 1;
        }
        else if (num_bytes == 13)
            printf("Read %i bytes. Received message: %s", num_bytes, read_buf);
    }
    return 0;
}
