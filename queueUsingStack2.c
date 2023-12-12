#include <stdio.h>
#include <stdlib.h>

int top1 = -1;
int top2 = -1;
int front = -1;
int rear = -1;


void push(int* stack,int** top,int size,int data) {
    if (*top == size - 1) {
        printf("\nOverflow");
    } else {
        ++(*top);
        arr[*top] = data;
    }
}

int pop(int* stack, int size,int** top) {
    if (*top == -1) {
        printf("\nUnderflow");
        return -1; // Return some default value indicating underflow
    } else {
        return arr[(*top)--];
    }
}

void enqueue(int* stack1, int* stack2, int data) {
    while(top1!=-1){
        push(stack2,&top2,size,pop(stack1,&top1));
    }
    push(stack1,&top1,size,data);
    while(top2!=-1){
        push(stack1,&top1,size,pop(stack2,&top2));
    }
    
}

void dequeue(int* stack1, int* stack2) {
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
    enqueue(s1,s2,1);
    enqueue(s1,s2,2);
    enqueue(s1,s2,3);
    enqueue(s1,s2,4);
    enqueue(s1,s2,5);
    dequeue(s1,s2);
    dequeue(s1,s2);
    dequeue(s1,s2);
    display(s1,top1);
    display(s2,top2);
}
