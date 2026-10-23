#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int row;
    int col;
    int val;
} Term;

void readSparseMatrix(Term a[], int *rows, int *cols)
{
    int element, k = 1;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", rows, cols);

    a[0].row = *rows;
    a[0].col = *cols;

    printf("Enter the matrix elements (%d x %d):\n", *rows, *cols);
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *cols; j++)
        {
            scanf("%d", &element);
            if (element != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].val = element;
                k++;
            }
        }
    }
    a[0].val = k - 1;
}

void displayTriplet(Term a[])
{
    if (a[0].val == 0)
    {
        printf("Matrix is completely zero.\n");
        return;
    }
    printf("\nRow\tCol\tValue\n");
    printf("---------------------\n");
    for (int i = 0; i <= a[0].val; i++)
    {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);
    }
}
void transposeSparse(Term a[], Term b[])
{
    int k = 1;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    if (a[0].val > 0)
    {
        for (int col = 0; col < a[0].col; col++)
        {
            for (int i = 1; i <= a[0].val; i++)
            {
                if (a[i].col == col)
                {
                    b[k].row = a[i].col;
                    b[k].col = a[i].row;
                    b[k].val = a[i].val;
                    k++;
                }
            }
        }
    }
}
int addSparse(Term a[], Term b[], Term sum[])
{
    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        return 0;
    }

    int i = 1, j = 1, k = 1;
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val)
    {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
        {
            sum[k++] = a[i++];
        }
        else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col))
        {
            sum[k++] = b[j++];
        }
        else
        {
            int addedVal = a[i].val + b[j].val;
            if (addedVal != 0)
            {
                sum[k].row = a[i].row;
                sum[k].col = a[i].col;
                sum[k].val = addedVal;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i <= a[0].val)
    {
        sum[k++] = a[i++];
    }

    while (j <= b[0].val)
    {
        sum[k++] = b[j++];
    }

    sum[0].val = k - 1;
    return 1;
}

int main()
{
    Term A[MAX], B[MAX], T[MAX], Sum[MAX];
    int r1, c1, r2, c2;
    int choice;

    while (1)
    {
        printf("\n========= SPARSE MATRIX OPERATIONS =========\n");
        printf("1. Input Matrices (A and B)\n");
        printf("2. Display Triplet Representation\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Add Matrices (A + B)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\n--- Matrix A ---\n");
            readSparseMatrix(A, &r1, &c1);
            printf("\n--- Matrix B ---\n");
            readSparseMatrix(B, &r2, &c2);
            printf("\nMatrices stored successfully.\n");
            break;

        case 2:
            printf("\nTriplet Representation of Matrix A:");
            displayTriplet(A);
            printf("\nTriplet Representation of Matrix B:");
            displayTriplet(B);
            break;

        case 3:
            transposeSparse(A, T);
            printf("\nTranspose of Matrix A:");
            displayTriplet(T);
            break;

        case 4:
            if (addSparse(A, B, Sum))
            {
                printf("\nSum of Matrix A and Matrix B:");
                displayTriplet(Sum);
            }
            else
            {
                printf("\nError: Dimensions do not match. Addition not possible.\n");
            }
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Choose between 1 and 5.\n");
        }
    }
    return 0;
}
