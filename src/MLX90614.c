#include <MLX90614.h>
#include <bcm2835.h>
#include <unistd.h>

static void MLX90614_ReadI2C(uint8_t address, char temperature_address, char* buffer)
{
    bcm2835_init();
    bcm2835_i2c_begin(); 
    bcm2835_i2c_setSlaveAddress(address);
    bcm2835_i2c_write_read_rs(&temperature_address, 1, buffer, 3);
    bcm2835_i2c_end();
    bcm2835_close();

}

float MLX90614_ReadAmbientF(uint8_t address)
{
    return MLX90614_ReadAmbientC(address) * 1.8 + 32;
}

float MLX90614_ReadAmbientC(uint8_t address)
{
    return MLX90614_ReadAmbientK(address) - 273.15;
}

float MLX90614_ReadAmbientK(uint8_t address)
{
    char buffer[3];
    MLX90614_ReadI2C(address, (char)0x06, buffer);
    return ((buffer[1] << 8) + buffer[0]) * 0.02 - 0.01;
}

float MLX90614_ReadObjectF(uint8_t address)
{
    return MLX90614_ReadObjectC(address) * 1.8 + 32;
}

float MLX90614_ReadObjectC(uint8_t address)
{
    return MLX90614_ReadObjectK(address) - 273.15;
}

float MLX90614_ReadObjectK(uint8_t address)
{
    char buffer[3];
    MLX90614_ReadI2C(address, (char)0x07, buffer);
    return ((buffer[1] << 8) + buffer[0]) * 0.02 - 0.01;
}
