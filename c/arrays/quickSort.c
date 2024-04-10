#include <stdio.h>

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int i = low-1; // i keeps track of last element smaller than pivot
    for(int j = low; j <= high; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);
    return i+1;
}

void quickSort(int* array, int low, int high)
{
    if(low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi-1);
        quickSort(array, pi+1, high);
    }
}
int main()
{
    int arr[] = {100, 1, 5, 10, 7, 60, 20, 55, 21};
    int n = 8;
    quickSort(arr, 0, n);

    for(int i = 0; i < n; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("\b\b \n");
    return 0;
}