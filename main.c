#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "highest_GPA.h"
#include "lowest_GPA.h"
#include "highest_BP.h"
#include "oldest_student.h"
#include "youngest_student.h"
int main() {
    int numOfStudents;
    do
    {
        printf("Enter number of students (maximum 1000): ");
        scanf("%d", &numOfStudents);
    } while (numOfStudents > MAXIMUM_STUDENTS);

    struct Student students[numOfStudents];

    for (int i = 0; i < numOfStudents; i++) {
        printf("Enter information for student %d:\n", i+1);
        printf("Student ID: ");
        scanf("%s", students[i].studentID);
        printf("Last Name: ");
        scanf(" %[^\n]s", students[i].lastName);
        printf("First Name: ");
        scanf(" %[^\n]s", students[i].firstName);
        printf("Birthdate (dd/mm/yyyy) \n"); 
        printf("EX: 21 10 2003: "); 
        scanf("%s", students[i].bir);
        scanf("%s", students[i].thd);
        scanf("%s", students[i].ate);
        printf("Algebra grade: ");
        scanf("%f", &students[i].algebraGrade);
        printf("Calculus grade: ");
        scanf("%f", &students[i].calculusGrade);
        printf("Programming grade: ");
        scanf("%f", &students[i].programmingGrade);

        // calculate GPA
        students[i].gpa = (students[i].algebraGrade + students[i].calculusGrade + students[i].programmingGrade) / 3.0;
    }

    printf("\n");
    printf("-----------------------------------------------------------------------------");
    printf("\n\n");
    //Print the student with highest GPA
    struct Student highestGPAStudent = findHighestGPA(students, numOfStudents);
    printf("Student with highest GPA:\n");
    printf("Name: %s %s\n", highestGPAStudent.firstName, highestGPAStudent.lastName);
    printf("GPA: %.2f\n", highestGPAStudent.gpa);
    printf("\n");

    //Print the student with lowest GPA
    struct Student lowestGPAStudent = findLowestGPA(students, numOfStudents);
    printf("Student with lowest GPA:\n");
    printf("Name: %s %s\n", lowestGPAStudent.firstName, lowestGPAStudent.lastName);
    printf("GPA: %.2f\n", lowestGPAStudent.gpa);
    printf("\n");

    //Print the student with highest BP grade
    struct Student highestBPStudent = findHighestBP(students, numOfStudents);
    printf("Student with highest BP grade:\n");
    printf("Name: %s %s\n", highestBPStudent.firstName, highestBPStudent.lastName);
    printf("Basic Programming grade: %.2f\n", highestBPStudent.programmingGrade);

    //Print the oldest student with ID, full name, and birthdate
    struct Student oldestStudent = findOldestStudent(students, numOfStudents);
    printf("Oldest student:\n");
    printf("ID: %s\n", oldestStudent.studentID);
    printf("Name: %s %s\n", oldestStudent.firstName, oldestStudent.lastName);
    printf("Birthdate: %s/%s/%s\n", oldestStudent.bir, oldestStudent.thd, oldestStudent.ate);
    printf("\n");

    //Print the youngest student
    struct Student youngestStudent = findYoungestStudent(students, numOfStudents);
    printf("Youngest student:\n");
    printf("ID: %s\n", youngestStudent.studentID);
    printf("Name: %s %s\n", youngestStudent.firstName, youngestStudent.lastName);
    printf("Birthdate: %s/%s/%s\n", youngestStudent.bir, youngestStudent.thd, youngestStudent.ate);
    printf("\n");

    // print student list as a table to a text file
    FILE *file = fopen("student_list.txt", "w");
    fprintf(file, "+------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    fprintf(file, "| Student ID |          Full Name         |    Birthdate    | Algebra | Calculus| Basic Programming |   GPA  |\n");
    fprintf(file, "+------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");

    for (int i = 0; i < numOfStudents; i++) {
        fprintf(file, "| %5s   | %-26s |    %1s/%2s/%3s   | %6.2f  | %6.2f  |%12.2f       | %6.2f |\n",
            students[i].studentID,
            strcat(strcat(students[i].lastName, " "), students[i].firstName),
            students[i].bir,
            students[i].thd,
            students[i].ate,
            students[i].algebraGrade,
            students[i].calculusGrade,
            students[i].programmingGrade,
            students[i].gpa);
        fprintf(file, "+------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    }

    fclose(file);

    return 0;
}   