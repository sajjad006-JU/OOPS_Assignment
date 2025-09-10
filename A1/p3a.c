#include <stdio.h>
#include <stdlib.h>

#define N 3

int main () {
    // implementation using array of pointers.
    int* arr[N];

    for (int i=0; i<N; i++) {
        int* row=(int *) malloc(N*sizeof(int));
        arr[i]=row;

        for (int j=0; j<N; j++) {
            scanf("%d", row+j);
        }
    }

    for (int i=0; i<N; i++) {
        int* row=arr[i];

        for (int j=0; j<N; j++) {
            printf("%d ", *(row+j));
        }
        printf("\n");
    }
}