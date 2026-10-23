// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 3
// // Maximum capacity of the queue

// int queue[MAX];
// int front = -1;
// int rear = -1;

// // Function to add an element to the queue (Enqueue)
// void enqueue(int val)
// {
//     if (rear == MAX - 1)
//     {
//         printf("\nQueue Overflow! Cannot insert %d.\n", val);
//         return;
//     }
//     if (front == -1)
//     {
//         front = 0; // Set front to 0 on inserting the very first element
//     }
//     rear++;
//     queue[rear] = val;
//     printf("Successfully inserted %d into the queue.\n", val);
// }

// // Function to delete an element from the queue (Dequeue)
// void dequeue()
// {
//     if (front == -1 || front > rear)
//     {
//         printf("\nQueue Underflow! The queue is empty.\n");
//         return;
//     }
//     printf("\nDeleted element: %d\n", queue[front]);
//     front++;
// }

// // Function to display queue elements
// void display()
// {
//     if (front > rear)
//     {
//         printf("\nThe queue is empty.\n");
//         return;
//     }
//     printf("\nQueue elements (Front -> Rear): ");
//     for (int i = front; i <= rear; i++)
//     {
//         printf("element of %d is %d\n", i, queue[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int choice, val;

//     while (1)
//     {
//         printf("\n=== QUEUE OPERATIONS ===");
//         printf("\n1. Enqueue (Insert)");
//         printf("\n2. Dequeue (Delete)");
//         printf("\n3. Display Queue");
//         printf("\n4. Exit");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             printf("Enter value to insert: ");
//             scanf("%d", &val);
//             enqueue(val);
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             display();
//             break;
//         case 4:
//             exit(0);
//         default:
//             printf("Invalid choice! Please try again.\n");
//         }
//     }

//     return 0;
// }

//----QUEUE using dynamic array

#include <stdio.h>
#include <stdlib.h>

int *queue;       // Pointer for dynamic array
int capacity = 2; // Starting small so we can watch it grow
int front = -1;
int rear = -1;

// Function to Enqueue (Insert) with auto-growth
void enqueue(int val)
{
    // If array is full, double its capacity using realloc
    if (rear == capacity - 1)
    {
        capacity *= 2; // Double the size
        queue = (int *)realloc(queue, capacity * sizeof(int));
        printf("\n[Queue Auto-Resized! New capacity is now %d]\n", capacity);
    }

    if (front == -1)
    {
        front = 0; // First element being inserted
    }

    rear++;
    queue[rear] = val;
    printf("Successfully inserted %d\n", val);
}

// Function to Dequeue (Delete)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    printf("\nDeleted element: %d\n", queue[front]);
    front++;

    // Reset if queue becomes completely empty
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Function to Display
void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nThe queue is empty.\n");
        return;
    }

    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    // Allocate initial memory on the heap
    queue = (int *)malloc(capacity * sizeof(int));

    // Testing the dynamic behavior
    enqueue(10);

    // This next insert exceeds capacity 2, triggering realloc() automatically!
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    display();

    // Free heap memory before closing
    free(queue);
    return 0;
}