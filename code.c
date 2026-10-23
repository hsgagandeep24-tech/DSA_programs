#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;

    int *arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Array elements after calloc:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]= %d\n", i, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * 10;
    }

    // Print updated values
    printf("\nArray elements after assignment:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Always free dynamically allocated memory when done
    free(arr);

    // Prevent dangling pointer by setting to NULL
    arr = NULL;

    return 0;
}
