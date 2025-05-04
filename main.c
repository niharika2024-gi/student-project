#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
};

void addStudent() {
    FILE *f = fopen("students.txt", "a");
    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    fprintf(f, "%d %s\n", s.roll, s.name);
    fclose(f);
    printf("Student added successfully.\n");
}

void displayStudents() {
    FILE *f = fopen("students.txt", "r");
    struct Student s;

    if (f == NULL) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Records:\n");
    while (fscanf(f, "%d %s", &s.roll, s.name) != EOF) {
        printf("Roll No: %d, Name: %s\n", s.roll, s.name);
    }

    fclose(f);
}

void searchStudent() {
    int targetRoll;
    int found = 0;
    struct Student s;
    FILE *f = fopen("students.txt", "r");

    if (f == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &targetRoll);

    while (fscanf(f, "%d %s", &s.roll, s.name) != EOF) {
        if (s.roll == targetRoll) {
            printf("Student Found:\nRoll No: %d\nName: %s\n", s.roll, s.name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", targetRoll);
    }

    fclose(f);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Search Student\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 0);

    return 0;
}

