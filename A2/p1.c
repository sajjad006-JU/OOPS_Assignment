#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[31];
    int score[5];
    int flag;
};

int search(char* fn, int roll) {
    FILE* fp;
    int k=0;
    struct Student record;

    fp=fopen(fn, "r");

    while (fread(&record, sizeof(struct Student), 1, fp)) {
        k++;

        if (record.roll==roll && record.flag!=0) {
            fclose(fp);
            return k;
        }
    }
    if (feof(fp)) {
        fclose(fp);
        return 0;
    }
}

void addRecord(char* fn) {
    FILE *fp;
    struct Student student;

    fp=fopen(fn, "a");
    printf("enter roll: ");
    scanf("%d", &student.roll);

    if (search(fn, student.roll)) {
        printf("Roll number already exists. \n");
        return;
    }

    printf("enter name: ");
    scanf("%s", student.name);
    printf("enter score in 5 subjects: ");

    for (int i=0; i<5; i++) {
        scanf("%d", &student.score[i]);
    }
    student.flag=1;

    fwrite(&student, sizeof(struct Student), 1, fp);
    fclose(fp);
}

void display(struct Student student) {
    printf("%d %s\nMarks: ", student.roll, student.name);
    int total=0;
    for (int i=0; i<5; i++) {
        total+=student.score[i];
        printf("%d ", student.score[i]);
    }
    printf("\n");
    printf("Total Marks: %d\n", total);
    printf("\n");
}

void displayAll(char* fn) {
    FILE *fp;
    struct Student student;

    fp=fopen(fn, "r");

    while(fread(&student, sizeof(struct Student), 1, fp)!=0) {
        if (student.flag!=0)
            display(student);
    }
    fclose(fp);
}

void displayRecordByRoll(char* fn, int roll) {
    FILE *fp;
    struct Student student;

    fp=fopen(fn, "r");

    while(fread(&student, sizeof(struct Student), 1, fp)!=0) {
        if (student.roll==roll && student.flag!=0)
            display(student);
    }
    fclose(fp);

}

void editRecord(char* fn, int roll) {
    FILE *fp;
    struct Student record;
    int k;
    k=search(fn, roll);

    if (k==0) {
        printf("No such record");
    } else {
        fp=fopen(fn, "r+");

        fseek(fp, (k-1)*sizeof(struct Student), 0);
        fread(&record, sizeof(struct Student), 1, fp);
        fseek(fp, -1*sizeof(struct Student), 1);

        printf("Editing Roll %d, %s's Scores: \n", record.roll, record.name);
        printf("enter the updated scores in all 5 subjects: ");
        for (int i=0; i<5; i++) {
            scanf("%d", &record.score[i]);
        }
        fwrite(&record, sizeof(struct Student), 1, fp);
        fclose(fp);
        printf("Successfully edited. \n");
    }
    return;
}

void deleteRecordLogical(char* fn, int roll) {
    FILE *fp;
    struct Student record;
    int k;
    k=search(fn, roll);

    if (k==0) {
        printf("No such record");
    } else {
        fp=fopen(fn, "r+");

        fseek(fp, (k-1)*sizeof(struct Student), 0);
        fread(&record, sizeof(struct Student), 1, fp);
        fseek(fp, -1*sizeof(struct Student), 1);
        record.flag=0;
        fwrite(&record, sizeof(struct Student), 1, fp);
        fclose(fp);
        printf("Successfully deleted. \n");
    }
    return;
}

int main() {
    char* fn="student";
    
    while (1) {
        printf("1. Add Student \n2. Display All\n3. Search Record \n4. Edit Record\n5. Delete Record\n6. Exit\n");
        int option, roll, k;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            addRecord(fn);
            break;    
        case 2: 
            displayAll(fn);
            break;
        case 3:
            printf("enter roll to search : ");
            scanf("%d", &roll);
            int k=search(fn, roll);
            if (k!=0)
                displayRecordByRoll(fn, k);
            else
                printf("No such student!\n");
            break;
        case 4:
            printf("enter roll to edit : ");
            scanf("%d", &roll);
            editRecord(fn, roll);
            break;
        case 5:
            printf("enter roll to Delete: ");
            scanf("%d", &roll);
            deleteRecordLogical(fn, roll);
            break;
        default:
            exit(EXIT_SUCCESS);
            break;
        }
    }
    addRecord(fn);
    return 0;
}