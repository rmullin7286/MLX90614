# MLX90614
A C library for the MLX90614 IR Sensor on Raspberry Pi

## Installation
Simply run the following commands in the root folder and the library will be installed:


    make
    sudo make install


That's all there is to it!

## How to use

This is a simple library and contains only 6 functions in total, all located in the header file 'MLX90614.h'. Each function takes the address of the MLX90614 device as an argument and returns a float value for the temperature specified. The address is 0x5a by default, which is defined in the library as 'MLX90614_I2CADDRESS'.

The six functions to retrieve temperatures are as follows:

    MLX90614_ReadAmbientF()
    MLX90614_ReadAmbientC()
    MLX90614_ReadAmbientK()
    
    MLX90614_ReadObjectF()
    MLX90614_ReadObjectC()
    MLX90614_ReadObjectK()
    
With F, C and K denoting Farenheit, Celsius and Kelvin scales respectively.

## Compiling

Compiling an application with the library is simple. Simply append '-lmlx90614' to the end of your gcc arguments to use the library. Ex:

    gcc main.cpp -lmlx90614
