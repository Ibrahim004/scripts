#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct HM_Node {
    int key;
    int value;
    struct HM_Node* next;
} Node;

Node** createHashMap(int size)
{
    Node** map = (Node**) calloc(size, sizeof(Node*));
    return map;
}

void freeHashMap(Node** map, int size)
{
    for(int i = 0; i < size; i++)
    {
        Node* n = map[i];
        while(n)
        {
            Node* temp = n->next;
            free(n);
            n = temp;
        }
    }
    free(map);
}

int add(Node** map, int key, int value, int mapSize)
{
    int index = key % mapSize;
    Node* n = map[index];
    if(n)
    {
        while(n->key != key && n->next != NULL)
        {
            n = n->next;
        }
        if(n->key == key)
        {
            // update value
            n->value = value;
            return 1;
        }
        Node* temp = (Node*) malloc(sizeof(Node));
        if(temp == NULL)
        {
            return 0; // could not allocate new node into memory
        }
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        n->next = temp;
        return 1;
    }
    else
    {
        n = (Node*) malloc(sizeof(Node));
        if(n == NULL)
        {
            return 0; // we could not allocate new node into memory
        }
        n->key = key;
        n->value = value;
        n->next = NULL;
        map[index] = n;
        return 1;
    }
}

int find(Node** map, int mapSize, int key)
{
    int index = key % mapSize;
    Node* n = map[index];
    while(n && n->key != key)
    {
        n = n->next;
    }
    if(n == NULL)
        return INT_MIN; // could not find item in the map
    return n->value;
}

int contains(Node** map, int mapSize, int key)
{
    int value = find(map, mapSize, key);
    return (value != INT_MIN);
}

void delete(Node** map, int mapSize, int key)
{
    if(!contains(map, mapSize, key))
        return; // item is not in the map, nothing to do
    int index = key % mapSize;
    Node* n = map[index];
    if(n && n->key == key)
    {
        map[index] = n->next;
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

int main()
{
    int mapSize = 1024;
    Node** map = createHashMap(mapSize);
    add(map, 1, 100, mapSize);
    add(map, 1025, 100, mapSize);
    add(map, 100, 10, mapSize);
    freeHashMap(map, mapSize);

    return 0;
}