#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int **arr, int length) {
  int change;
  int i;

  do {
    change = 0;

    for (i = 0; i < length-1; i++) {
      if ((*arr)[i] > (*arr)[i+1]) {
        int aux = (*arr)[i];

        (*arr)[i] = (*arr)[i+1];
        (*arr)[i+1] = aux;

        change = 1;
      }
    }
  } while (change);
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
  bubbleSort(&arr, length);
  t = clock() - t; 

  double time_taken = ((double)t) / CLOCKS_PER_SEC;

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("bubble_sort() took %.7lf seconds to execute \n", time_taken);

  free(arr);

  return 0;
}