#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* createIntegerArrayWithRandomValues(int n)
{
    int* arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    return arr;
}
void printArray(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
void insertionSort(int* arr, int n)
{
    int min, temp;
    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        // swap arr[i] and arr[min]
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int compare(const void* p, const void* q)
{
    int a = *(int*) p;
    int b = *(int*) q;
    return a - b;
}

void sort(int* array, int n)
{
    qsort(array, n, sizeof(int), compare);
}

int main()
{
    srand(time(NULL));
    int n = 100;
    int* arr = createIntegerArrayWithRandomValues(n);
    printf("Initial Array:\n");
    printArray(arr, n);

    sort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    free(arr);
    printf("Done!");
    return 0;
}