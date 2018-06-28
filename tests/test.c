#include <MLX90614.h>
#include <stdio.h>

int main(void)
{
	float object = 0.0f, ambient = 0.0f;
	while(1)
	{
		object = MLX90614_ReadObjectF(MLX90614_I2CADDRESS);
		ambient = MLX90614_ReadAmbientF(MLX90614_I2CADDRESS);
		printf("OBJECT: %f   AMBIENT: %f\n", object, ambient);
	}
}
