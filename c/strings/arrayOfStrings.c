#include <stdio.h>
#include <stdlib.h>
#include "simpleString.c"

char** createArrayOfRandomStrings(int arraySize, int stringLength)
{
    char** array = (char**) malloc(arraySize * sizeof(char*));
    for(int i = 0; i < arraySize; i++)
    {
        array[i] = createStringWithRandomCharacters(stringLength);
    }
    return array;
}

void printStringsArray(char** array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s\n", array[i]);
    }
}

void freeStringsArray(char** array, int size)
{
    for(int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

int cmpStrings(const void* p, const void* q)
{
    char* s1 = *(char**) p;
    char* s2 = *(char**) q;

    int n = strlen(s1);
    for(int i = 0; i < n; i++)
    {
        if(s1[i] < s2[i])
        {
            return -1;
        }
        else if(s1[i] > s2[i])
        {
            return 1;
        }
    }
    return 0;
}

void sortArray(char** array, int arraySize, int stringLength)
{
    // sort individual strings
    for(int i = 0; i < arraySize; i++)
    {
        insertionSort(array[i], stringLength);
    }
    qsort(array, arraySize, sizeof(char*), cmpStrings);
}

int main()
{
    int arraySize = 3;
    int stringLength = 5;
    char** array = createArrayOfRandomStrings(arraySize, stringLength);
    printStringsArray(array, arraySize);
    printf("Sorted strings:\n");
    sortArray(array, arraySize, stringLength);
    printStringsArray(array, arraySize);
    freeStringsArray(array, arraySize);
    printf("Done!\n");
    return 0;
}