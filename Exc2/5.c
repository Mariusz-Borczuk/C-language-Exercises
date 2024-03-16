#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
/*### Task 5: Implementing a Simple Address Book

- Define a `Contact` structure that contains first name, 
last name (as an array of characters) and phone number (as an array of characters).
- Create an array of `Contact` structures and initialize it with sample data.
- Write functions to:
     - Adding a new contact to the address book.
     - Search for a contact by name.
     - Delete a contact by name.
     - Listing all contacts in the address book.
- To make managing your contact board easier, you can set a fixed maximum board size and track the current number of contacts.
- In the `main` function, implement a simple user interface to perform the above operations
(add, find, remove, show all). (just use `scanf` asking what the user wants to do, or use [parsing input arguments](https://stackoverflow.com/questions/9642732/parsing-command-line-arguments-in-c))*/
struct Contact {
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
};

void addContact(struct Contact contacts[], int *numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Address book is full.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter first name: ");
    scanf("%s", newContact.firstName);

    printf("Enter last name: ");
    scanf("%s", newContact.lastName);

    printf("Enter phone number: ");
    scanf("%s", newContact.phoneNumber);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact has been added.\n");
}

void searchContact(struct Contact contacts[], int numContacts, char lastName[]) {
    int found = 0;

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            printf("Contact found:\n");
            printf("First Name: %s\n", contacts[i].firstName);
            printf("Last Name: %s\n", contacts[i].lastName);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(struct Contact contacts[], int *numContacts, char lastName[]) {
    int found = 0;

    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Contact has been deleted.\n");
    } else {
        printf("Contact not found.\n");
    }
}

void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Address book is empty.\n");
        return;
    }

    printf("Address book:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("First Name: %s\n", contacts[i].firstName);
        printf("Last Name: %s\n", contacts[i].lastName);
        printf("Phone Number: %s\n", contacts[i].phoneNumber);
        printf("\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char lastName[50];

    while (1) {
        printf("Select an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                printf("Enter the last name of the contact to search: ");
                scanf("%s", lastName);
                searchContact(contacts, numContacts, lastName);
                break;
            case 3:
                printf("Enter the last name of the contact to delete: ");
                scanf("%s", lastName);
                deleteContact(contacts, &numContacts, lastName);
                break;
            case 4:
                displayContacts(contacts, numContacts);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
