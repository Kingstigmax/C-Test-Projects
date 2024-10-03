#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Book 
{
    int id;
    char title[100];
    char author[50];
    int available;
} Book;


typedef struct Node
{
    Book book;
    struct Node* next;
} Node;

Node* head = NULL;

void addBook() // add
{
    Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter a book title: ");
    scanf("%[^\n]]", &newBook.title);
    printf("Enter author: ");
    scanf("%[^\n]]", &newBook.author);

    newBook.available = 1;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book = newBook;
    newNode->next = head;
    head = newNode;

    printf("Book added successfully!\n");
}

void displayBooks() {
    Node* current = head;
    if (current == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("Book Inventory:\n");
    while (current != NULL) {
        printf("ID: %d, Title: %s, Author: %s, Available: %s\n",
               current->book.id, current->book.title, current->book.author,
               current->book.available ? "Yes" : "No");
        current = current->next;
    }
}



int main()
{
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}