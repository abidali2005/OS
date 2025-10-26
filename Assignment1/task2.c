/*
 * Name: Abid Ali Atif
 * Registration No: 23-NTU-CS-1124
 * Task Title: Task 2 – Personalized Greeting Thread
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by the thread
void* greetingThread(void* arg) {
    char* name = (char*) arg;  // Get the name passed as argument
    printf("Thread says: Hello, %s! Welcome to the world of threads.\n", name);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;  // Thread identifier
    char name[50];

    // Get the user's name
    printf("Enter your name: ");
    scanf("%s", name);

    // Create the thread and pass the name as argument
    printf("Main thread: Waiting for greeting...\n");
    pthread_create(&thread, NULL, greetingThread, (void*)name);

    // Wait for the greeting thread to finish
    pthread_join(thread, NULL);

    // Final message from main thread
    printf("Main thread: Greeting completed.\n");

    return 0;
}
