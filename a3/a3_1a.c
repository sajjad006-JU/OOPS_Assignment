#include <stdio.h>

#define MAX_SIZE 100

void push(int* arr, int data, int* top) {
    if (*top>=MAX_SIZE) {
        printf("stack is full");
        return;
    }

    (*top)++;
    arr[*top]=data;
    return;
}

int pop(int* arr, int* top) {
    if (*top==-1) {
        printf("stack is empty");
        return -1;
    }

    int x=arr[*top];
    (*top)--;
    return x;
}

int main () {
    int stack[MAX_SIZE];

    int top=-1, x;
    while (1) {
        printf("\n1. Push\n2. Pop\n3.Exit\n");
        int choice, data;
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &data);
                push(stack, data, &top);
                break;
            case 2: 
                x=pop(stack, &top);
                printf("\nPop successful! Output is: %d", x);
                break;
            default:
                break;
            }

    }
    return 0;
}