#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void listBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
    } else {
        for (int i = 0; i < bookCount; i++) {
            printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
        }
    }
}

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
    addBook("1984", "George Orwell");
    addBook("The Great Gatsby", "F. Scott Fitzgerald");
    listBooks();
    return 0;
}
