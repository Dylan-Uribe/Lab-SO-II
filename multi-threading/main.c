#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread function to print the value in reverse order
void* print_reverse(void* arg) {
    int thread_id = *((int*)arg); // Retrieve the thread ID (current value to print)

    if (thread_id > 1) {
        pthread_t next_thread;
        int next_id = thread_id - 1;

        // Create the next thread
        pthread_create(&next_thread, NULL, print_reverse, &next_id);

        // Wait for the next thread to finish (join it)
        pthread_join(next_thread, NULL);
    }

    // Print the current thread ID
    printf("%d\n", thread_id);

    return NULL;
}

int main() {
    int N;

    // Input the value of N
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return -1;
    }

    pthread_t first_thread;
    int first_id = N;

    // Create the first thread which starts the chain of threads
    pthread_create(&first_thread, NULL, print_reverse, &first_id);

    // Wait for the first thread to finish
    pthread_join(first_thread, NULL);

    return 0;
}
