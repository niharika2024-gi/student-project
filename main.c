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
}

void displayStudents() {
    FILE *f = fopen("students.txt", "r");
    struct Student s;
    while (fscanf(f, "%d %s", &s.roll, s.name) != EOF) {
        printf("Roll: %d\tName: %s\n", s.roll, s.name);
    }
    fclose(f);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
    } while (choice != 0);
    return 0;
}

