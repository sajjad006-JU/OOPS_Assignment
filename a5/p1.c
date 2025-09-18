#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

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

void dfs(Node* node) {
    if (node==NULL)
        return;
    printf("%d", node->val);
    dfs(node->left);
    dfs(node->right);
    return;
}

int main (int argc, char *argv[]) {    
    FILE *fp;

    if (argc!=2) {
        printf("provide file name");
        return 0;
    }

    fp=fopen(argv[1], "r");

    if (!fp) {
        printf("Invalid file name!");
        return 0;
    }

    int x;

    while (1) {
        fscanf(fp, "%d", &x);
        printf("%d ", x);

        Node* node=createNode(x);
        node->left

        if (x==-1)
            break;
    }
}