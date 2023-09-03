// binary search using recursion
#include<stdio.h>
#include<stdlib.h>
int binarysearch(int *arr,int start,int end,int target){
    if(start>end){
        return -1;
    }
    else{
        int mid = (start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            return binarysearch(arr,start,mid-1,target);
        }
        else{
            return binarysearch(arr,mid+1,end,target);
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
    int target;
    printf("Enter the target:");
    scanf("%d",&target);
    printf("%d",binarysearch(nums,0,n-1,target));
}
