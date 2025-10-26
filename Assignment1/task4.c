/*
 * Name: Abid Ali Atif
 * Registration No: 23-NTU-CS-1124
 * Task Title: Task 4 – Thread Return Values (Factorial)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by the thread
void* factorialThread(void* arg) {
    int n = *(int*)arg;
    long long* result = (long long*)malloc(sizeof(long long));  // Allocate memory for result
    *result = 1;

    for (int i = 1; i <= n; i++) {
        *result *= i;
    }

    pthread_exit((void*)result);  // Return result pointer
}

int main() {
    pthread_t thread;   // Thread identifier
    int num;
    long long* factorialResult;  // Pointer to receive the returned value

    // Take input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Create the thread to compute factorial
    pthread_create(&thread, NULL, factorialThread, (void*)&num);

    // Wait for thread to complete and get the result
    pthread_join(thread, (void**)&factorialResult);

    // Print the result
    printf("Factorial of %d = %lld\n", num, *factorialResult);
    printf("Main thread: Computation completed.\n");

    // Free allocated memory
    free(factorialResult);

    return 0;
}
