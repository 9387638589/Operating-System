//Write program to calculate sum of n numbers using thread library.//
#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBERS 100
// Structure to hold arguments for the thread function
struct ThreadArgs {
    int* numbers;
    int start;
    int end;
};

// Function to calculate the sum of numbers in a given range
void* calculateSum(void* arg) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)arg;
    int* numbers = threadArgs->numbers;
    int start = threadArgs->start;
    int end = threadArgs->end;

    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += numbers[i];
    }

    // Return the result through a pointer
    int* result = malloc(sizeof(int));
    *result = sum;
    pthread_exit(result);
}

int main() {
    int n;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid input for n. Please enter a positive value less than or equal to %d.\n", MAX_NUMBERS);
        return 1;
    }

    int numbers[MAX_NUMBERS];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Number of threads (for simplicity, we use two threads here)
    int numThreads = 2;

    // Calculate elements per thread
    int elementsPerThread = n / numThreads;

    // Array to hold thread IDs
    pthread_t threads[numThreads];

    // Array to hold results from threads
    int* threadResults[numThreads];

    // Create and run threads
    for (int i = 0; i < numThreads; i++) {
        struct ThreadArgs* threadArgs = malloc(sizeof(struct ThreadArgs));
        threadArgs->numbers = numbers;
        threadArgs->start = i * elementsPerThread;
        threadArgs->end = (i == numThreads - 1) ? n : (i + 1) * elementsPerThread;

        pthread_create(&threads[i], NULL, calculateSum, (void*)threadArgs);
    }

    // Join threads and accumulate results
    int totalSum = 0;
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], (void**)&threadResults[i]);
        totalSum += *threadResults[i];
        free(threadResults[i]);
    }

    // Display the result
    printf("Sum of %d numbers: %d\n", n, totalSum);

    return 0;
}