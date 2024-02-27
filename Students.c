#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int sno;
    char sname[50];
    int marks;
    char grade;
} Student;

char generateGrade(int marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int compareStudents(const void *a, const void *b) {
    return ((Student *)b)->marks - ((Student *)a)->marks;
}

void inputStudentDetails(Student *student, int index) {
    printf("\nEnter details for student %d:\n", index + 1);
    student->sno = index + 1;
    printf("Enter student name: ");
    scanf("%s", student->sname);
    printf("Enter marks: ");
    scanf("%d", &(student->marks));
    student->grade = generateGrade(student->marks);
}

void printStudentDetails(Student *students, int n) {
    printf("\nStudent Records Sorted by Marks (Descending Order):\n");
    printf("%-5s%-15s%-7s%-5s\n", "SNO", "SNAME", "MARKS", "GRADE");
    for (int i = 0; i < n; i++) {
        printf("%-5d%-15s%-7d%-5c\n", students[i].sno, students[i].sname,
               students[i].marks, students[i].grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        inputStudentDetails(&students[i], i);
    }
    qsort(students, n, sizeof(Student), compareStudents);
    printStudentDetails(students, n);
    return 0;
}
