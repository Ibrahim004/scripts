#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

ArrayList* newArrayList(int size)
{
    if(size > ABSOLUTE_MAX_CAPACITY)
    {
        printf("Requested arrayList size %d is greater than max allowed!\n", size);
        return NULL;
    }
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
    if(list != NULL)
    {
        list->array = (int*) calloc(size, sizeof(int));
        list->capacity = size;
        list->size = 0;
    }
    return list;
}

void deleteArrayList(ArrayList* list)
{
    if(list != NULL)
    {
        free(list->array);
    }
    free(list);
}

int doubleArrayListCapacity(ArrayList* list)
{
    if(list != NULL)
    {
        int newCapacity = list->capacity * 2;
        if(newCapacity > ABSOLUTE_MAX_CAPACITY)
        {
            printf("Can't create array of capacity greater than max allowed!\n");
            return 0;
        }
        int* newArray = (int*) calloc(newCapacity, sizeof(int));
        if(newArray == NULL)
        {
            return 0;
        }

        for(int i = 0; i < list->size; i++)
        {
            newArray[i] = list->array[i];
        }
        
        int* temp = list->array;
        list->array = newArray;
        free(temp);
        
        list->capacity = newCapacity;
        return 1;
    }
    return 0;
}

int push_back(ArrayList* list, int x)
{
    if(list != NULL)
    {
        if(list->size < list->capacity)
        {
            list->array[list->size++] = x;
            return 1;
        }
        else
        {
            if(doubleArrayListCapacity(list) && list->size < list->capacity)
            {
                list->array[list->size++] = x;
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

int getElementAt(ArrayList* list, int index)
{
    if(list == NULL || list->array == NULL || index >= list->size || index < 0)
    {
        return -1;
    }
    return list->array[index];
}

int putElementAt(ArrayList* list, int element, int index)
{
    if(list == NULL || list->array == NULL || index < 0 || index >= list->size)
    {
        return 0;
    }
    list->array[index] = element;
    return 1;
}

void printArraList(ArrayList* list)
{
    if(list != NULL)
    {
        for(int i = 0; i < list->size; i++)
        {
            printf("%d ", getElementAt(list, i));
        }
        printf("\n");
    }
}