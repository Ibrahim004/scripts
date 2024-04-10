#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList {
    int data;
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* previous;
} Node;

Node* createNode(int data)
{
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;
    return n;
}

void appendToTail(Node* head, int data)
{
    if(head == NULL)
    {
        return;
    }

    Node* n = createNode(data);
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = n;
    n->previous = head;
}

Node* appendToHead(Node* head, int data)
{
    if(head == NULL)
        return NULL;

    Node* n = createNode(data);
    n->next = head;
    head->previous = n;
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
        if(n->next)
        {
            n->next->previous = NULL;
        }
        free(n);
        return temp;
    }

    while(n->next)
    {
        if(n->next->data == data)
        {
            temp = n->next;
            if(n->next->next)
            {
                n->next->next->previous = n;
            }
            n->next = n->next->next;
            free(temp);
            return head;
        }
        n = n->next;
    }
    return NULL;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        printf("%d<->", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n");
}

void freeList(Node* head)
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        free(head);
    }
}

int main()
{
    Node* head = createNode(5);
    appendToTail(head, 4);
    appendToTail(head, 3);
    appendToTail(head, 3);
    appendToTail(head, 2);
    head = deleteNode(head, 3);
    printList(head);

    Node* x = createNode(3);
    x = appendToHead(x, 2);
    x = appendToHead(x, 1);
    printList(x);

    freeList(head);
    freeList(x);
    return 0;
}