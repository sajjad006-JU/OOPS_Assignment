#include <stdio.h>
#include <stdlib.h>

// creating a node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// function to create a node
Node* createNode(int data) {
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Stack* createStack() {
    Stack* st=(Stack *)malloc(sizeof(Stack));
    st->top=NULL;
    return st;
}

void push(int data, Stack* st) {
    struct Node* newNode=createNode(data);
    newNode->next=st->top;
    st->top=newNode;
    return;
}

int isEmpty(Stack* st) {
    return st->top==NULL;
}

int top(Stack* st) {
    return (st->top!=NULL)?st->top->data:-1;
}

void pop(Stack* st) {
    if (st->top==NULL) {
        return;
    }
    st->top=st->top->next;
    return;
}
