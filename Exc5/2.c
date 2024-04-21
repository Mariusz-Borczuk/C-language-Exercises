#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Function to add a node at the beginning of the list
void add_first(struct Node **head, int value)
{
    // Creating a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    // Linking the new node with the current head of the list
    new_node->next = *head;

    // Setting the new node as the new head of the list
    *head = new_node;
}

void delete_first(struct Node **head)
{
    // If the list is empty
    if (*head == NULL)
    {
        return;
    }

    // Storing the current head
    struct Node *temp = *head;

    // Setting the new head of the list
    *head = (*head)->next;

    // Freeing the memory of the previous head
    free(temp);
}
int main()
{
    // Initializing an empty list
    struct Node *head = NULL;

    // Adding elements at the beginning of the list
    add_first(&head, 5);
    add_first(&head, 10);
    add_first(&head, 15);

    // Displaying the list
    struct Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // Deleting the first element of the list
    delete_first(&head);

    // Displaying the list after deletion
    current = head;
    printf("\nList after deletion the first element: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // read the user input

    printf("\nPress any key to exit.");
    scanf("%d");
    return 0;
}