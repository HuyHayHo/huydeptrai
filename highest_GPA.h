struct Student findHighestGPA(struct Student students[], int numOfStudents) {
    struct Student highestGPAStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].gpa > highestGPAStudent.gpa) {
            highestGPAStudent = students[i];
        }
    }
    return highestGPAStudent;
}