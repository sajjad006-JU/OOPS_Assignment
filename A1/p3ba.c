#include <stdio.h>
#include <stdlib.h>

#define r 3
#define c r

int main () {
    // implementation using pointer to pointers with two malloc.
    int** arr=(int **)malloc(r*sizeof(int *));

    for (int i=0; i<r; i++) {
        int* row=(int *) malloc(c*sizeof(int));
        *(arr+i)=row;

        for (int j=0; j<c; j++) {
            scanf("%d", row+j);
        }
    }

    for (int i=0; i<r; i++) {
        int* row=*(arr+i);

        for (int j=0; j<c; j++) {
            printf("%d ", *(row+j));
        }
        printf("\n");
    }
}