#include <stdio.h>
#include <stdlib.h>
// Find the average grades of a group of five students in two subjects, mathematics and physics.
// To do this, we will use a two-dimensional array named grades.
// The grades corresponding to mathematics will be stored in the first row (grades[0]),
// while the grades corresponding to physics will be stored in the second row (grades[1]).

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 2

int main() {
    // Variables for storing grades and averages
    int grades[NUM_SUBJECTS][NUM_STUDENTS];
    float subject_averages[NUM_SUBJECTS] = {0};
    float class_average = 0;

    // Get grades for each subject
    for (int subj = 0; subj < NUM_SUBJECTS; subj++) {
        printf("Enter grades for subject %d:\n", subj + 1);

        for (int student = 0; student < NUM_STUDENTS; student++) {
            printf("Student %d: ", student + 1);
            scanf("%d", &grades[subj][student]);
            subject_averages[subj] += grades[subj][student];
        }
    }

    // Calculate subject averages
    for (int subj = 0; subj < NUM_SUBJECTS; subj++) {
        subject_averages[subj] /= NUM_STUDENTS;
    }

    // Calculate class average
    for (int subj = 0; subj < NUM_SUBJECTS; subj++) {
        class_average += subject_averages[subj];
    }
    class_average /= NUM_SUBJECTS;

    // Display results in a super basic way
    printf("\nMath 1 average: %.2f\n", subject_averages[0]);
    printf("Physics 2 average: %.2f\n", subject_averages[1]);
    printf("Class average: %.2f\n", class_average);

    return 0;
}