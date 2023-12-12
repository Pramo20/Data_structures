#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lc;
    struct node* rc;
}*root;

struct node* createNode(int data) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->lc=NULL;
    t->rc=NULL;
    return t;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data <= root->data) {
        root->lc = insert(root->lc, data);
    } else {
        root->rc = insert(root->rc, data);
    }
    return root;
}

//function to search a node
void search(struct node* root,int data){
    if(root==NULL){
        return ;
    }
    while(root->lc!=NULL || root->rc!=NULL){
        struct node *parent =root;
        if(root->data==data){
            return;
        }else if(data<root->data){
            root=root->lc;
        }else{
            root=root->rc;
        }
    }
}


// print inorder
void printInorder(struct node* root){
    if (root == NULL){
        return;
    }
    if(root->lc!=NULL){
        printInorder(root->lc);
    }
    printf("%d ", root->data);
    if(root->rc!=NULL){
        printInorder(root->rc);
    }

}
// find inorder successor
struct node* inorderSuccessor(struct node* cur) 
{  
    cur=cur->rc;
    while(cur->lc != NULL) {  
        cur = cur->lc;  
    }  
    return cur;  
}  
// function to delete a node
struct node* deleteNode(struct node* root, int data) {
    struct node* curr= root;
    struct node* parent = NULL;
    search(curr,data);
    if(curr==NULL){
        return NULL;
    }
    if(curr->lc==NULL && curr->rc==NULL){ // No children
        if(curr!=root){
            if(curr==parent->lc){
                parent->lc=NULL;
            }else{
                parent->rc=NULL;
            }
        }else{
            root=NULL;
        }
        free(curr);
    }
    else if (curr->lc && curr->rc) { // 2 children
    struct node* successor = inorderSuccessor(curr);
    if (successor != NULL) {
        int val = successor->data;
        deleteNode(root, val);
        curr->data = val;
    }
}

    else{ // 1 child
        struct node* child = (curr->lc)? curr->lc: curr->rc;
        if(curr!=root){
            if(curr==parent->lc){
                parent->lc=child;
            }else{
                parent->rc=child;
            }
        }else{
            root=child;
        }
        free(curr);
    }
}

// function to print preorder
void printPreorder(struct node* root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    if(root->lc!=NULL){
        printPreorder(root->lc);
    }
    
    if(root->rc!=NULL){
        printPreorder(root->rc);
    }
}

// print postorder
void printPostorder(struct node* root){
    if (root == NULL){
        return;
    }
    if(root->lc!=NULL){
        printPostorder(root->lc);
    }
    if(root->rc!=NULL){
        printPostorder(root->rc);
    }
    printf("%d ", root->data);

}
// printing the tree level by level
int height(struct node* node) {
    if (node == NULL){
        return 0;
    } 
    int leftHeight = height(node->lc);
    int rightHeight = height(node->rc);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void printGivenLevel(struct node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevel(root->lc, level - 1);
        printGivenLevel(root->rc, level - 1);
    }
}


void printLevelOrder(struct node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("\n");
    }
}
// swap two nodes
void swapnode(struct node* a, struct node* b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;

}

// function to convert a given tree to it's mirror tree
struct node* MirrorTree(struct node* root){
    struct node* curr=root;
    if(root==NULL){
        return root;
    }
    if(curr->lc!=NULL){
        MirrorTree(curr->lc);
    }
    if(curr->rc!=NULL){
        MirrorTree(curr->rc);
    }
    swapnode(curr->lc,curr->rc);    
    return root;

}
// find ancestors, leaf nodes, 
int findAncestors(struct node* root, int target) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        return 1;
    }
    int foundInLeft = findAncestors(root->lc, target);
    int foundInRight = findAncestors(root->rc, target);
    
    if (foundInLeft || foundInRight) {
        printf("%d\t", root->data);
        return 1;
    }
    return 0;
}


// function to print only leaf nodes
void printleaf(struct node* root){
    if(root==NULL){
        return;
    }
    if(root->lc==NULL && root->rc==NULL){
        printf("%d\t",root->data);
    }
    printleaf(root->lc);
    printleaf(root->rc);

}

int main(){
    root=NULL;
    root=insert(root,45);
    root=insert(root,50);
    root=insert(root,15);
    root=insert(root,8);
    root=insert(root,16);
    root=insert(root,49);
    root=insert(root,55);
    printf("\nPreorder traversal of the constructed tree is \n");
    printPreorder(root);
    printf("\nInorder traversal of the constructed tree is \n");
    printInorder(root);
    printf("\nPostorder traversal of the constructed tree is \n");
    printPostorder(root);
    printf("\nLevel order traversal of the constructed tree is \n");
    printLevelOrder(root);
    // printf("\nDeleting 15\n");
    // deleteNode(root,15);
    // printf("\nInorder traversal of the constructed tree(after deleting 15) is \n");
    // printInorder(root);
    //MirrorTree(root);
    // printf("\nInorder traversal of the constructed tree(after mirroring) is \n");   
    // printInorder(root);
    printf("\nAncestors of 55 are: ");
    findAncestors(root,55);
    printf("\nLeaf nodes are: ");
    printleaf(root);



    
}