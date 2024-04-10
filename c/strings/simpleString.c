#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ALPHABET_SIZE 26

char* createStringWithRandomCharacters(int size)
{
    char* str = (char *) malloc(sizeof(char) * size + 1);
    for(int i = 0; i < size; i++)
    {
        str[i] = 'a' + (rand() % ALPHABET_SIZE);
    }
    str[size] = '\0';
    return str;
}

void swap(char* str, int i, int j)
{
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
}

void insertionSort(char* str, int n)
{
    int min;
    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        swap(str, i, min);
    }
}