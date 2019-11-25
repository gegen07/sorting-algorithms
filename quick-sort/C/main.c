#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void partition(int **arr, int l, int r, int *i, int *j) {
  *i = l;
  *j = r;

  int pivo = (*arr)[ (*i + *j)/2 ];

  do {
    while (pivo > (*arr)[*i]) (*i)++;
    while (pivo < (*arr)[*j]) (*j)--;
    
    if (*i <= *j) {
      int aux = (*arr)[*i];
      (*arr)[*i] = (*arr)[*j];
      (*arr)[*j] = aux;

      (*i)++;
      (*j)--;
    }
    
  } while (*i <= *j);
  

}

void quickSort(int **arr, int l, int r) {
  int i, j;
  partition(arr, l, r, &i, &j);
  if (l < j) quickSort(arr, l, j);
  if (i < r) quickSort(arr, i, r);   
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
  quickSort(&arr, 0, length-1);
  t = clock() - t; 

  double time_taken = ((double)t) / CLOCKS_PER_SEC;

  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  printf("quickSort() took %f seconds to execute \n", time_taken);

  free(arr);

  return 0;
}