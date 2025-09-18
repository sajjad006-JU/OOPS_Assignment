#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int isPrime(int n) {
    for (int i=2; i<n; i++) {
        if (n%i==0)
            return 0;
    }
    return 1;
}

int main () {
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    Stack* st=createStack();

    for (int i=x; i>1; i--) {
        if (x%i==0 && isPrime(i))
            push(i, st);
    }

    printf("Prime divisors are: ");
    while (!isEmpty(st)) {
        printf("%d ", top(st));
        pop(st);
    }
}