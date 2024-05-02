#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    void* value;
    struct BST* left;
    struct BST* right;
} BST;

BST* create_BST_node(void* value){
    BST* node = (BST*) malloc(sizeof(BST));
    if(node == NULL)
    {
        perror("Could not allocate node");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_BST_node(BST* root, void (*deleteValue)(void*))
{
    if(deleteValue == NULL)
    {
        perror("deleteValue function pointer can't be null");
        exit(EXIT_FAILURE);
    }
    if(root == NULL)
    {
        return; // nothing to delete
    }
    free_BST_node(root->left, deleteValue);
    free_BST_node(root->right, deleteValue);
    deleteValue(root->value);
    free(root);
}

void insert(void* value)
{
    // todo
}

void delete(void* value)
{
    // todo
}

BST* search(BST* root, void* value)
{
    // todo
    return NULL;
}