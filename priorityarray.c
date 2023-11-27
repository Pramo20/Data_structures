#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct element{
    int value;
    int priority;
};

struct element pr[100000];
int size = -1;

void enqueue(int value, int priority){
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}

int peek(){
    if(size == -1){
        printf("Priority queue is empty\n");
        return INT_MIN;
    }
    int maxPriority = pr[0].priority;
    int index = 0;
    for (int i = 1; i <= size; i++) {
        if (pr[i].priority > maxPriority) {    
            maxPriority = pr[i].priority;
            index = i;
        }
    }
    return index;
}

int dequeue() {
    int index = peek();

    if (index == INT_MIN) {
        return INT_MIN; 
    }

    struct element highestPriority = pr[index];

    for (int i = index; i < size; i++) {
        pr[i] = pr[i + 1];
    }
    size--; 
    return highestPriority.value;
}
void display()
{
    if(size == -1)
    {
        printf("Priority queue is empty\n");
        return;
    }
    for(int i = 0; i <= size; i++)
        printf("%d ", pr[i].value);
    printf("\n");

}

int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 1);
    enqueue(12, 3);
    display();
    while (size >= 0) {
        int highestPriorityValue = dequeue();
        printf("%d\n", highestPriorityValue);
        display();
    }

    return 0;
}
