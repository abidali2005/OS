/*
 * Name: Abid Ali Atif
 * Registration No: 23-NTU-CS-1124
 * Task Title: Task 1 – Thread Information Display
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>   // For sleep()

// Function executed by each thread
void* threadFunction(void* arg) {
    int threadNum = *((int*)arg); // Get thread number (1–5)
    printf("Thread %d started. Thread ID: %lu\n", threadNum, pthread_self());

    // Sleep for a random time between 1–3 seconds
    int sleepTime = rand() % 3 + 1;
    sleep(sleepTime);

    printf("Thread %d (ID: %lu) completed after %d seconds.\n", threadNum, pthread_self(), sleepTime);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int threadNums[5];

    srand(time(NULL)); // Seed random number generator

    printf("Creating 5 threads...\n\n");

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        threadNums[i] = i + 1;
        int result = pthread_create(&threads[i], NULL, threadFunction, &threadNums[i]);

        if (result != 0) {
            printf("Error creating thread %d\n", i + 1);
            exit(1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nAll threads have completed execution.\n");

    return 0;
}
