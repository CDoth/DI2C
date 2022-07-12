#include "DI2C.h"


DI2C::DI2CHandle DI2C::openI2CDevice(const char *deviceName, DI2C::DI2CRegister deviceAddress, int flag) {
    DI2CHandle h = 0;
    h = open(deviceName, flag);
    ioctl(h, I2C_SLAVE, deviceAddress);
    return h;
}
void DI2C::DI2CRead(DI2C::DI2CHandle handle, DI2C::DI2CRegister reg, uint8_t &data) {
    data = i2c_smbus_read_byte_data(handle, reg);
}
void DI2C::DI2CWrite(DI2C::DI2CHandle handle, DI2C::DI2CRegister reg, uint8_t data) {
    i2c_smbus_write_byte_data(handle, reg, data);
}
