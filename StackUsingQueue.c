#include<stdio.h>
#include<stdlib.h>

int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;

void enqueue(int* queue, int size, int data, int* f, int* r) {
    if (*r == size - 1) {
        printf("Queue is full.\n");
    } else {
        if (*f == -1) {
            *f = 0;
        }
        queue[++(*r)] = data;
    }
}
int dequeue(int* queue, int* f, int* r) {
    if (*f == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int data = queue[*f];
        if (*f == *r) {
            *f = *r = -1;
        } else {
            (*f)++;
        }
        return data;
    }
}

void push(int* queue, int size, int data) {
    enqueue(queue, size, data, &f1, &r1);
}

int pop(int* queue1, int* queue2, int size) {
    if (f1 == -1) {
        printf("Stack is empty.\n");
        return -1;
    }

    while (f1 != r1) {
        enqueue(queue2, size, dequeue(queue1, &f1, &r1), &f2, &r2);
    }

    int popped = dequeue(queue1, &f1, &r1);

    while (f2 != -1) {
        enqueue(queue1, size, dequeue(queue2, &f2, &r2), &f1, &r1);
    }

    return popped;
}

void printStack(int* queue, int f, int r) {
    if (f == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d", &n);
    int* arr1 = (int*)malloc(sizeof(int) * n);
    int* arr2 = (int*)malloc(sizeof(int) * n);
    push(arr1, n, 10);
    push(arr1, n, 20);
    push(arr1, n, 30);
    push(arr1, n, 40);
    pop(arr1, arr2, n);
    pop(arr1, arr2, n);
    printStack(arr1, f1, r1);
    free(arr1);
    free(arr2);
}
