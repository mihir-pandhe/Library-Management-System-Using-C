#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 1

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
    } else {
        printf("Library is full.\n");
    }
}

void listBooks() {
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
    }
}

int main() {
    addBook("The Great Gatsby", "F. Scott Fitzgerald");
    addBook("1984", "George Orwell");
    listBooks();
    return 0;
}
