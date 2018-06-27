CFLAGS = -shared -Wl,-rpath .
LDFLAGS = -L./thirdparty/bcm2835-1.56/ -lbcm2835
INCLUDES = -I./include -I./thirdparty/bcm2835-1.56/src

libmlx90614.so: MLX90614.o

MLX90614.o: ./src/MLX90614.c ./include/MLX90614.h libbcm2835.so*
	$(CC) $(CFLAGS) -o $@ $< $(INCLUDES) $(LDFLAGS)

libbcm2835.so*:
	@cd ./thirdparty/bcm2835-1.56 && ./configure && $(MAKE)
	@cp ./thirdparty/bcm2835-1.56/libbcm2835.so* .

install: libmlx90614.so
	$(MAKE) -C thirdparty/bcm2835-1.56 install
	install -m 0755 ./include/MLX90614.h /usr/local/include/
	install -m 0755 libmlx90614.so /usr/local/lib/
.PHONY: install

clean:
	$(MAKE) -C ./thirdparty/bcm2835-1.56 clean
	rm -f *.so
	rm -f *.o
.PHONY: clean

dist-clean: clean
	$(MAKE) -C ./thirdparty/bcm2835-1.56 dist-clean
	rm -f /usr/local/lib/libmlx90614.so
	rm -f /usr/local/include/MLX90614.h
.PHONY: dist-clean