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

void delete_last(struct Node **head)
{
    // If the list is empty
    if (*head == NULL)
    {
        return;
    }

    // If the list contains only one element
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Finding the second last node
    struct Node *second_last = *head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }

    // Freeing the memory of the last node
    free(second_last->next);

    // Setting the next of the second last node to NULL
    second_last->next = NULL;
}

void removeById(struct Node **head, int id)
{
    // If the list is empty
    if (*head == NULL)
    {
        return;
    }

    // If the list contains only one element
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Finding the node before the node to be removed
    struct Node *before = *head;
    for (int i = 0; i < id - 2; i++)
    {
        before = before->next;
    }

    // Storing the node to be removed
    struct Node *temp = before->next;

    // Linking the node before the removed node with the node after the removed node
    before->next = before->next->next;

    // Freeing the memory of the removed node
    free(temp);
}

void delete_by_value(struct Node **head, int value)
{
    // If the list is empty
    if (*head == NULL)
    {
        return;
    }

    // If the first element matches the value
    if ((*head)->data == value)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Finding the node before the node to be removed
    struct Node *before = *head;
    while (before->next != NULL && before->next->data != value)
    {
        before = before->next;
    }

    // If the value is not found in the list
    if (before->next == NULL)
    {
        return;
    }

    // Storing the node to be removed
    struct Node *temp = before->next;

    // Linking the node before the removed node with the node after the removed node
    before->next = before->next->next;

    // Freeing the memory of the removed node
    free(temp);
}

void addByIndex(struct Node **head, int value, int index)
{
    // Creating a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    // If the list is empty
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // If the new node is to be added at the beginning of the list
    if (index == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Finding the node before the index
    struct Node *before = *head;
    for (int i = 0; i < index - 1; i++)
    {
        before = before->next;
    }

    // Linking the new node with the node after the index
    new_node->next = before->next;

    // Linking the node before the index with the new node
    before->next = new_node;
}
int main()
{
    // Initializing an empty list
    struct Node *head = NULL;

    // Adding elements at the beginning of the list
    add_first(&head, 5);
    add_first(&head, 10);
    add_first(&head, 15);
    add_first(&head, 20);
    add_first(&head, 25);
    add_first(&head, 30);

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

    // Deleting the last element of the list
    delete_last(&head);

    // Displaying the list after deletion
    current = head;
    printf("\nList after deletion the last element: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // Removing the element at index 2
    removeById(&head, 2);

    // Displaying the list after removal
    current = head;
    printf("\nList after removal of the element at index 2: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // Deleting the element with value 15
    delete_by_value(&head, 15);

    // Displaying the list after deletion
    current = head;
    printf("\nList after deletion the element with value 15: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    // Adding an element at index 2
    addByIndex(&head, 35, 2);

    // Displaying the list after adding an element at index 2
    current = head;
    printf("\nList after adding an element at index 2: ");
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