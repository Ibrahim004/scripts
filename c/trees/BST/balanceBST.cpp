#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

void getSortedArrayFromBST(BST* root, vector<BST*>& nodes)
{
    if(root != NULL)
    {
        getSortedArrayFromBST(root->left, nodes);
        nodes.push_back(root);
        getSortedArrayFromBST(root->right, nodes);
    }
}

BST* getBalancedBST(vector<BST*>& nodes, int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    BST* root = nodes[mid];
    root->left = getBalancedBST(nodes, start, mid-1);
    root->right = getBalancedBST(nodes, mid+1, end);
    return root;
}

int main()
{
    // create unbalanced BST
    BST* root = insert(NULL, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);

    // print unbalanced bst
    cout << "Unbalanced BST: " << endl;
    preOrderPrintTree(root);
    cout << endl;

    // balance the BST
    vector<BST*> nodes;
    getSortedArrayFromBST(root, nodes);
    int n = nodes.size();
    root = getBalancedBST(nodes, 0, n-1);

    // print balanced BST
    cout << "Balanced BST: " << endl;
    preOrderPrintTree(root);
    cout << endl;
}