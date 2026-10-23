#include <stdio.h>
void main()
{
    int newnode = 9;
    int *head = &newnode;
    int *counter;
    int *counter = head;
    printf("the value is %d\n", head);
    printf("the value is %d\n", counter);
}