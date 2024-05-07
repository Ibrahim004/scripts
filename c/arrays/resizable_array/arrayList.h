#ifndef ARRAY_LIST_HEADER
#define ARRAY_LIST_HEADER 

#define ABSOLUTE_MAX_CAPACITY 1 << 30

typedef struct {
    int* array;
    int size;
    int capacity;
} ArrayList;

ArrayList* newArrayList(int size);
void deleteArrayList(ArrayList* list);
int push_back(ArrayList* list, int x);
void printArraList(ArrayList* list);

#endif