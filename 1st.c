#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int Book_ID;
    char Title[100];
    char Author[100];
    float Price;
    char Availability[20];
} Book;
Book *books = NULL;
int n = 0;
void create(void)
{
    int i;
    if (books != NULL)
    {
        free(books);
        books = NULL;
    }
    printf("Enter number of books: ");
    scanf("%d", &n);
    books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Book %d\n", i + 1);
        printf("Book ID: ");
        scanf("%d", &books[i].Book_ID);
        printf("Title: ");
        scanf(" %[^\n]", books[i].Title);
        printf("Author: ");
        scanf(" %[^\n]", books[i].Author);
        printf("Price: ");
        scanf("%f", &books[i].Price);
        printf("Availability (Available/Issued): ");
        scanf("%19s", books[i].Availability);
    }
    printf("\nBook records added successfully.\n");
}
void display(void)
{
    int i;
    if (books == NULL || n == 0)
    {

        printf("No book records available.\n");
        return;
    }
    printf("\n%-8s %-25s %-20s %-10s %-12s\n",
           "ID", "Title", "Author", "Price", "Status");
    printf("--------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%-8d %-25s %-20s %-10.2f %-12s\n",
               books[i].Book_ID, books[i].Title, books[i].Author,
               books[i].Price, books[i].Availability);
    }
}
int findBook(int id)
{
    int i;
    for (i = 0; i < n; i++)
        if (books[i].Book_ID == id)
            return i;
    return -1;
}
void search(void)
{
    int id, pos;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    pos = findBook(id);
    if (pos == -1)
    {
        printf("Book not found.\n");
        return;
    }
    printf("\nBook ID : %d\n", books[pos].Book_ID);
    printf("Title   : %s\n", books[pos].Title);
    printf("Author  : %s\n", books[pos].Author);
    printf("Price   : %.2f\n", books[pos].Price);
    printf("Status  : %s\n", books[pos].Availability);
}
void issueBook(void)
{
    int id, pos;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    pos = findBook(id);
    if (pos == -1)
        printf("Book not found.\n");
    else if (strcmp(books[pos].Availability, "Issued") == 0)
        printf("Book is already issued.\n");
    else
    {
        strcpy(books[pos].Availability, "Issued");
        printf("Book issued successfully.\n");
    }
}
void returnBook(void)
{
    int id, pos;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    pos = findBook(id);
    if (pos == -1)
        printf("Book not found.\n");
    else if (strcmp(books[pos].Availability, "Available") == 0)
        printf("Book is already available in the library.\n");
    else
    {
        strcpy(books[pos].Availability, "Available");
        printf("Book returned successfully.\n");
    }
}
int main(void)
{
    int choice;
    do
    {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book Records\n");
        printf("2. Display all Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");

        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            returnBook();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);
    free(books);
    return 0;
}