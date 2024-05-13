#include <stdio.h>
#include "stringBuilder.h"

int main()
{
    StringBuilder* sb = newStringBuilder(1);
    // printf("sb: %p, sb array: %p, capacity: %d, size: %d\n", sb, sb->array, sb->capacity, sb->size);
    append(sb, 'h');
    append(sb, 'e');
    append(sb, 'l');
    append(sb, 'l');
    append(sb, 'o');
    appendString(sb, ", World!", 8);
    printStringBuilder(sb);
    deleteStringBuilder(sb);
    sb = NULL;
    printf("Hello, World!\n");
    return 0;
}