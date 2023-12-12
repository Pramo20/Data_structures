#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100


struct TreeNode {
    int data;
    struct TreeNode *lc, *rc;
} *root;

struct TreeNode* CreateTreeNode(int data) {
    struct TreeNode *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->data = data;
    p->lc = p->rc = NULL;
    return p;
}

struct TreeNode* createTree(int x) {
    if (x == -1) {
        return NULL;
    } else {
        struct TreeNode* new = CreateTreeNode(x);
        int leftChild, rightChild;

        printf("Enter the left child of %d: ", x);
        scanf("%d", &leftChild);
        new->lc = createTree(leftChild);

        printf("Enter the right child of %d: ", x);
        scanf("%d", &rightChild);
        new->rc = createTree(rightChild);

        return new;
    }
}

void findPath(struct TreeNode* root,int target,int *path,int var){
    if(root==NULL){
        return;
    }
    path[var] = root->data;
    var++;
    if(root->lc == NULL && root->rc ==NULL){
        int sum=0;
        for(int i=0;i<var;i++){
            sum+=path[i];
        }
        if(sum==target){
            for(int i=0;i<var;i++){
                printf("%d ",path[i]);
            }
            printf("\n");
        }
    }
    findPath(root->lc,target,path,var);
    findPath(root->rc,target,path,var);
    var--;

}

void DisplayPath(int *path,int var){
    for(int i=0;i<var;i++){
        printf("%d ",path[i]);
    }
    printf("\n");

}
int main() {
    int x;
    printf("Enter the root node: ");
    scanf("%d", &x);
    root = createTree(x);
    int target;
    printf("Enter the target sum: ");
    scanf("%d",&target);
    int path[MAX_SIZE];
    int var = 0;
    findPath(root,target,path,var);
    DisplayPath(path ,var);
    return 0;
}