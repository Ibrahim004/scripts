#include <stdio.h>
#include <assert.h>
#include <string.h>

void appendTextToFile(char filename[], char* str, int size)
{
    assert(str != NULL && size >= 0);
    assert(strlen(str) == size);
    assert(strlen(filename) != 0);

    FILE* fp = fopen(filename, "a");
    assert(fp != NULL);

    for(int i = 0; i < size && str[i] != '\0'; i++)
    {
        putc(str[i], fp);
    }

    fclose(fp);
}
