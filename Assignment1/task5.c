/*
 * Name: Abid Ali Atif
 * Registration No: 23-NTU-CS-1124
 * Task Title: Task 5 – Struct-Based Thread Communication
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define Student structure
typedef struct {
    int student_id;
    char name[50];
    float gpa;
} Student;

// Global variable to count Dean's List students
int deanCount = 0;
pthread_mutex_t lock; // Mutex for safe access to shared variable

// Function executed by each thread
void* checkDeanList(void* arg) {
    Student* s = (Student*)arg;

    printf("Thread for Student ID %d:\n", s->student_id);
    printf("Name: %s\n", s->name);
    printf("GPA: %.2f\n", s->gpa);

    // Check Dean's List eligibility
    if (s->gpa >= 3.5) {
        printf("Result: Eligible for Dean's List ✅\n\n");
        pthread_mutex_lock(&lock);
        deanCount++;
        pthread_mutex_unlock(&lock);
    } else {
        printf("Result: Not eligible for Dean's List ❌\n\n");
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    pthread_mutex_init(&lock, NULL);

    // Create three student records
    Student students[3] = {
        {1, "Ali", 3.8},
        {2, "Sara", 3.2},
        {3, "Bilal", 3.6}
    };

    // Create a thread for each student
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, checkDeanList, (void*)&students[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print final count
    printf("Main thread: Total students on Dean's List = %d\n", deanCount);

    pthread_mutex_destroy(&lock);
    return 0;
}
