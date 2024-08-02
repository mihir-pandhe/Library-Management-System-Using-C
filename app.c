#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_ISSUED_BOOKS 50

typedef struct {
    char title[100];
    char author[100];
} Book;

typedef struct {
    char title[100];
    char borrower[100];
} IssuedBook;

Book library[MAX_BOOKS];
IssuedBook issuedBooks[MAX_ISSUED_BOOKS];
int bookCount = 0;
int issuedBookCount = 0;

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

void issueBook(const char* title, const char* borrower) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0 && issuedBookCount < MAX_ISSUED_BOOKS) {
            strcpy(issuedBooks[issuedBookCount].title, title);
            strcpy(issuedBooks[issuedBookCount].borrower, borrower);
            issuedBookCount++;
            printf("Book issued: %s to %s\n", title, borrower);
            return;
        }
    }
    printf("Book not found or all books issued.\n");
}

void returnBook(const char* title) {
    for (int i = 0; i < issuedBookCount; i++) {
        if (strcmp(issuedBooks[i].title, title) == 0) {
            for (int j = i; j < issuedBookCount - 1; j++) {
                issuedBooks[j] = issuedBooks[j + 1];
            }
            issuedBookCount--;
            printf("Book returned: %s\n", title);
            return;
        }
    }
    printf("Issued book not found.\n");
}

void listIssuedBooks() {
    if (issuedBookCount == 0) {
        printf("No books issued.\n");
    } else {
        for (int i = 0; i < issuedBookCount; i++) {
            printf("%d. %s issued to %s\n", i + 1, issuedBooks[i].title, issuedBooks[i].borrower);
        }
    }
}

void listBooksByAuthor(const char* author) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("Found: %s by %s\n", library[i].title, library[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by %s.\n", author);
    }
}

int main() {
    int choice;
    char title[100];
    char author[100];
    char borrower[100];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. List Issued Books\n");
        printf("7. List Books by Author\n");
        printf("8. Exit\n");
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
                printf("Enter book title to issue: ");
                getchar();
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter borrower name: ");
                fgets(borrower, sizeof(borrower), stdin);
                borrower[strcspn(borrower, "\n")] = '\0';
                issueBook(title, borrower);
                break;
            case 5:
                printf("Enter book title to return: ");
                getchar();
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                returnBook(title);
                break;
            case 6:
                listIssuedBooks();
                break;
            case 7:
                printf("Enter author name to list books: ");
                getchar();
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';
                listBooksByAuthor(author);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
