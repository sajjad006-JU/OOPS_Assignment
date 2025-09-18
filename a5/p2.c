#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* node=(Node *) malloc(sizeof(Node));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inorderTraversal(Node* node) {
    if (node==NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->val);
    inorderTraversal(node->right);
    return;
}

void preorderTraversal(Node* node) {
    if (node==NULL)
        return;

    printf("%d ", node->val);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
    return;
}

void postorderTraversal(Node* node) {
    if (node==NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->val);
    return;
}

int main (int argc, char *argv[]) {
    Node* root=createNode(1);
    Node* node1=root->left=createNode(2);
    Node* node2=root->right=createNode(3);
    node1->left=createNode(5);

    printf("Inorder Traversal = ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre order Traversal = ");
    preorderTraversal(root);
    printf("\n");

    printf("Post order Traversal = ");
    postorderTraversal(root);
    printf("\n");
}