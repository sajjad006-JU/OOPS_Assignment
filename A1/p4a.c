#include <stdio.h>
#include <stdlib.h>

int getDimension() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    return n;
}

int* allocateMemory(int dimension) {
    return (int *)malloc(dimension*sizeof(int));
}

void acceptValues(int* arr, int dimension) {
    for (int i=0; i<dimension; i++) {
        scanf("%d", arr+i);
    }
}

void printValues(int* arr, int dimension) {
    for (int i=0; i<dimension; i++) {
        printf("%d ", *(arr+i));
    }
}


int main () {
    int n=getDimension();
    int* arr=allocateMemory(n);
    int *p[10];
    hello(&p);
    acceptValues(arr, n);
    printValues(arr, n);
    free(arr);
}