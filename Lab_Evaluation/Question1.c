//Question 1/1
//Write a C program that:
//1.  Defines a structure containing:   Student ID (integer)
  //Student Name (string - max 50 chars)   Marks (float)
  //Grade (char - to be calculated by thread)
//2.  Create an array of 3 student records with sample data
//3.  Create 3 threads, each thread receives one student structure and:   Determines grade based on marks:
 // = 85: Grade A
 
 
  //= 70: Grade B
 
 
  //= 60: Grade C
 
 
  //= 50: Grade D
 
  //< 50: Grade F
  //Prints the student information with the calculated grade
// 4.  Main thread waits for all threads to complete


#include <stdio.h>
#include <pthread.h>

// Define structure to store student details
struct Student {
    int id;           // Student ID
    char name[50];    // Student Name (max 50 characters)
    float marks;      // Marks
    char grade;       // Grade (to be calculated by thread)
};

// Thread function to calculate grade
void* calculateGrade(void* arg) {
    struct Student* s = (struct Student*) arg; // Typecast to Student pointer

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

    // Print student information with calculated grade
    printf("\nStudent ID: %d", s->id);
    printf("\nStudent Name: %s", s->name);
    printf("\nMarks: %.2f", s->marks);
    printf("\nGrade: %c\n", s->grade);

    return NULL; // Thread function must return NULL
}

int main() {
    // Step 1: Create array of 3 student records with sample data
    struct Student students[3] = {
        {1, "Ali Khan", 90.5, ' '},
        {2, "Sara Ahmed", 72.0, ' '},
        {3, "Usman Tariq", 48.5, ' '}
    };

    pthread_t threads[3]; // To store thread IDs

    // Step 2: Create 3 threads, each for one student
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, calculateGrade, (void*)&students[i]);
    }

    // Step 3: Main thread waits for all threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
