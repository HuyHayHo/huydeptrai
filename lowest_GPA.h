struct Student findLowestGPA(struct Student students[], int numOfStudents) {
    struct Student lowestGPAStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].gpa < lowestGPAStudent.gpa) {
            lowestGPAStudent = students[i];
        }
    }
    return lowestGPAStudent;
}