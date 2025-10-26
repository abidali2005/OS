/*
 * Name: Abid Ali Atif
 * Registration No: 23-NTU-CS-1124
 * Task Title: Task 3 – Number Info Thread
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by the thread
void* numberInfo(void* arg) {
    int num = *(int*)arg;  // Get the number passed from main thread
    int square = num * num;
    int cube = num * num * num;

    printf("Thread: The number is %d\n", num);
    printf("Thread: Square = %d\n", square);
    printf("Thread: Cube = %d\n", cube);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;  // Thread identifier
    int num;

    // Take input from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Create the thread and pass the number
    pthread_create(&thread, NULL, numberInfo, (void*)&num);

    // Wait for thread to complete
    pthread_join(thread, NULL);

    // Message from main thread
    printf("Main thread: Work completed.\n");

    return 0;
}
