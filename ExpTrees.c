#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* lc;
    struct node* rc;
};

struct node* root = NULL;

struct stackNode {
    struct node* data;
    struct stackNode* next;
};

struct stackNode* top = NULL;

struct node* CreateNode(char data) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->lc = NULL;
    t->rc = NULL;
    return t;
}

void push(struct node* x) {
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->data = x;
    newNode->next = NULL;

    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

struct node* pop() {
    if (top == NULL) {
        return NULL;
    } else {
        struct stackNode* temp = top;
        top = top->next;
        struct node* popped = temp->data;
        free(temp);
        return popped;
    }
}

int CheckOp(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/');
}

int CheckOperand(char data) {
    return ((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z'));
}

void Inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->lc);
    printf("%c ", root->data);
    Inorder(root->rc);
}

void convert(char* exp) {
    int i = 0;
    while (exp[i] != '\0') {
        if (CheckOperand(exp[i])) {
            struct node* t = CreateNode(exp[i]);
            push(t);
        } else if (CheckOp(exp[i])) {
            struct node* t = CreateNode(exp[i]);
            t->rc = pop();
            t->lc = pop();
            push(t);
        }
        i++;
    }
    root = pop();
    Inorder(root);
}

int evaluate(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->lc == NULL && root->rc == NULL) {
        return root->data - '0';
    }
    int l = evaluate(root->lc);
    int r = evaluate(root->rc);
    if (root->data == '+') {
        return l + r;
    } else if (root->data == '-') {
        return l - r;
    } else if (root->data == '*') {
        
        return l * r;
    } else if (root->data == '/') {
        return l / r;
    }
}

int main() {
    char exp[50];
    printf("Enter the expression: ");
    scanf("%s", exp);
    convert(exp);
    printf("\n%d\n", evaluate(root));

    return 0;
}
