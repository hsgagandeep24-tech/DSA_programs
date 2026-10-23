#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert at the beginning
void insertAtBeginning(struct Node **head, int value)
{
    *head = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertatlast(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertatpostion(struct Node **head, int position, int value)
{
    if (position < 1)
    {
        printf("position must be 1 or greater.\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *current = *head;
    int count = 1;

    while (current != NULL && count < position - 1)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        printf("Position %d is out of bounds.\n", position);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Case 1: If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }
    // Case 2: Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if (temp == NULL)
        return;
    // Unlink the node from the chain
    prev->next = temp->next;
    free(temp); // Free memory
}

int main()
{
    struct Node *head = NULL; // Initialize an empty list

    // Inserting elements
    insertAtBeginning(&head, 30);
    insertatpostion(&head, 1, 40);
    insertatpostion(&head, 3, 60);
    insertatlast(&head, 90);

    printf("The Singly Linked List (Chain):\n");
    displayList(head);
    deleteNode(&head, 30);
    displayList(head);
    return 0;
}