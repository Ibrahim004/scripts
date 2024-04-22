#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "..\math\power.c"


#define INIT_TABLE_SIZE 8192
#define MAX_STRING_LEN 1000000

typedef struct HS_Node {
    long hashCode;
    struct HS_Node* next;
} HS_Node;

typedef struct String_HS {
    int capacity;
    int elementCount;
    HS_Node** table;
} String_HS;

String_HS* createStringHashSet()
{
    String_HS* set = (String_HS*) malloc(sizeof(String_HS));
    set->capacity = INIT_TABLE_SIZE;
    set->table = (HS_Node**) calloc(INIT_TABLE_SIZE, sizeof(HS_Node*));
    set->elementCount = 0;
    return set;
}

HS_Node* createNode(long hashCode)
{
    HS_Node* n = (HS_Node*) malloc(sizeof(HS_Node));
    assert(n != NULL);
    n->hashCode = hashCode;
    n->next = NULL;
    return n;
}

void freeStringHashSet(String_HS* set)
{
    if(set == NULL)
        return;
    for(int i = 0; i < set->capacity; i++)
    {
        HS_Node* n = set->table[i];
        while(n != NULL)
        {
            HS_Node* temp = n;
            n = n->next;
            free(temp);
        }
    }
    free(set->table);
    free(set);
}

long getHashCode(char* str, int size)
{
    assert(size <= MAX_STRING_LEN);
    assert(strlen(str) == size);
    
    long hashCode = 0;
    for(int i = 0; i < size; i++)
    {
        hashCode += str[i] * power(31, size-i-1);
    }
    return hashCode;
}

void add(String_HS* set, char* str, int stringSize)
{
    assert(set != NULL && str != NULL && stringSize >= 0);
    long hashCode = getHashCode(str, stringSize);
    int index =  hashCode % set->capacity;
    HS_Node* n = set->table[index];
    if(n == NULL)
    {
        n = createNode(hashCode);
        set->table[index] = n;
    }
    else
    {
        while(n->next)
        {
            n = n->next;
        }
        HS_Node* newNode = createNode(hashCode);
        n->next = newNode;
    }
    set->elementCount++;
}

int contains(String_HS* set, char* str, int stringSize)
{
    if(set == NULL || str == NULL || stringSize < 0)
    {
        return 0;
    }
    long hashCode = getHashCode(str, stringSize);
    int index = hashCode % set->capacity;
    HS_Node* n = set->table[index];
    while(n != NULL)
    {
        if(n->hashCode == hashCode)
        {
            return 1;
        }
        n = n->next;
    }
    return 0;
}

void delete(String_HS* set, char* str, int stringSize)
{
    assert(set != NULL && str != NULL && stringSize >= 0);
    if(contains(set, str, stringSize))
    {
        HS_Node* n = NULL;
        long hashCode = getHashCode(str, stringSize);
        int index = hashCode % set->capacity;
        n = set->table[index];
        if(n->hashCode == hashCode)
        {
            set->table[index] = n->next; // update head of list
            free(n);
        }
        else {
            while(n->next && n->next->hashCode != hashCode)
            {
                n = n->next;
            }
            HS_Node* temp = n->next;
            if(n->next)
            {
                n->next = n->next->next;
            }
            free(temp);
        }
        set->elementCount--;
        assert(set->elementCount >= 0);
    }
}

int main()
{
    String_HS* hashSet = createStringHashSet();
    char* s = "hello";
    int k = strlen(s);
    add(hashSet, s, k);
    printf("Set contains '%s': %s\n", s, contains(hashSet, s, k) ? "true" : "false");
    delete(hashSet, s, k);
    printf("Set contains '%s': %s\n", s, contains(hashSet, s, k) ? "true" : "false");
    return 0;
}