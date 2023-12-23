#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lc;
    struct node *rc;
} *root;

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

struct node* create() {
    int x;
    printf("Enter the value : ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    } else {
        struct node* new = createNode(x);
        printf("Enter the left child of %d: ", x);
        new->lc = create();
        printf("Enter the right child of %d: ", x);
        new->rc = create();
        return new;
    }
}


int max(int a, int b){
    return (a>b)?a:b;
}


// function to find maximun path sum
int maxPathSumUtil(struct node *root, int &res){
    // base case
    if(root==NULL){
        return 0;
    }

    // l and r store maximum path sum going through left and right child of root respectively
    int l = maxPathSumUtil(root->lc,res);
    int r = maxPathSumUtil(root->rc,res);

    // max path for parent call of root. This path must include at most one child of root
    int max_single = max(max(l,r)+root->data,root->data);

    // max top represents the sum when the node under consideration is the root of the maxSum path and no ancestor of root are there in max sum path
    int max_top = max(max_single,l+r+root->data);

    res = max(res,max_top);

    return max_single;
}
int main(){
    struct node* root;
    printf("Enter the root node: ");
    root = create();
    printf("Max path sum is %d",maxPathSum(root));


}