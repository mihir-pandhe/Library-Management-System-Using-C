#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook(const char* title, const char* author) {
    if (bookCount < MAX_BOOKS) {
        strcpy(library[bookCount].title, title);
        strcpy(library[bookCount].author, author);
        bookCount++;
        printf("Book added: %s by %s\n", title, author);
    } else {
        printf("Library is full.\n");
    }
}

void listBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
    } else {
        for (int i = 0; i < bookCount; i++) {
            printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
        }
    }
}

void searchBookByTitle(const char* title) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, title) != NULL) {
            printf("Found: %s by %s\n", library[i].title, library[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;
    char title[100];
    char author[100];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                getchar();
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';
                addBook(title, author);
                break;
            case 2:
                listBooks();
                break;
            case 3:
                printf("Enter book title to search: ");
                getchar();
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                searchBookByTitle(title);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
