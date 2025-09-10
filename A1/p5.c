#include <stdio.h>
#include <stdlib.h>

void displayData(int n, int* ages, char** names) {
    for (int i=0; i<n; i++) {
        printf("%d %s \n", ages[i], names[i]);
    }
}

void sortData(int n, int* ages, char** names) {
    int min, index=0;

    for (int i=0; i<n; i++) {
        min=i;
        for (int j=i+1; j<n; j++) {
            if (ages[j]<ages[min]) {
                min=j;
            }
        }
        int temp=ages[i];
        char* tempName=names[i];
        ages[i]=ages[min];
        ages[min]=temp;
        names[i]=names[min];
        names[min]=tempName;
    }
}

void takeUserInput(int n, int* ages, char** names) {
    printf("enter name and age: \n");
    for (int i=0; i<n; i++) {
        *(names+i)=(char *)malloc(sizeof(char)*50);
        scanf("%s", *(names+i));
        scanf("%d", ages+i);
    }
}

// int** allocateMemory(int n) {
//     int** arr=(int **)malloc(n*sizeof(int)+n*sizeof(char *));
// }

int main () {
    int n;
    printf("Enter the number of people: \n");
    scanf("%d", &n);
    int* ages=(int *)malloc(n*sizeof(int));
    char **names=(char **)malloc(n*sizeof(char *));

    takeUserInput(n, ages, names);
    sortData(n, ages, names);
    displayData(n, ages, names);
    free(names);
    free(ages);
}