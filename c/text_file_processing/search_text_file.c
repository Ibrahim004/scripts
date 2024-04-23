#include <stdio.h>
#include <assert.h>

#define MAX_LINE_LENGTH 1024

int readLine(char* str, int size, FILE* fp)
{
    assert(str != NULL && size >= 1 && fp != NULL);
    int i, c;
    for(i = 0; i < size; i++)
    {
        c = fgetc(fp);
        if(c == EOF)
        {
            break;
        }
        str[i] = c;
        if(c == '\n')
        {
            break;
        }
    }
    if(c == EOF)
    {
        str[i] = '\0';
        return i;
    }
    else if(i+1 < size)
    {
        str[i+1] = '\0';
        return i+1;
    }
    str[i] = '\0';
    return i;
}

int checkContainsWord(char* line, int lineSize, char* word, int wordSize)
{
    assert(line != NULL && lineSize >= 0 && word != NULL && wordSize >= 1);
    int index = 0;
    for(int i = 0; i < lineSize; i++)
    {
        if(line[i] == word[index])
        {
            index++;
        }
        else
        {
            index = 0;
        }
        if(index == wordSize)
        {
            return 1;
        }
    }
    return 0;
}

int checkContainsAnyWord(char* line, int lineSize, char** wordsList, int listSize, int* wordSizeList)
{
    assert(line != NULL && lineSize >= 0 && wordsList != NULL && listSize > 0 && wordSizeList != NULL);
    for(int i = 0; i < listSize; i++)
    {
        if(checkContainsWord(line, lineSize, wordsList[i], wordSizeList[i]))
        {
            return 1;
        }
    }
    return 0;
}