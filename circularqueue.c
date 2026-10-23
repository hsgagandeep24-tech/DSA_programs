#include <stdio.h>
#include <stdlib.h>

#define N 5
int q[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == -1 && front == -1)
    {
        rear = front = 0;
        q[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("QUEUE is full\n");
        return;
    }
    else
    {
        rear = (rear + 1) % N;
        q[rear] = x;
    }
    printf("The added value is %d\n", x);
}

void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("QEUE is empty");
    }
    else if (rear == front)
    {
        printf("deleted value is %d", q[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted value is %d\n", q[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (rear == -1 && front == -1)
    {
        printf("QEUE is empty");
    }
    else
    {
        printf("queue elements are: ");
        int i = front;
        while (1)
        {
            printf("%d\t", q[i]);
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}
int main()
{
    int choice, x;
    while (1)
    {
        printf("\n=== QUEUE OPERATIONS ===");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Display Queue");
        printf("\n4. Exit\n");
        printf("Enter the choice(1-4):");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the value to enter");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between (1-4).\n");
        }
    }
    return 0;
}