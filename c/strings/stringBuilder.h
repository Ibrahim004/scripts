#ifndef STRING_BUILDER_HEAD
#define STRING_BUILDER_HEAD

#define MAX_STRING_BUILDER_SIZE 1 << 30

typedef struct {
    char* array;
    int capacity;
    int size;
} StringBuilder;

StringBuilder * newStringBuilder(int capacity);
void deleteStringBuilder(StringBuilder* sb);
void append(StringBuilder* sb, char c);
void appendString(StringBuilder* sb, char* string, int size);
void printStringBuilder(StringBuilder * sb);

#endif
