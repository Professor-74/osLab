#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the buffer size (number of items it can hold)
#define BUFFER_SIZE 5

// Declare the buffer and the count of items in the buffer
int buffer[BUFFER_SIZE];
int count = 0;

// Declare a mutex to synchronize access to the buffer
pthread_mutex_t mutex;

// Producer function that produces items and adds them to the buffer
void* producer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        // Generate a random item to produce
        int item = rand() % 100;

        // Lock the mutex to ensure exclusive access to the buffer
        pthread_mutex_lock(&mutex);
        
        // Wait until there is space in the buffer
        // If the buffer is full (count == BUFFER_SIZE), the producer waits
        while (count == BUFFER_SIZE) {
            // Unlock the mutex before sleeping, to allow the consumer to consume items
            pthread_mutex_unlock(&mutex);  
            sleep(1);  // Simulate the wait for space in the buffer
            pthread_mutex_lock(&mutex);  // Re-lock the mutex after waking up
        }

        // Add the item to the buffer and increase the count
        buffer[count++] = item;
        printf("Produced: %d\n", item);
        
        // Unlock the mutex after modifying the shared buffer
        pthread_mutex_unlock(&mutex);

        // Simulate the time taken to process an item (e.g., production time)
        sleep(1);  
    }
    return NULL;  // End the producer thread
}

// Consumer function that consumes items from the buffer
void* consumer(void* arg) {
    for (int i = 0; i < 10; ++i) {
        // Lock the mutex to ensure exclusive access to the buffer
        pthread_mutex_lock(&mutex);
        
        // Wait until there is something to consume in the buffer
        // If the buffer is empty (count == 0), the consumer waits
        while (count == 0) {
            // Unlock the mutex before sleeping, to allow the producer to produce
            pthread_mutex_unlock(&mutex);  
            sleep(1);  // Simulate the wait for items in the buffer
            pthread_mutex_lock(&mutex);  // Re-lock the mutex after waking up
        }

        // Consume the item from the buffer and decrease the count
        int item = buffer[--count];
        printf("Consumed: %d\n", item);
        
        // Unlock the mutex after modifying the shared buffer
        pthread_mutex_unlock(&mutex);

        // Simulate the time taken to process an item (e.g., consumption time)
        sleep(2);  
    }
    return NULL;  // End the consumer thread
}

int main() {
    pthread_t prod, cons;  // Declare two threads: one for producer and one for consumer

    // Initialize the mutex before using it
    pthread_mutex_init(&mutex, NULL);

    // Create the producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the threads to finish execution
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy the mutex after use to free the resources
    pthread_mutex_destroy(&mutex);

    return 0;  // Return success (exit the program)
}

