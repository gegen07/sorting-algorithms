all: benchmark clear

benchmark: benchmark.o main.o
	gcc benchmark.o main.o -o benchmark

benchmark.o: benchmark.c
	gcc -c benchmark.c -o benchmark.o

main.c: main.c
	gcc -c main.c -o main.o

clear:
	rm *.o