#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
} *root;

int NodeHeight(struct node* p){
    int hl,hr;
    hl=p && p->left? p->left->height:0;
    hr=p && p->right? p->right->height:0;
    return hl>hr? hl+1:hr+1;
}

int BalanceFactor(struct node* p){
    int hl,hr;
    hl=p && p->left? p->left->height:0;
    hr=p && p->right? p->right->height:0;
    return hl-hr;
}
//LL
struct node* LLRotation(struct node* p){
    struct node* pl=p->left;
    struct node* plr=pl->right;
    
    pl->right=p;
    p->left=plr;
    
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    
    if(root==p){
        root=pl;
    }
    return pl;
}
//RR
struct node* RRRotation(struct node* p){
    struct node* pr=p->right;
    struct node* prl=pr->left;
    
    pr->left=p;
    p->right=prl;
    
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    
    if(root==p){
        root=pr;
    }
    return pr;
}
//LR
struct node* LRRotation(struct node* p){
    struct node* pl=p->left;
    struct node* plr=pl->right;
    
    pl->right=plr->left;
    p->left=plr->right;
    
    plr->left=pl;
    plr->right=p;
    
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    
    if(root==p){
        root=plr;
    }
    return plr;
}
//RL
struct node* RLRotation(struct node* p){
    struct node* pr=p->right;
    struct node* prl=pr->left;
    
    pr->left=prl->right;
    p->right=prl->left;
    
    prl->right=pr;
    prl->left=p;
    
    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);
    
    if(root==p){
        root=prl;
    }
    return prl;
}


struct node* Insert(struct node* p, int data){
    struct node* t=NULL;
    if(p==NULL){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=data;
        t->left=NULL;
        t->right=NULL;
        t->height=1;
        return t;
        
    }
    if(data< p->data){
        p->left=Insert(p->left,data);
    }else if(data > p->data){
        p->right=Insert(p->right,data);
    }
    p->height=NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
        return RLRotation(p);
        }
    return p;
}

// diplay
void Inorder(struct node* p){
    if(p){
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}
// function to delete a node
struct node* Delete(struct node* p,int key){
    struct node* q;
    if(p==NULL){
        return NULL;
    }
    if(p->left==NULL && p->right==NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data){
        p->left=Delete(p->left,key);
    }else if(key > p->data){
        p->right=Delete(p->right,key);
    }else{
        if(NodeHeight(p->left)>NodeHeight(p->right)){
            q=InPre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }else{
            q=InSucc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,q->data);
        }
    }
    p->height=NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
        return RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
        return RLRotation(p);
        }
    return p;
}
int main(){
    root=Insert(root,10);
    Insert(root,5);
    Insert(root,2);
    Inorder(root);
}