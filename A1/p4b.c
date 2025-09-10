#include <stdio.h>
#include <stdlib.h>

void getDimension(int *n, int* m) {
    printf("Enter the number of rows: \n");
    scanf("%d", n);
    printf("Enter the number of columns: \n");
    scanf("%d", m);
}

int** allocateMemory(int r, int c) {
    int** arr=(int **)malloc(r*sizeof(int *)+r*c*sizeof(int));
    return arr;
}

void acceptValues(int** arr, int r, int c) {
    for (int i=0; i<r; i++) {
        *(arr+i)=(int *)(arr+r+c*i);
        int* row=*(arr+i);

        for (int j=0; j<c; j++) {
            scanf("%d", row+j);
        }
    }
}

void printValues(int** arr, int r, int c) {
    for (int i=0; i<r; i++) {
        int *row =*(arr+i);
        for (int j=0; j<c; j++) {
            printf("%d ", *(row+j));
        }
        printf("\n");
    }
}

int main () {
    int r, c;
    getDimension(&r, &c);
    // int** arr=allocateMemory(r, c);
    int** arr=(int **)malloc(r*sizeof(int *)+r*c*sizeof(int));
    acceptValues(arr, r, c);
    printValues(arr, r, c);
    free(arr);
}