#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* lcl;
    struct node* rcl;
} node;

node* createNode(int info) {
    node* temp = (node*)malloc(sizeof(node));
    temp->info = info;
    temp->lcl = temp->rcl = NULL;
    return temp;
}

node* insert(node* root, int info) {
    if (root == NULL) return createNode(info);
    if (info < root->info)
        root->lcl = insert(root->lcl, info);
    else
        root->rcl = insert(root->rcl, info);
    return root;
}

node* copyTree(node* root) {
    if (root == NULL) return NULL;
    node* temp = createNode(root->info);
    temp->lcl = copyTree(root->lcl);
    temp->rcl = copyTree(root->rcl);
    return temp;
}

void buildTree(node** root) {
    int n, info;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &info);
        *root = insert(*root, info);
    }
}

void printTree(node* root) {
    if (root != NULL) {
        printTree(root->lcl);
        printf("%d ", root->info);
        printTree(root->rcl);
    }
}

int main() {
    node* tree1 = NULL;
    node* tree2 = NULL;

    printf("Build original tree:\n");
    buildTree(&tree1);

    tree2 = copyTree(tree1);

    printf("Original tree: ");
    printTree(tree1);
    printf("\nCopied tree: ");
    printTree(tree2);
    printf("\n");

    return 0;
}
