#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For bool, true, false

#define MAX_SIZE 10 // Defining the maximum size of the queue

// Queue structure using an array
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->rear == -1;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// Function to add an element to the queue
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", element);
    } else {
        if (q->front == -1) { // If the queue is initially empty
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE; // Circular increment
        q->items[q->rear] = element;
    }
}

// Function to remove and return the front element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return a value that indicates the queue is empty
    } else {
        int item = q->items[q->front];
        if (q->front == q->rear) { // If the queue becomes empty after dequeuing
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_SIZE; // Circular increment
        }
        return item;
    }
}

// Function to get the front element of the queue without removing it
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // Return a value that indicates the queue is empty
    } else {
        return q->items[q->front];
    }
}

// Main function to demonstrate queue operations
int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front element is: %d\n", peek(&myQueue));
    printf("Dequeued %d from queue\n", dequeue(&myQueue));
    printf("Front element is now: %d\n", peek(&myQueue));

    return 0;
}
