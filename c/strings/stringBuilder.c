#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringBuilder.h"


StringBuilder* newStringBuilder(int capacity)
{
    if(capacity < 1)
    {
        perror("Capacity needs to be at least 1");
        return NULL;
    }
    if(capacity > MAX_STRING_BUILDER_SIZE)
    {
        perror("Request StringBuilder size is larger than max allowed");
        return NULL;
    }
    StringBuilder* sb = (StringBuilder*) malloc(sizeof(StringBuilder));
    if(sb != NULL)
    {
        char* str = (char*) calloc(capacity, sizeof(char));
        if(str == NULL)
        {
            perror("Could not allocate string in memory");
            free(sb);
            return NULL;
        }
        str[0] = '\0';
        sb->array = str;
        sb->capacity = capacity;
        sb->size = 0;
        return sb;
    }
    return NULL;
}

void deleteStringBuilder(StringBuilder* sb)
{
    if(sb != NULL)
    {
        free(sb->array);
        free(sb);
    }
}

int doubleStringBuilderCapacity(StringBuilder* sb)
{
    if(sb == NULL)
    {
        return 0;
    }
    int newCapacity = sb->capacity * 2;
    if(newCapacity < 1 || newCapacity > MAX_STRING_BUILDER_SIZE)
    {
        perror("Could not double string builder capacity.");
        return 0;
    }
    char* newArray = (char*) calloc(newCapacity, sizeof(char));
    if(newArray == NULL)
    {
        return 0;
    }
    strcpy(newArray, sb->array);
    free(sb->array);
    sb->array = newArray;
    sb->capacity = newCapacity;
    return 1;
}

void append(StringBuilder* sb, char c)
{
    if(sb != NULL)
    {
        if(sb->size < sb->capacity -1 || doubleStringBuilderCapacity(sb))
        {
            sb->array[sb->size++] = c;
            sb->array[sb->size] = '\0';
        }
    }
}

void appendString(StringBuilder* sb, char* str, int size)
{
    if(sb == NULL || strlen(str) != size)
    {
        printf("could not append string to stringBuilder\n");
        return;
    }
    for(int i = 0; i < size; i++)
    {
        append(sb, str[i]);
    }
}

void printStringBuilder(StringBuilder * sb)
{
    if(sb != NULL)
    {
        printf("%s\n", sb->array);
    }
}