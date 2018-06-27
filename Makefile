INCLUDES = -I./include

libmlx90614.a: MLX90614.o bcm2835.o
	ar rcs $@ $^

MLX90614.o: ./src/MLX90614.c ./include/MLX90614.h
	$(CC) $(INCLUDES) -c -o $@ $<

bcm2835.o: ./src/bcm2835.c ./include/bcm2835.h
	$(CC) $(INCLUDES) -c -o $@ $<

install: libmlx90614.a
	install -m 0755 ./include/*.h /usr/local/include/
	install -m 0755 libmlx90614.a /usr/local/lib/
