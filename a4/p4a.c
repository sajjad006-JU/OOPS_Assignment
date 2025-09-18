#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"

int main () {
    char* str="bcse#bcse";
    int n=strlen(str);
    Queue* q=createQueue();
    int flag=1;

    int c=0;
    while (str[c]!='#') {
        enqueue(str[c++], q);
    }

    if (n%2!=1 || (n-1)/2!=c) {
        printf("invalid format");
        return 0;
    }

    c+=1;

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