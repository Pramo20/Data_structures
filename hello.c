/*#include<stdio.h>
int main(){
    printf("hello");
}*/

//bubble sort
/*#include<stdio.h>
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
}*/

// Insertion sort
#include<stdio.h>
#include<stdlib.h>
void insertionsort(int* arr,int size){
    int temp;
    for(int i=1;i<=size-1;i++){
        temp=arr[i];
        for(int j=i-1;j>=0;j--){
            if(temp < arr[j]){
                arr[j+1]=arr[j];
                arr[j]=temp;
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
    insertionsort(nums,n);
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
}