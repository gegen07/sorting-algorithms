#include "benchmark.h"

double benchmark(void (*sorting_algorithm)(int** arr, int length), int **arr, int length) {
  clock_t t;
  
  t = clock();
  sorting_algorithm(arr, length);
  t = clock() - t; 

  return ((double)t)/CLOCKS_PER_SEC;
}
