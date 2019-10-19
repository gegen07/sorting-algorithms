#include <stdio.h>
#include <stdlib.h>
#include "../../benchmark-library/C/benchmark.h"

void insertionSort(int **arr, int length) {
  int element;
  int i, j;

  for (i = 1; i < length; i++) {
    element = (*arr)[i];
    j = i-1;

    while (j >= 0 && (*arr)[j] > element) {
      (*arr)[j+1] = (*arr)[j];
      j--;
    }

    if (j != i-1) {
      (*arr)[j+1] = element;
    }
  } 
}

int main() {
  int *arr;
  int length;

  scanf("%d", &length);
  arr = (int*) malloc(length * sizeof(int));

  int i;
  for (i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }

  insertionSort(&arr, length);

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  double time_taken = benchmark(insertionSort, &arr, length);
  printf("insertionSort() took %f seconds to execute \n", time_taken);

  free(arr);

  return 0;
}