#include <stdio.h>
#include <stdlib.h>

int queue[50];
int front = -1;
int rear = -1;
int size; // Declaration of global variable 'size'

void enqueue()
{
    int ele;
    printf("Enter the element to be enqueued: ");
    scanf("%d", &ele);
    
    // Check for overflow first in a circular queue
    if((rear + 1) % size == front)
    {
        printf("Overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = ele;
    }
    else
{
    if (rear == size - 1)
    {
        rear = 0; 
    }
    else
    {
        rear++;  
    }
    
    queue[rear] = ele; 
}
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else if(front == rear)
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        while(1)
        {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % size;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("Enter the size of the queue (max 50): ");
    scanf("%d", &size);

    if(size > 50 || size <= 0)
    {
        printf("Invalid size!\n");
        return 0;
    }

    while(1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
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
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
