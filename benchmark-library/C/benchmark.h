#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double benchmark(void (*sorting_algorithm)(int** arr, int length), int **arr, int length);

#endif