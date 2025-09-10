#include <stdio.h>
#include <stdlib.h>

// struct Student* createNode(struct Student* student) {
//     struct Student* newNode=(struct Student *)malloc(sizeof(struct Student));
//     newNode->data=student;
//     newNode->next=NULL;
//     return newNode;
// }

struct Student {
    int roll;
    char* name;
    int score;
    struct Student* next;
};

void addStudent(struct Student** head) {
    printf("enter roll, name, score: ");
    struct Student* student=(struct Student *)malloc(sizeof(struct Student));
    student->name=(char *)malloc(sizeof(char)*50);
    student->next=NULL;

    scanf("%d", &(student->roll));
    scanf("%s", student->name);
    scanf("%d", &(student->score));

    if (*head==NULL) {
        *head=student;
    } else {
        struct Student* temp=*head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=student;
    }
}

void deleteStudent(struct Student** head, int roll) {
    struct Student *p, *cp;

    if ((*head)->roll==roll) {
        p=*head;
        *head=(*head)->next;
        free(p);
    } else {
        cp=(*head)->next;
        p=*head;

        while (cp!=NULL) {
            if (cp->roll==roll) {
                p->next=cp->next;
                free(cp);
                break;
            } else {
                p=cp;
                cp=cp->next;
            }
        }
    }
}

void displayStudents(struct Student* head) {
    printf("\n");
    struct Student* temp=head;
    while (temp!=NULL) {
        printf("%d %s %d \n", temp->roll, temp->name, temp->score);
        temp=temp->next;
    }
    printf("\n");
}

int main () {
    // struct Node* head=createNode(NULL);
    struct Student* head=NULL;
    while (1) {
        printf("1. Add Student \n2. Delete Student\n3. Display Student \n4. Exit\n\n");
        int option, roll;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            addStudent(&head);
            break;    
        case 2:
            printf("enter roll to delete: ");
            scanf("%d", &roll);
            deleteStudent(&head, roll);
            break;
        case 3: 
            displayStudents(head);
            break;
        default:
            exit(EXIT_SUCCESS);
            break;
        }
    }
}