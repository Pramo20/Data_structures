#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int top2 = -1;

void push(int* stack, int* top, int size, int data) {
    if (*top == size - 1) {
        printf("\nOverflow");
    } else {
        stack[++(*top)] = data;
    }
}

int pop(int* stack, int* top) {
    if (*top == -1) {
        printf("\nUnderflow");
        return -1; // Return some default value indicating underflow
    } else {
        return stack[(*top)--];
    }
}

void enqueue(int* stack1, int* stack2, int size, int data) {
    while (top1 != -1) {
        push(stack2, &top2, size, pop(stack1, &top1));
    }
    push(stack1, &top1, size, data);
    while (top2 != -1) {
        push(stack1, &top1, size, pop(stack2, &top2));
    }
}

void dequeue(int* stack1, int* stack2, int size) {
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
    printf("Enter the size of stacks:");
    int size;
    scanf("%d", &size);
    int* s1 = (int*)malloc(size * sizeof(int));
    int* s2 = (int*)malloc(size * sizeof(int));
    enqueue(s1, s2, size, 1);
    enqueue(s1, s2, size, 2);
    enqueue(s1, s2, size, 3);
    enqueue(s1, s2, size, 4);
    enqueue(s1, s2, size, 5);
    display(s1, top1);
    display(s2, top2);
    dequeue(s1, s2, size);
    dequeue(s1, s2, size);
    dequeue(s1, s2, size);
    display(s1, top1);
    display(s2, top2);

    free(s1);
    free(s2);
}
