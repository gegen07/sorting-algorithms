all: main clear

main: benchmark.o main.o
	gcc benchmark.o main.o -o main

benchmark.o: ../../benchmark-library/C/benchmark.c
	gcc -c ../../benchmark-library/C/benchmark.c -o benchmark.o

main.c: main.c
	gcc -c main.c -o main.o

clear:
	rm *.o