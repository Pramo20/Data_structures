
#include <stdio.h>
#include <stdlib.h>


// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to enqueue an element into the queue(insert at end)
void enqueue(int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue an element from the queue(delete at beginning)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);
    return data;
}

