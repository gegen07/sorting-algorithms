#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int **arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int *auxLeft = (int*) malloc (n1 * sizeof(int));
  int *auxRight = (int*) malloc (n2 * sizeof(int));

  for (i = 0; i < n1; i++) auxLeft[i] = (*arr)[l+i];
  for (i = 0; i < n2; i++) auxRight[i] = (*arr)[i+m+1];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (auxLeft[i] <= auxRight[j]) {
      (*arr)[k] = auxLeft[i];
      i++;
    } else {
      (*arr)[k] = auxRight[j];
      j++;
    }
    k++;
  }  

  while (i < n1) {
    (*arr)[k] = auxLeft[i];
    i++;
    k++;
  }

  while (j < n2) {
    (*arr)[k] = auxRight[j];
    j++;
    k++;
  }
}

void mergeSort(int **arr, int l, int r) {
  if (l < r) {
    int m = (l+(r-1))/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
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
  mergeSort(&arr, 0, length-1);
  t = clock() - t; 

  double time_taken = ((double)t) / CLOCKS_PER_SEC;

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("mergeSort() took %f seconds to execute \n", time_taken);

  free(arr);

  return 0;
}