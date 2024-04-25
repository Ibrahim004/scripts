#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_READABLE_FILE_SIZE 1<<30

long int getFileSize(char fileName[])
{
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        printf("Could not open file: \"%s\"\n", fileName);
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fclose(fp);
    return size;
}

long int readFile(char* buffer, int bufferSize, FILE* file)
{
    assert(buffer != NULL && bufferSize > 0 && file != NULL);
    long int size = fread(buffer, 1, bufferSize, file);
    if(ferror(file))
    {
        printf("Encountered error while reading file!\n");
        return -1;
    }
    return size;
}