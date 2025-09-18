#include <stdio.h>
#include <stdlib.h>

int insertData(int* arr, int value) {
    int pos=0;
    while (arr[pos]!=0) {
        pos++;
    }
    arr[pos]=value;
    pos++;
    arr[pos]=0;
}
void shiftFromRight(int* arr, int pos) {
    int end=pos;

    while(arr[end]!=0) {
        end++;
    }
    for (int i=end+1; i>pos; i--) {
        arr[i]=arr[i-1];
    }
}

void insertBeforeGivenData(int* arr, int data, int value) {
    int pos=0;
    while (arr[pos]!=0 && arr[pos]!=data) {
        pos++;
    }
    
    if (arr[pos]==0)
        return;
    shiftFromRight(arr, pos);
    arr[pos]=value;
}

void insertAfterGivenData(int* arr, int data, int value) {
    int pos=0;
    while (arr[pos]!=0 && arr[pos]!=data) {
        pos++;
    }
    
    if (arr[pos]==0)
        return;
    shiftFromRight(arr, pos);
    arr[pos]=value;
}

void insertInPosition(int* arr, int data, int pos) {
    int prev=data;
    while (prev!=0) {
        int x=arr[pos];
        arr[pos]=prev;
        prev=x;
        pos++;
    }
}

int findMiddle(int* arr) {
    int pos=0;
    while (arr[pos]!=0) {
        pos++;
    }
    return arr[pos/2];
}

void deleteGivenData(int* arr, int data) {
    int pos=0;

    while (arr[pos]!=data) {
        pos++;    
    }

    int next=arr[pos+1];
    while (next!=0) {
        next=arr[pos+1];
        arr[pos]=next;
        pos++;
    }
}

void printArray(int* arr) {
    int c=0;
    while (arr[c]!=0) {
        printf("%d ", arr[c]);
        c++;
    }    
    printf("\n");
}

int getNthDataFromEnd(int *arr, int n) {
    int pos=0;
    while (arr[pos]!=0) {
        pos++;
    }
    return arr[pos-n];
}

int main() {
    int arr[100];
    int pos=0;

    printf("enter numbers terminated by 0: ");
    int input=-1;
    while (input!=0) {
        scanf("%d", &input);
        arr[pos++]=input;
    }

    while (1) {
        printf("1. Insert after data \t 2. Insert Before Given Data \t 3. Delete Given Data \t 4. insert in given position \t 5. Find middle of array\t 6. Get nth data from end\t 7. Exit\n");
        int input, data, value;
        scanf("%d", &input);

        switch (input)
        {
            case 1:
                printf("enter data to insert after: \n");
                scanf("%d", &data);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertAfterGivenData(arr, data, value);
                printArray(arr);
                break;
            case 2: 
                printf("enter data to insert before: \n");
                scanf("%d", &data);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertBeforeGivenData(arr, data, value);
                printArray(arr);
                break;
            case 3:
                printf("enter data to delete: \n");
                scanf("%d", &data);
                deleteGivenData(arr, data);
                printArray(arr);
                break;
            case 4:
                printf("enter position to insert in: \n");
                scanf("%d", &pos);
                printf("enter data to insert: \n");
                scanf("%d", &value);
                insertInPosition(arr, value, pos);
                printArray(arr);
                break;
            case 5:
                value=findMiddle(arr);
                printf("%d\n", value);
                break;
            case 6:
                printf("enter n: \n");
                scanf("%d", &pos);
                int y=getNthDataFromEnd(arr, pos);
                printf("%d\n", y);
                break;
                
            default:
                break;
        }
    }
    // printArray(arr);
    // insertAfterGivenData(arr, 3, 67);
    // printArray(arr);

    // printArray(arr);
    // insertData(arr, 98);
    // printArray(arr);
    // insertBeforeGivenData(arr, 3, 90);
    // printArray(arr);
    // deleteGivenData(arr, 4);
    // printArray(arr);
    // insertInPosition(arr, 34, 2);
    // printArray(arr);
    // int x=findMiddle(arr);
    // printf("%d\n", x);
    // x=getNthDataFromEnd(arr, 3);
    // printf("%d\n", x);
}