#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *Top = NULL;

void push(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }
    newnode->data = value;
    newnode->next = Top;
    Top = newnode;
    printf("%d\n", value);
}
int pop()
{
    if (Top == NULL)
    {
        printf("the stack is empty:");
        return -1;
    }
    struct Node *Temp = Top;
    int poppedvalue = Temp->data;
    Top = Top->next;
    free(Temp);
    return poppedvalue;
}

void display()
{
    if (Top == NULL)
    {
        printf("the stack is empty:");
        return;
    }
    struct Node *temp = Top;
    printf("Stack elements (Top to Bottom): ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    push(15);
    push(25);
    push(35);

    display();

    printf("popped element %d\n", pop());

    display();
    return 0;
}
