/*#include<stdio.h>
int main(){
    printf("hello");
}*/
Sorting and Search Algorithms
1. Bubble Sort:
//bubble sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a =* b;
    *b = temp;
}
void bsort(int *arr, int size){
    for(int i=size-1 ; i>=1;i--){ //executes n-1 times
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int *nums =(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    bsort(nums,n);
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
}

2.  Insertion Sort:

