#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int top2 = -1;
int front = -1;
int rear = -1;

void push(int* arr, int* top, int size, int data) {
    if (*top == size - 1) {
        printf("\nOverflow");
    } else {
        ++(*top);
        arr[*top] = data;
    }
}

int pop(int* arr, int* top) {
    if (*top == -1) {
        printf("\nUnderflow");
        return -1; // Return some default value indicating underflow
    } else {
        return arr[(*top)--];
    }
}

void enqueue(int* arr, int size, int* stack1, int* stack2, int data) {
    if (front == -1) {
        front++;
    }

    if (rear == size - 1) {
        printf("\nQueue is full");
    } else {
        rear++;
        push(stack1, &top1, size, data);
    }
}

void dequeue(int* arr, int size, int* stack1, int* stack2) {
    if (top2 == -1) {
        while (top1 != -1) {
            int data = pop(stack1, &top1);
            push(stack2, &top2, size, data);
        }
    }

    if (top2 == -1) {
        printf("\nQueue is empty");
    } else {
        pop(stack2, &top2);
        rear--;
    }
}

void display(int* stack, int top) {
    if (top == -1) {
        printf("\nEmpty");
    } else {
        printf("\nThe elements in stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d\t", stack[i]);
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int* que = (int*)malloc(n * sizeof(int));
    int* s1 = (int*)malloc(n * sizeof(int));
    int* s2 = (int*)malloc(n * sizeof(int));

    if (que == NULL || s1 == NULL || s2 == NULL) {
        printf("\nMemory allocation failed. Exiting...");
        exit(EXIT_FAILURE);
    }

    enqueue(que, n, s1, s2, 5);
    enqueue(que, n, s1, s2, 10);
    enqueue(que, n, s1, s2, 15);
    enqueue(que, n, s1, s2, 20);

    printf("\nQueue after enqueuing elements:");
    display(s1, top1);
    display(s2, top2);

    dequeue(que, n, s1, s2);
    dequeue(que, n, s1, s2);

    printf("\nQueue after dequeuing elements:");
    display(s1, top1);
    display(s2, top2);

    free(que);
    free(s1);
    free(s2);

    return 0;
}
