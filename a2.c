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

// function to create a linked list and take user input
Node* createLinkedList() {
    printf("Enter data to add to list : ");
    
    int input;
    Node* head=createNode(0);
    Node* temp=head;

    while (input!=-1) {
        scanf("%d", &input);
        Node* current=createNode(input);
        temp->next=current;
        temp=temp->next;
    }
    head=head->next;
    return head;
}

// function to insert data after a given data in list
void insertAfterGivenData(Node* head, int data, int value) {
    Node* curr=head;
    while (curr->data!=data) {
        curr=curr->next;
    }
    Node* new=createNode(value);
    new->next=curr->next;
    curr->next=new;
    // return head;
}

// function to insert data before a given data in list
void insertBeforeGivenData(Node* head, int data, int value) {
    Node* curr=head;
    Node* next=head->next;

    while (next->data!=data && curr!=NULL && next!=NULL) {
        curr=curr->next;
        next=next->next;
    }
    Node* new=createNode(value);
    new->next=next;
    curr->next=new;
    // return head;
}

// function to delete given data
void deleteGivenData(Node* head, int data) {
    Node* curr=head;
    while (curr->next!=NULL && curr->next->data!=data) {
        curr=curr->next;
    }
    curr->next=curr->next->next;
}

// function to insert data in given position
void insertInPosition(Node* head, int data, int pos) {
    Node* temp=head;
    int curr=0;
    while (curr<pos-1 && temp!=NULL) {
        temp=temp->next;
        curr++;
    }
    Node* new=createNode(data);
    new->next=temp->next;
    temp->next=new;
}

// function to print given linked list
void printList(Node* head) {
    Node* curr=head;
    while (curr->next!=NULL) {
        printf("%d ", curr->data);
        curr=curr->next;
    }
    printf("\n");
}

// function to find the middle value of list
int findMiddle(Node* head) {
    Node* temp=head;
    int size=0;
    while (temp!=NULL) {
        temp=temp->next;
        size++;
    }

    temp=head;
    int c=0;
    while (c<(size/2)-1) {
        temp=temp->next;
        c++;                
    }
    return temp->data;
}

// function to get data from the nth position from the end
int getNthDataFromEnd(Node* head, int n) {
    Node* temp=head;
    int size=0;
    while (temp!=NULL) {
        temp=temp->next;
        size++;
    }
    int p=size-n, c=0;
    temp=head;
    while (c<p-1) {
        temp=temp->next;
        c++;
    }
    return temp->data;
}

int main () {
    Node* head=createLinkedList();    
    
    while (1) {
        printf("1. Insert after data \n2. Insert Before Given Data \n3. Delete Given Data \n4. insert in given position \n5. Find middle of headay\n6. Get nth data from end\n7. Exit\n");
        int input, data, value;
        scanf("%d", &input);

        // menu driven part to accept user choic
        switch (input)
        {
            case 1:
                printf("enter data to insert after: \n");
                scanf("%d", &data);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertAfterGivenData(head, data, value);
                printList(head);
                break;
            case 2: 
                printf("enter data to insert before: \n");
                scanf("%d", &data);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertBeforeGivenData(head, data, value);
                printList(head);
                break;
            case 3:
                printf("enter data to delete: \n");
                scanf("%d", &data);
                deleteGivenData(head, data);
                printList(head);
                break;
            case 4:
                printf("enter position to insert in: \n");
                scanf("%d", &data);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertInPosition(head, value, data);
                printList(head);
                break;
            case 5:
                value=findMiddle(head);
                printf("%d\n", value);
                break;
            case 6:
                printf("enter n: \n");
                scanf("%d", &data);
                int y=getNthDataFromEnd(head, data);
                printf("%d\n", y);
                break;
                
            default:
                break;
        }
    }
}