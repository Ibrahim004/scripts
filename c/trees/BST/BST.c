#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BST.h"

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

BST* deleteNode(BST* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(key > root->key)
    {
        root->right = deleteNode(root->right, key);
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
    root = insert(root, 8);
    insert(root, 1);
    insert(root, 10);
    insert(root, 8);
    insert(root, 5);
    insert(root, 11);
    insert(root, 7);
    inOrderTraversal(root);
    printf("\n");

    BST* result = search(root, 1);
    printf("Got result: %d\n", result->key);

    root = deleteNode(root, 8);
    inOrderTraversal(root);
    printf("\n");

    free_BST_node(root);
    return 0;
}