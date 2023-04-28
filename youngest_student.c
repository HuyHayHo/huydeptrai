struct Student findYoungestStudent(struct Student students[], int numOfStudents) {
    struct Student youngestStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (strcmp(students[i].ate, youngestStudent.ate) > 0) {
            youngestStudent = students[i];
        } else if (strcmp(students[i].ate, youngestStudent.ate) == 0 &&
                strcmp(students[i].thd, youngestStudent.thd) > 0) {
            youngestStudent = students[i];
        } else if (strcmp(students[i].ate, youngestStudent.ate) == 0 &&
                strcmp(students[i].thd, youngestStudent.thd) == 0 &&
                strcmp(students[i].bir, youngestStudent.bir) > 0) {
            youngestStudent = students[i];
        }
    }
    return youngestStudent;
}
