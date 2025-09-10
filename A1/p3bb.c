#include <stdio.h>
#include <stdlib.h>

#define r 3
#define c 3

int main () {
    // implementation using pointer to pointers with one malloc.
    int** arr=(int **)malloc(r*sizeof(int *)+r*c*sizeof(int));

    for (int i=0; i<r; i++) {
        *(arr+i)=(int *)(arr+r+c*i);
        int *row =*(arr+i);

        for (int j=0; j<c; j++) {
            scanf("%d", row+j);
        }
    }

    for (int i=0; i<r; i++) {
        int *row =*(arr+i);
        for (int j=0; j<c; j++) {
            printf("%d ", *(row+j));
        }
        printf("\n");
    }
}