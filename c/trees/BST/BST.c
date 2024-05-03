#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BST {
    int key;
    void* value;
    struct BST* left;
    struct BST* right;
} BST;

BST* create_BST_node(int key, void* value){
    BST* node = (BST*) malloc(sizeof(BST));
    if(node == NULL)
    {
        perror("Could not allocate node");
        exit(EXIT_FAILURE);
    }
    node->key = key;
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

BST* insert(BST* root, int key, void* value)
{
    if(root == NULL)
    {
        return create_BST_node(key, value);
    }
    if(key <= root->key)
    {
        root->left = insert(root->left, key, value);
    }
    else
    {
        root->right = insert(root->right, key, value);
    }
    return root;
}

void delete(BST* root, int key)
{
    // todo
}

BST* search(BST* root, int key)
{
    if(root == NULL || root->key == key)
    {
        return root;
    }
    else if(key <= root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inOrderTraversal(BST* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main()
{
    BST* root = NULL;
    root = insert(root, 8, NULL);
    insert(root, 1, NULL);
    insert(root, 10, NULL);
    insert(root, 8, NULL);
    insert(root, 5, NULL);
    insert(root, 11, NULL);
    insert(root, 7, NULL);
    inOrderTraversal(root);
    printf("\n");

    BST* result = search(root, 1);
    printf("Got result: %d\n", result->key);

    free_BST_node(root, free);
    return 0;
}