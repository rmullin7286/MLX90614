#pragma once
#include <stdint.h>

#define MLX90614_I2CADDRESS 0x5A

float MLX90614_ReadAmbientF(uint8_t address);
float MLX90614_ReadAmbientC(uint8_t address);
float MLX90614_ReadAmbientK(uint8_t address);

float MLX90614_ReadObjectF(uint8_t address);
float MLX90614_ReadObjectC(uint8_t address);
float MLX90614_ReadObjectK(uint8_t address);
