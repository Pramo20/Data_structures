#include<stdio.h>
#include<stdlib.h>
#include "queuelinlist.h"
#include "stack.h"

void BFS(int G[][7], int start,int n){
    int i=start,j; 
    int visited[7]={0};
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty()){
        i=dequeue();
        for(j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

// DFS
void DFS(int G[][7], int start,int n){
    int i=start,j; 
    int visited[7]={0};
    printf("%d ",i);
    visited[i]=1;
    push(i);
    while(!isEmptyS()){
        i=pop();
        for(j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                push(j);
            }
        }
    }
}

// Topological sort
void Topo(int G[][7], int start,int n){
    static int visited[7]={0};
    int j;
    if(visited[start]==0){
        printf("%d ",start);
        visited[start]=1;
        for(j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0){
                Topo(G,j,n);
            }
        }
    }
}



int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    // DAG graph
    int G2[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0}};
    printf("BSF: ");
    BFS(G,4,7);
    printf("\n");
    printf("DSF: ");
    DFS(G,5,7);
    printf("\nTopological sort:");
    Topo(G2,1,7);
    return 0;
}