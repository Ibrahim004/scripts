#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1D_int_array.c"

int** create2DArrayOfIntegersWithRandomValues(int rows, int columns)
{
    int** arr = (int**) malloc(sizeof(int*) *rows);
    for(int i = 0; i < rows; i++)
    {
        arr[i] = (int*) malloc(sizeof(int) * columns);
        for(int j = 0; j < columns; j++)
        {
            arr[i][j] = rand();
        }
    }
    return arr;
}

void print2DArray(int** arr, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("\b\b \n");
    }
}

void free2DIntegerArray(int** arr, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void sortRowsOf2DIntegerArray(int** arr, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        insertionSort(arr[i], columns);
    }
}

int* copyRow(int** arr, int row, int n)
{
    int* a = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        a[i] = arr[row][i];
    }
    return a;
}
void multiplySquareMatrices(int** m1, int** m2, int n)
{
    for(int i = 0; i < n; i++)
    {
        int* row = copyRow(m1, i, n);
        
        for(int j = 0; j < n; j++)
        {
            int result = 0;
            for(int k = 0; k < n; k++)
            {
                result += row[k] * m2[k][j];
            }
            m1[i][j] = result;
        }
    }
}

int main()
{
    srand(time(NULL));
    // 2D matrix multiplication
    int n = 5;
    int** m1 = create2DArrayOfIntegersWithRandomValues(n, n);
    int** m2 = create2DArrayOfIntegersWithRandomValues(n, n);

    printf("First matrix:\n");
    print2DArray(m1, n, n);
    printf("------------------\nSecond matrix:\n");
    print2DArray(m2, n, n);
    multiplySquareMatrices(m1, m2, n);
    printf("------------------\nResult of multiplication:\n");
    print2DArray(m1, n, n);

    free2DIntegerArray(m1, n);
    free2DIntegerArray(m2, n);
    printf("Done!\n");
    return 0;
}