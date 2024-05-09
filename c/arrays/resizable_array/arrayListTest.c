#include <stdio.h>
#include "arrayList.h"

int main()
{
    ArrayList* list = newArrayList(1);
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);

    putElementAt(list, 0, 0);

    printArraList(list);
    deleteArrayList(list);
    return 0;
}