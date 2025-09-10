#include <stdio.h>
#include <stdlib.h>

#define N 3

int main () {
    // implementation using pointer to an array.
    int rows, cols;
    printf("enter no of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int (*p)[cols];
    p=malloc(rows*sizeof(*p));

    printf("enter elements: ");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d", &p[i][j]);
        }
    }

    printf("\nOutput:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    free(p);

}