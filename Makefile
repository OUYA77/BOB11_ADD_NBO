#Makefile
all:
	gcc -o add-nbo add-nbo.c
	./add-nbo thousand.bin five-hundred.bin

clean:
	rm -f add-nbo
	rm -f *.o
