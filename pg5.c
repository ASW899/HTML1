#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("STACK OVERFLOW: MEMORY NOT AVAILABLE\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("%d pushed into the stack\n", value);
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void linear_search(int key) {
    struct node *temp = top;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d from the top\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the stack\n", key);
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- STACK USING SINGLE LINKED LIST ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. LINEAR SEARCH\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &value);
                linear_search(value);
                break;

            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
