// implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*top;

struct node* createNode(int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

void display(struct node* top){
    struct node* temp= top;
    if(top==NULL){
        printf("\nStack is empty");
    }
    else{
        printf("\nThe stack contains the following elements: " );
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
// insert at beginning
void push(int x){
    struct node* new= createNode(x);
    new->next=top;
    top=new;
    printf("\nPushed Succesfully\n");
}
// delete at beginning
struct node* pop(){
    if(top==NULL){
        printf("\nUnderflow");
    }else{
        struct node* temp=top;
        top=top->next;
        free(temp);
        printf("\nPopped Succesfully\n");
        return top;
    }
}

void peek(){
    if(top==NULL){
        printf("The stack is empty");
    }else{
        printf("\nThe top element is %d\n",top->data);
    }
}
int main(){
    //struct node* top=NULL;
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    pop();
    display(top);
    pop();
    peek();
    push(9);
    pop();
    pop();
    peek();
    display(top);
    
}