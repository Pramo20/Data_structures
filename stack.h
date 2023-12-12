#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stack[100];

#define MAX_SIZE 100
void push(int data){
    if(top==MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=data;
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek(){
    if(top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top];
}

int isEmptyS(){
    return top==-1;
}