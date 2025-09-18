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

void enqueue(int data, struct Node** front, Node** rear) {
    struct Node* newNode=createNode(data);

    if (*front==NULL) {
        *front=newNode;
        *rear=newNode;
        return;
    } 
    (*rear)->next=newNode;
    *rear=newNode;
    // newNode->next=*rear;
    return;
}

int dequeue(struct Node** front, Node** rear) {
    if (*front==NULL) {
        printf("queue is empty\n");
        return -1;
    }
    int x=(*front)->data;
    *front=(*front)->next;
    return x;
}

int peek(struct Node** front, Node** rear) {
    if (*front==NULL) {
        printf("queue is empty.");
        return -1;
    }
    return (*front)->data;
}

int isEmpty(struct Node** front, Node** rear) {
    if (*front==NULL)
        return 1;
    else
        return 0;
} 

int size(struct Node** front, Node** rear) {
    Node* temp=*front;
    int size=0;

    if (temp==NULL)
        return 0;

    while (temp!=*rear) {
        size++;
        temp=temp->next;
    }
    return size+1;
}

int main () {
    Node* front=NULL;
    Node* rear=NULL;

    while (1) {
    printf("\n1. Enqueue\n2. Dequeue\n3. Size\n4. Is Empty\n5. Peek\n6.Exit\n");
    int choice, data;
    scanf("%d", &choice);

    switch (choice){
        case 1:
            printf("\nEnter value to enter: ");
            scanf("%d", &data);
            enqueue(data, &front, &rear);
            break;
        case 2: 
            dequeue(&front, &rear);
            break;
        case 3:
            printf("\nSize is: %d", size(&front, &rear));
            break;
        case 4:
            printf((isEmpty(&front, &rear)==1)?"\nYes queue is empty":"\nNo, queue is not empty.");
            break;
        case 5:
            printf("\nValue at top : %d", peek(&front, &rear));
            break;
        default:
            break;
        }

    }
}