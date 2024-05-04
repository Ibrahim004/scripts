#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BST {
    int key;
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
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_BST_node(BST* root)
{
    if(root == NULL)
    {
        return; // nothing to delete
    }
    free_BST_node(root->left);
    free_BST_node(root->right);
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

int findMax(BST* root)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->right == NULL)
    {
        return root->key;
    }
    return findMax(root->right);
}

BST* delete(BST* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->key)
    {
        root->left = delete(root->left, key);
        return root;
    }
    if(key > root->key)
    {
        root->right = delete(root->right, key);
        return root;
    }
    if(root->left == NULL)
    {
        BST* node = root->right;
        free(root);
        return node;
    }
    else if(root->right == NULL)
    {
        BST* node = root->left;
        free(root);
        return node;
    }

    // find successor on left side of root
    BST* parent = root;
    BST* successor = root->left;
    while(successor->right != NULL)
    {
        parent = successor;
        successor = successor->right;
    }

    root->key = successor->key;

    // delete successor node
    if(parent->left == successor)
    {
        parent->left = successor->left;
    }
    else
    {
        parent->right = successor->left;
    }
    free(successor);
    return root;
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

    root = delete(root, 8);
    inOrderTraversal(root);
    printf("\n");

    free_BST_node(root);
    return 0;
}