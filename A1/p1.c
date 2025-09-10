#include <stdio.h>

int main () {
    int x;
    int* p=&x;
    int** pp=&p;

    printf("Enter a number: \n");
    scanf("%d", &x);
    printf("Value of x : %d\n", x);
    printf("Value of p : %d\n", *p);
    printf("Value of pp : %d\n", **pp);
}