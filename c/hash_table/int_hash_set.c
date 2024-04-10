#include <stdio.h>
#include <stdlib.h>

#define SET_SIZE 4096

typedef struct HS_Node {
    int key;
    struct HS_Node* next;
} Node;

Node* createNode(int key)
{
    Node* n = (Node*) malloc(sizeof(Node));
    if(n)
    {
        n->key = key;
        n->next = NULL;
    }
    return n;
}


Node** createHashSet(int size)
{
    Node** table = (Node**) calloc(size, sizeof(Node*));
    return table;
}

void freeHashSet(Node** table, int tableSize)
{
    for(int i = 0; i < tableSize; i++)
    {
        Node* n = table[i];
        while(n != NULL)
        {
            Node* temp = n->next;
            free(n);
            n = temp;
        }
    }
    free(table);
}

void add(int key, Node** table, int size)
{
    int index = key % size;
    if(table[index])
    {
        Node* n = table[index];
        while(n->next != NULL && n->key != key)
        {
            n = n->next;
        }
        if(n->key == key)
        {
            return; // key is already in the set
        }
        Node* temp = createNode(key);
        n->next = temp;
    }
    else
    {
        table[index] = createNode(key);
    }
}

int contains(int key, Node** table, int size)
{
    int index = key % size;
    Node* n = table[index];
    while(n != NULL && n->key != key)
    {
        n = n->next;
    }
    return (n != NULL);
}

void delete(int key, Node** table, int size)
{
    if(!contains(key, table, size))
        return; // key is not in the set, nothing to do
    int index = key % size;
    Node* n = table[index];

    if(n && n->key == key)
    {
        table[index] = n->next;
        free(n);
        return;
    }

    while(n->next && n->next->key != key)
    {
        n = n->next;
    }

    if(n->next)
    {
        Node* temp = n->next;
        n->next = n->next->next;
        free(temp);
    }
}

void printHashSet(Node** table, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d: ", i);
        Node* n = table[i];
        while(n != NULL)
        {
            printf("%d->", n->key);
            n = n->next;
        }
        printf("\b\b  \n");
    }
}

void CheckContains(int val, Node** table, int size)
{
    printf("hash set contains %d: %s\n", val, contains(val, table, size) ? "True": "False");
}

void deleteTest(int val, Node** table, int size)
{
    printf("Deleting %d from set\n", val);
    delete(val, table, size);
    CheckContains(val, table, size);
}

int main()
{
    int size = 10;
    Node** table = createHashSet(size);
    add(1, table, size);
    add(11, table, size);
    add(100, table, size);

    // contains tests
    CheckContains(1, table, size);
    CheckContains(11, table, size);
    CheckContains(100, table, size);
    CheckContains(200, table, size);

    // delete tests
    int val = 1;
    deleteTest(1, table, size);
    deleteTest(100, table, size);
    deleteTest(2000, table, size);

    // printHashSet(table, size);
    freeHashSet(table, size);

    return 0;
}