#include "oldest_student.h"
#include <stdio.h>
#include <string.h>

struct Student findOldestStudent(struct Student students[], int numOfStudents) {
    struct Student oldestStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (strcmp(students[i].ate, oldestStudent.ate) < 0) {
            oldestStudent = students[i];
        } else if (strcmp(students[i].ate, oldestStudent.ate) == 0 &&
                strcmp(students[i].thd, oldestStudent.thd) < 0) {
            oldestStudent = students[i];
        } else if (strcmp(students[i].ate, oldestStudent.ate) == 0 &&
                strcmp(students[i].thd, oldestStudent.thd) == 0 &&
                strcmp(students[i].bir, oldestStudent.bir) < 0) {
            oldestStudent = students[i];
        }
    }
    return oldestStudent;
}
