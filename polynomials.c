// #include <stdio.h>
// void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
// {
//     float coefficient;
//     *startD = avail;
//     while (startA <= finishA && startB <= finishB)

//         switch (COMPARE(terms[startA].expon, terms[startB].expon))
//         {
//         case -1:
//             attach(terms[startB].coef, terms[startB].expon);
//             startB++;
//             break;

//         case 0:
//             coefficient = terms[startA].coef + terms[startB].coef;
//             if (coefficient)
//                 attach(coefficient, terms[startA].expon);
//             startA++;
//             startB++;
//             break;

//         case 1:
//             attach(terms[startA].coef, terms[startA].expon);
//             startA++;
//         }
//     for (; startA <= finishA; startA++)
//         attach(terms[startA].coef, terms[startA].expon);

//     for (; startB <= finishB; startB++)
//         attach(terms[startB].coef, terms[startB].expon);

//     *finishD = avail - i;
// }

#include <stdio.h>

struct Term
{
    int coeff;
    int exp;
};

int main()
{
    struct Term p[10], q[10], r[20];

    int n1, n2;
    int i = 0, j = 0, k = 0;

    // Number of terms in first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    // Enter first polynomial
    printf("Enter coefficient and exponent of each term:\n");

    for (i = 0; i < n1; i++)
    {
        scanf("%d %d", &p[i].coeff, &p[i].exp);
    }

    // Number of terms in second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    // Enter second polynomial
    printf("Enter coefficient and exponent of each term:\n");

    for (i = 0; i < n2; i++)
    {
        scanf("%d %d", &q[i].coeff, &q[i].exp);
    }

    // Reset i because we need it for addition
    i = 0;

    // Polynomial addition
    while (i < n1 && j < n2)
    {
        // Same exponent
        if (p[i].exp == q[j].exp)
        {
            r[k].coeff = p[i].coeff + q[j].coeff;
            r[k].exp = p[i].exp;

            i++;
            j++;
            k++;
        }

        // First polynomial has greater exponent
        else if (p[i].exp > q[j].exp)
        {
            r[k] = p[i];

            i++;
            k++;
        }

        // Second polynomial has greater exponent
        else
        {
            r[k] = q[j];

            j++;
            k++;
        }
    }

    // Copy remaining terms of first polynomial
    while (i < n1)
    {
        r[k] = p[i];

        i++;
        k++;
    }

    // Copy remaining terms of second polynomial
    while (j < n2)
    {
        r[k] = q[j];

        j++;
        k++;
    }

    // Display result
    printf("\nResultant Polynomial:\n");

    for (i = 0; i < k; i++)
    {
        if (i > 0 && r[i].coeff >= 0)
            printf("+");

        if (r[i].exp == 0)
        {
            printf("%d", r[i].coeff);
        }
        else if (r[i].exp == 1)
        {
            printf("%dx", r[i].coeff);
        }
        else
        {
            printf("%dx^%d", r[i].coeff, r[i].exp);
        }
    }

    printf("\n");

    return 0;
}
