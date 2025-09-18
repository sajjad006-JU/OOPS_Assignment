#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"

int main () {
    char* str="helloahello";
    int n=strlen(str);
    Queue* q=createQueue();
    int flag=1;

    for (int i=0; i<n/2; i++) {
        enqueue(str[i], q);
    }

    if (n%2!=0) {
        printf("Invalid format!");
        return 0;
    }

    int c=n/2;
    while (!isEmpty(q)) {
        if (dequeue(q) != str[c]) {
            flag=0;
            break;
        }
        c++;
    }

    if (flag)
        printf("Valid format!");
    else
        printf("Invalid format!");
}