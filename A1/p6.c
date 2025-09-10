#include <stdio.h>
#include <stdlib.h>

struct Person {
    int age;
    char* name;
};

void displayData(int n, struct Person** persons) {
   for (int i=0; i<n; i++) {
        printf("%s %d \n", persons[i]->name, persons[i]->age);
    }
}

void takeUserInput(int n, struct Person** persons) {
    printf("enter name and age: \n");
    for (int i=0; i<n; i++) {
        struct Person *person=(struct Person *)malloc(sizeof(struct Person));
        *(persons+i)=person;
        person->name=(char *)malloc(sizeof(char)*50);
        scanf("%s", person->name);
        scanf("%d", &(person->age));
    }
}


void sortData(int n, struct Person** persons) {
    int min, index=0;

    for (int i=0; i<n; i++) {
        min=i;
        for (int j=i+1; j<n; j++) {

            if (persons[j]->age<persons[min]->age) {
                min=j;
            }
        }
        int temp=persons[i]->age;
        char* tempName=persons[i]->name;
        persons[i]->age=persons[min]->age;
        persons[min]->age=temp;
        persons[i]->name=persons[min]->name;
        persons[min]->name=tempName;
    }
}

struct Person** allocateMemory(int n) {
    return (struct Person **)malloc(n*sizeof(struct Person *));
} 

int main () {
    int n;
    printf("Enter the number of people: \n");
    scanf("%d", &n);
    struct Person **persons=allocateMemory(n); 
    takeUserInput(n, persons);
    sortData(n, persons);
    displayData(n, persons);
    free(persons);
    return 0;
}