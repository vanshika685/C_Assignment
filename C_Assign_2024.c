#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    float marks;
    char grade;
    int attempts; // To track the number of attempts
};

void calculateGrade(struct Student *s) {
    if (s->marks >= 90) {
        s->grade = 'A';
    } else if (s->marks >= 80) {
        s->grade = 'B';
    } else if (s->marks >= 70) {
        s->grade = 'C';
    } else if (s->marks >= 60) {
        s->grade = 'D';
    } else {
        s->grade = 'F';
    }
}

void trackEffort(int attempts) {
    if (attempts == 1) {
        printf("Effort Level: Beginner\n");
    } else if (attempts == 2) {
        printf("Effort Level: Intermediate\n");
    } else {
        printf("Effort Level: Advanced\n");
    }
}

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        students[i].attempts = 0; // Initialize attempts count

        char choice;
        do {
            students[i].attempts++; // Increment attempts count
            printf("Attempt %d - Enter Marks: ", students[i].attempts);
            scanf("%f", &students[i].marks);

            calculateGrade(&students[i]);
            trackEffort(students[i].attempts);

            printf("Do you want to update the marks for this student? (y/n): ");
            scanf(" %c", &choice);
        } while (choice == 'y' || choice == 'Y');
    }

    printf("\nStudent Report:\n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("Grade: %c\n", students[i].grade);
        printf("Attempts: %d\n", students[i].attempts);
    }

    return 0;
}