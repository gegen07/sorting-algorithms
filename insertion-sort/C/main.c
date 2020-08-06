#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

  clock_t t;
  t = clock();
  insertionSort(&arr, length);
  t = clock() - t; 

  double time_taken = ((double)t) / CLOCKS_PER_SEC;

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("insertionSort() took %f seconds to execute \n", time_taken);

  free(arr);

  return 0;
}