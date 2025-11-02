#include <stdio.h>
#include <pthread.h>

// Define a structure to store student details
struct Student {
    int id;           // Student ID
    char name[50];    // Student Name (max 50 chars)
    float marks;      // Marks
    char grade;       // Grade (to be calculated by thread)
};

// Thread function to calculate the grade
void* calculateGrade(void* arg) {
    struct Student* s = (struct Student*) arg;  // Typecast to Student pointer

    // Determine grade based on marks
    if (s->marks >= 85)
        s->grade = 'A';
    else if (s->marks >= 70)
        s->grade = 'B';
    else if (s->marks >= 60)
        s->grade = 'C';
    else if (s->marks >= 50)
        s->grade = 'D';
    else
        s->grade = 'F';

    return NULL; // Thread completes its work
}

int main() {
    // Step 1: Create an array of 3 student records with sample data
    struct Student students[3] = {
        {1, "Ali Khan", 90.5, ' '},
        {2, "Sara Ahmed", 72.0, ' '},
        {3, "Usman Tariq", 48.5, ' '}
    };

    pthread_t threads[3]; // Step 2: Declare 3 thread IDs

    // Step 3: Create 3 threads, each handling one student
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, calculateGrade, (void*)&students[i]);
    }

    // Step 4: Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Step 5: After all threads finish, print the results in main
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nStudent ID: %d", students[i].id);
        printf("\nStudent Name: %s", students[i].name);
        printf("\nMarks: %.2f", students[i].marks);
        printf("\nGrade: %c\n", students[i].grade);
    }

    return 0;
}
