#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void build_heap(int **arr, int length) {
    for (int i=1; i<length; i++) {
        int f = i+1;
        while(f > 1 && (*arr)[f/2] < (*arr)[f]) {
            exchange(&((*arr)[f/2]), &((*arr)[f]));
            f /= 2;
        }
    }   
}

void topdown(int **arr, int length) {
    int parent = 1, child = 2, x = (*arr)[1];
    while (child <= length) {
        if (child < length && (*arr)[child] < (*arr)[child+1]) child++;
        if (x >= (*arr)[child]) break;
        (*arr)[parent] = (*arr)[child];
        parent = child; child = 2*parent;
    }
    (*arr)[parent] = x;
}

void heapsort(int **arr, int length) {
    build_heap(arr, length);
    for (int i = length; i >= 2; i--) {
        exchange(&((*arr)[1]), &((*arr)[i]));
        topdown(arr, i-1);
    }
    
}

int main() {
    int *arr, length;

    scanf("%d", &length);

    arr = (int*) malloc (length * sizeof(int));

    for (int i=0; i<length; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t t;
    t = clock();
    heapsort(&arr, length);
    t = clock() - t; 

    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("heapsort() took %f seconds to execute \n", time_taken);

    free(arr);

    return 0;
}