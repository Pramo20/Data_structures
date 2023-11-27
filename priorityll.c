#include <stdio.h>
#include <stdlib.h>

struct Node {       
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

void insert(int item, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->priority = priority;
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int delete() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int item = temp->data;
    front = front->next;
    free(temp);
    return item;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(5, 2);
    insert(3, 1);
    insert(7, 3);
    insert(1, 1);
    display();
    printf("Deleted item: %d\n", delete());
    printf("Deleted item: %d\n", delete());
    display();
    return 0;
}
