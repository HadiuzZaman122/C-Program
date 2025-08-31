#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union Result {
    float cgpa;         // Engineering
    int internship;     // Medical
    char grade;         // Arts
};
struct Student {
    char name[50];
    int rollNo;
    char course[20];
    union Result result;
};
void addStudent(struct Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(struct Student));
    printf("Enter Name: ");
    scanf(" %[^\n]", (*students)[*count].name);
    printf("Enter Roll Number: ");
    scanf("%d", &(*students)[*count].rollNo);
    printf("Enter Course (Engineering/Medical/Arts): ");
    scanf("%s", (*students)[*count].course);
    if (strcmp((*students)[*count].course, "Engineering") == 0) {
        printf("Enter CGPA: ");
        scanf("%f", &(*students)[*count].result.cgpa);
    } 
    else if (strcmp((*students)[*count].course, "Medical") == 0) {
        printf("Enter Internship Hours: ");
        scanf("%d", &(*students)[*count].result.internship);
    } 
    else if (strcmp((*students)[*count].course, "Arts") == 0) {
        printf("Enter Project Grade: ");
        scanf(" %c", &(*students)[*count].result.grade);
    } 
    else {
        printf("Invalid course! Record not added.\n");
        return;
    }
    (*count)++;
    printf("Student added successfully!\n");
}
void displayStudents(struct Student *students, int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Name: %s\nRoll No: %d\nCourse: %s\n", students[i].name,students[i].rollNo,students[i].course);

        if (strcmp(students[i].course, "Engineering") == 0)
            printf("CGPA: %.2f\n", students[i].result.cgpa);
        else if (strcmp(students[i].course, "Medical") == 0)
            printf("Internship Hours: %d\n", students[i].result.internship);
        else if (strcmp(students[i].course, "Arts") == 0)
            printf("Project Grade: %c\n", students[i].result.grade);
        else
            printf("Invalid course data!\n");
    }
}
void searchStudent(struct Student *students, int count) {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\n--- Student Found ---\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Course: %s\n", students[i].course);
            if (strcmp(students[i].course, "Engineering") == 0)
                printf("CGPA: %.2f\n", students[i].result.cgpa);
            else if (strcmp(students[i].course, "Medical") == 0)
                printf("Internship Hours: %d\n", students[i].result.internship);
            else if (strcmp(students[i].course, "Arts") == 0)
                printf("Project Grade: %c\n", students[i].result.grade);
            else
                printf("Invalid course data!\n");
            return;
        }
    }
    printf("No student found with Roll No: %d\n", roll);
}
void updateResult(struct Student *students, int count) {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            if (strcmp(students[i].course, "Engineering") == 0) {
                printf("Enter new CGPA: ");
                scanf("%f", &students[i].result.cgpa);
            } 
            else if (strcmp(students[i].course, "Medical") == 0) {
                printf("Enter new Internship Hours: ");
                scanf("%d", &students[i].result.internship);
            } 
            else if (strcmp(students[i].course, "Arts") == 0) {
                printf("Enter new Project Grade: ");
                scanf(" %c", &students[i].result.grade);
            } 
            else {
                printf("Invalid course type for this student. Update failed!\n");
            }
            printf("Result updated successfully!\n");
            return;
        }
    }
    printf("No student found with Roll No: %d\n", roll);
}

int main() {
    struct Student *students = NULL;
    int count = 0, choice;
    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Search by Roll Number\n");
        printf("4. Update Result\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(&students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: updateResult(students, count); break;
            case 5: free(students); printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
