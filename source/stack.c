#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For bool, true, false

#define MAX_SIZE 10 // Defining the maximum size of the stack

// Stack structure using an array
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to add an element to the stack
void push(Stack *s, int element) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d onto stack\n", element);
    } else {
        s->top++;
        s->items[s->top] = element;
    }
}

// Function to remove an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element\n");
        return -1; // Return a value that indicates the stack is empty
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Function to get the top element of the stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return a value that indicates the stack is empty
    } else {
        return s->items[s->top];
    }
}

// Main function to demonstrate stack operations
int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element is: %d\n", peek(&myStack));
    printf("Popped %d from stack\n", pop(&myStack));
    printf("Top element is now: %d\n", peek(&myStack));

    return 0;
}
