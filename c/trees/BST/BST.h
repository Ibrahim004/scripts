#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int key;
    struct BST* left;
    struct BST* right;
} BST;

BST* deleteNode(BST* root, int key);
BST* search(BST* root, int key);

BST* create_BST_node(int key){
    BST* node = (BST*) malloc(sizeof(BST));
    if(node == NULL)
    {
        perror("Could not allocate node");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrderPrintTree(BST* root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrderPrintTree(root->left);
        preOrderPrintTree(root->right);
    }
}

BST* insert(BST* root, int key)
{
    if(root == NULL)
    {
        return create_BST_node(key);
    }
    if(key <= root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}