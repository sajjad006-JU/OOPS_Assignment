#include <stdio.h>

class Node {

    public:
        int data;
        Node* next;

        Node (int val) {
            data=val;
            next=NULL;
        }
};

class LinkedList {
    private:
        Node* head;
    
    public:
        LinkedList() {
            head=NULL;
        }

        void insertAtEnd(int data) {
            // Node newNode(data);
            Node* newNode=new Node(data);
            Node* temp=head;

            if (temp==NULL) {
                head=newNode;
                return;
            }

            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newNode;
            return;
        }

        void printList() {
            Node* temp=head;

            while (temp!=NULL) {
                printf("%d ", temp->data);
                temp=temp->next;
            }
            return;
        }
};

int main () {
    LinkedList ll;
    ll.insertAtEnd(32);
    ll.insertAtEnd(21);
    ll.insertAtEnd(10);
    ll.printList();
}