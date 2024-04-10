#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} Node;

Node* createNode(int data)
{
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void appendToTail(Node* head, int data)
{
    if(head == NULL)
    {
        printf("Error: head cannot be null!");
        return;
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = createNode(data);
}

Node* prependToHead(Node* head, int data)
{
    Node* n = createNode(data);
    n->next = head;
    return n;
}

Node* deleteNode(Node* head, int data)
{
    if(head == NULL)
        return NULL;
    
    Node* n = head;
    Node* temp;
    if(n->data == data)
    {
        temp = n->next;
        free(n);
        return temp;
    }

    while(n->next != NULL)
    {
        if(n->next->data == data)
        {
            temp = n->next;
            n->next = n->next->next;
            free(temp);
            return head;
        }
        n = n->next;
    }
    return head;
}

Node* getNodeWithValue(Node* head, int value)
{
    while(head != NULL)
    {
        if(head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\b\b  \n");
}

void freeList(Node* head)
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node* n = createNode(5);
    appendToTail(n, 2);
    appendToTail(n, 7);
    appendToTail(n, 8);
    appendToTail(n, 9);
    printList(n);
    n = deleteNode(n, 8); // delete node with value 8
    printList(n);


    Node* x = createNode(3);
    x = prependToHead(x, 2);
    x = prependToHead(x, 1);
    printList(x);

    Node* node2 = getNodeWithValue(x, 2);
    printf("Got node with value: %d, and next: %p\n", node2->data, node2->next);

    freeList(n);
    freeList(x);
    return 0;
}