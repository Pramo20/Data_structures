// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }
// // enqueue operation - insert at end
// void enqueue(struct Node** head, int data) {
//     struct Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//     } else {

//         struct Node* current = *head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
// }
// // dequeue operation - delete at beginning
// void dequeue(struct Node** head){
//     if(*head==NULL){
//        printf("Linked list is empty");
//     }
//     else{
//         struct Node*temp=*head;
//         *head=(*head)->next;
//         free(temp);
//     }
//     }

// // function to find whether queue is empty or full
// void isEmpty(struct Node* head) {
//     if (head == NULL) {
//         printf("Queue is empty\n");
//     } else {
//         printf("Queue is not empty\n");
//     }
// }
// void printqueue(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct Node* head = NULL;
//     enqueue(&head, 10);
//     enqueue(&head, 20);
//     enqueue(&head, 30);
//     enqueue(&head, 40);
//     enqueue(&head,50);
//     printqueue(head);
//     printf("Linked List: ");
//     dequeue(&head);
//     dequeue(&head);
//     dequeue(&head);
//     printqueue(head);
// }

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

// Function to print the elements in the queue
void displayQueue() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("Queue elements: ");
    displayQueue();
    
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Queue elements after dequeue: ");
    displayQueue();
    printf("\nfront= %d",front->data);
    printf("\nrear= %d",rear->data);
}

