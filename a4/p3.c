#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include <string.h>

int evaluatePrefix(char str[50]) {
    int n=strlen(str);
    int total=0;

    Stack* st=createStack();    

    int c=n-1;
    while (c>-1) {
        char ch=str[c];

        // if operand, push to stack
        if ((ch>='0' && ch<='9')) {
            push(ch-'0', st);
        } else {
            int op1=top(st);
            pop(st);
            int op2=top(st);
            pop(st);

            switch (ch) {
            case '+':
                push(op1+op2, st);
                break;
            case '-':
                push(op1-op2, st);
                break;
            case '*':
                push(op1*op2, st);
                break;
            case '/':
                push(op1/op2, st);
                break;
            case '^':
                push(op1^op2, st);
                break;
            default:
                printf("Invalid expression");
                return -1;
            }
        }
        c--;
    }
    return top(st);
}

int main (int argc, char *argv[]) {
    FILE *fp;

    if (argc!=2) {
        printf("provide file name");
        return 0;
    }

    fp=fopen(argv[1], "r");

    if (!fp) {
        printf("Invalid file name!");
        return 0;
    }

    char str[50];
    fscanf(fp, "%s\n", str);
    printf("Result = %d", evaluatePrefix(str));
}