#ifndef DI2C_H
#define DI2C_H

extern "C" {
    #include </usr/include/linux/i2c-dev.h>

   // #include <linux/i2c-dev.h>


//    #include <linux/i2c.h>
}
//#include "smbus.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <iostream>
#include <stdint.h>

namespace DI2C {
    typedef int DI2CRegister;
    typedef int DI2CHandle;
#define DEFAULT_DI2C_OPEN_FLAGS (O_RDWR | O_NOCTTY)
    DI2CHandle openI2CDevice(const char *deviceName, DI2CRegister deviceAddress,
                             int flag = DEFAULT_DI2C_OPEN_FLAGS);
    void DI2CRead(DI2CHandle handle, DI2CRegister reg, uint8_t &data);
    void DI2CWrite(DI2CHandle handle, DI2CRegister reg, uint8_t data);
}

#endif // DI2C_H
