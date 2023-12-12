#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
} *root;

struct node* CreateNode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

int getHeight(struct node* n){
    if(n==NULL){
        return -1;
    }
    return n->height;
}

int getBF(struct node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}


struct node* leftRotate(struct node* z){
    struct node* y=z->right;
    struct node* t2=y->left;

    y->left=z;
    z->right=t2;

    z->height=1+max(getHeight(z->left),getHeight(z->right));
    y->height=1+max(getHeight(y->left),getHeight(y->right));

    return y;
}

struct node* rightRotate(struct node* z){
    struct node* y=z->left;
    struct node* t3=y->right;

    y->right=z;
    z->left=t3;

    z->height=1+max(getHeight(z->left),getHeight(z->right));
    y->height=1+max(getHeight(y->left),getHeight(y->right));

    return y;
}

int max(int a,int b){
    a>b ? : return a : return b;
}