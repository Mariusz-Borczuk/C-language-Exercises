#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure called Student
struct Student {
    char name[50];
    float grade;
};

// Array of female first names
const char *femaleFirstNames[] = {
    "Anastasia", "Ludmila", "Svetlana", "Tatiana", "Natalia",
    "Olga", "Katarina", "Elena", "Irina", "Yulia",
    "Daria", "Anya", "Oksana", "Zoya", "Milena",
    "Nadezhda", "Vera", "Sofiya", "Marina", "Viktoria"
};

// Array of surnames
const char *surnames[] = {
    "Novak", "Kovačević", "Horvat", "Petrović", "Marković",
    "Pavlov", "Mikhailov", "Nikitin", "Romanov", "Volkov",
    "Sokolov", "Smirnov", "Ivanov", "Fedorov", "Popov",
    "Kuznetsov", "Kozlov", "Stepanov", "Sidorov", "Orlov"
};

// Function to generate a random float between min and max
float getRandomGrade(float min, float max) {
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

// Sorting function for an array of Student structures in descending order of grades
void sortStudents(struct Student *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].grade < array[j + 1].grade) {
                // Swap places
                struct Student temp;
                int k;

                // Copy name manually
                for (k = 0; array[j].name[k] != '\0'; k++) {
                    temp.name[k] = array[j].name[k];
                }
                temp.name[k] = '\0';

                temp.grade = array[j].grade;

                // Copy name manually
                for (k = 0; array[j + 1].name[k] != '\0'; k++) {
                    array[j].name[k] = array[j + 1].name[k];
                }
                array[j].name[k] = '\0';

                array[j].grade = array[j + 1].grade;

                // Copy name manually
                for (k = 0; temp.name[k] != '\0'; k++) {
                    array[j + 1].name[k] = temp.name[k];
                }
                array[j + 1].name[k] = '\0';

                array[j + 1].grade = temp.grade;
            }
        }
    }
}

int main() {
    // Initialization of the array of Student structures with sample data
    struct Student studentList[20];

    // Seed the random number generator
    srand(time(NULL));

    // Generate random grades and assign names
    for (int i = 0; i < 20; i++) {
        // Randomly select a female first name
        const char *firstName = femaleFirstNames[rand() % (sizeof(femaleFirstNames) / sizeof(femaleFirstNames[0]))];

        // Randomly select a surname
        const char *surname = surnames[rand() % (sizeof(surnames) / sizeof(surnames[0]))];

        // Combine the first name and surname to form the full name
        snprintf(studentList[i].name, sizeof(studentList[i].name), "%s %s", firstName, surname);

        // Generate a random grade between 2 and 5
        studentList[i].grade = getRandomGrade(2.0, 5.0);
    }

    int size = sizeof(studentList) / sizeof(studentList[0]);

    // Calling the sorting function
    sortStudents(studentList, size);

    // Printing the sorted list of students along with their grades
    for (int i = 0; i < size; i++) {
        printf("Student: %s, Grade: %.2f\n", studentList[i].name, studentList[i].grade);
    }

    return 0;
}
