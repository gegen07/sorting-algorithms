#include <stdio.h>
#include <stdlib.h>
#include "../../benchmark-library/C/benchmark.h"

void selectionSort(int **arr, int length) {
  int min;
  int i, j;

  for (i = 0; i < length-1; i++) {
    min = i;
    for (j = i+1; j < length; j++) {
      if ((*arr)[j] < (*arr)[min]) {
        min = j;
      }
    }
    int aux = (*arr)[min];
    (*arr)[min] = (*arr)[i];
    (*arr)[i] = aux;
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

  selectionSort(&arr, length);

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  double time_taken = benchmark(selectionSort, &arr, length);
  printf("selectionSort() took %f seconds to execute \n", time_taken);

  free(arr);

  return 0;
}