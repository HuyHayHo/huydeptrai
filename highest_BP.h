struct Student findHighestBP(struct Student students[], int numOfStudents) {
    struct Student highestBPStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].programmingGrade > highestBPStudent.programmingGrade) {
            highestBPStudent = students[i];
        }
    }
    return highestBPStudent;
}