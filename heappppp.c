#include<stdio.h>
#include<stdlib.h>
// insert in a maxheap
void insertMax(int *heap,int *size,int val){
    if (*size == 0) {
        heap[0] = val;
        *size = 1;
        return;
    }

    int i = *size;
    heap[i] = val;
    (*size)++;

    // Adjust the heap by comparing the new value with its parent
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        // Swap the current node with its parent
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        // Move to the parent level
        i = (i - 1) / 2;
}}

// insert in a minheap
void insertMin(int *heap,int *size,int val){
    if (*size == 0) {
        heap[0] = val;
        *size = 1;
        return;
    }

    int i = *size;
    heap[i] = val;
    (*size)++;

    // Adjust the heap by comparing the new value with its parent
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        // Swap the current node with its parent
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        // Move to the parent level
        i = (i - 1) / 2;
}}

// heapify
void maxheapify(int *heap,int size,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=size && heap[l]>heap[largest]){
        largest=l;
    }
    if(r<=size && heap[r]>heap[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        heapify(heap,size,largest);
    }
}
// min heapify
void minheapify(int *heap,int size,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=size && heap[l]<heap[smallest]){
        smallest=l;
    }
    if(r<=size && heap[r]<heap[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        int temp=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=temp;
        heapify(heap,size,smallest);
    }
}

int main(){
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    int *arr=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        int data;
        printf("\nEnter :");
        scanf("%d",&data);
        insertMax(arr,n,i,data);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        int data;
        printf("\nEnter :");
        scanf("%d",&data);
        insertMin(arr,n,i,data);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

