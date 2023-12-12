#include<stdio.h>
#include<stdlib.h>
int f1=-1,f2=-1;
int r1=-1,r2=-1;

void enqueue1(int* queue1,int size,int data){
    if (r1 == size - 1) {
        printf("Queue1 is full.\n");
    }
    else {
        if (f1 == -1) {
            f1 = 0;
        }
        queue1[++r1] = data;
    }
}

void enqueue2(int*queue2,int size,int data) {
    if (r2 == size - 1) {
        printf("Queue2 is full.\n");
    }
    else {
        if (f2 == -1) {
            f2 = 0;
        }
        queue2[++r2] = data;
    }
}

int dequeue1(int *queue1) {
    if (f1 == -1) {
        printf("Queue1 is empty.\n");
        return -1;
    }
    else {
        int data = queue1[f1];
        if (f1 == r1) {
            f1 = r1 = -1;
        }
        else {
            f1++;
        }
        return data;
    }
}

int dequeue2(int*queue2) {
    if (f2 == -1) {
        printf("Queue2 is empty.\n");
        return -1;
    } else {
        int data = queue2[f2];
        if (f2 == r2) {
            f2 = r2 = -1;
        }
        else {
            f2++;
        }
        return data;
    }
}

void push(int*queue1,int size,int data) {
    enqueue1(queue1,size,data);
}

int pop(queue1,queue2,size) {
    if (f1 == -1) {
        printf("Stack is empty.\n");
        return -1;
    }

    while (f1 != r1) {
        enqueue2(queue2,size,dequeue1(queue1));
    }

    int popped = dequeue1(queue1);

    while (f2 != -1) {
        enqueue1(queue1,size,dequeue2(queue2));
    }

    return popped;
}


void printStack(int*queue1) {
    if (f1 == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = f1; i <= r1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int *arr1=(int*)malloc(sizeof(int)*n);
    int *arr2=(int*)malloc(sizeof(int)*n);
    push(arr1,n,10);
    push(arr1,n,20);
    push(arr1,n,30);
    push(arr1,n,40);
    pop(arr1,arr2,n);
    pop(arr1,arr2,n);
    printStack(arr1);
}
