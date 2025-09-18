#include <stdio.h>
#include <stdlib.h>

// creating a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to create a node
Node* createNode(int data) {
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(int data, struct Node** top) {
    struct Node* newNode=createNode(data);
    newNode->next=*top;
    *top=newNode;
    return;
}

int pop(struct Node** top) {
    if (*top==NULL) {
        printf("stack is empty\n");
        return -1;
    }
    int x=(*top)->data;
    *top=(*top)->next;
    return x;
}

int main () {
    Node* top=NULL;
    int x;

    while (1) {
        printf("\n1. Push\n2. Pop\n3.Exit\n");
        int choice, data;
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &data);
                push(data, &top);
                break;
            case 2: 
                x=pop(&top);
                printf("\nPop successful! Popped value: %d ", x);
                break;
            default:
                break;
            }

    }
}