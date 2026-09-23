#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    struct node *temp = head;
    printf("\nTHE LINKED LIST IS: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void addatbeg()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
    printf("Node inserted at the beginning successfully!\n");
}

void addatend()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Node inserted at the end successfully!\n");
}

void addinbetween()
{
    int pos, i;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        addatbeg();
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);

    struct node *temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!\n");
        free(newnode);
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted successfully!\n");
    }
}

void deletenode()
{
    if (head == NULL)
    {
        printf("The linked list is empty! Nothing to delete.\n");
        return;
    }

    int pos, i;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    struct node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    struct node *prev = NULL;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!\n");
    }
    else
    {
        prev->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add In Between\n");
        printf("4. Delete Node\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addatbeg();
                break;
            case 2:
                addatend();
                break;
            case 3:
                addinbetween();
                break;
            case 4:
                deletenode();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
