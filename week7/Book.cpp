#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Book {
    int id;
    string name;
    string author;

    void inputInfo() {
        cin >> id;
        cin >> name;
        cin >> author;
    }

    void outputInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
    }
};

struct Library {
    int idLibrary;
    string nameLibrary;
    int numBooks;
    Book books[MAX];

    void inputLibrary() {
        cout << "Enter library ID: ";
        cin >> idLibrary;

        cout << "Enter library name: ";
        cin >> nameLibrary;

        cout << "Enter number of books: ";
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++) {
            cout << "\nEnter book " << i + 1 << ":" << endl;
            books[i].inputInfo();
        }
    }

    void outputLibrary() {
        cout << "\n===== LIBRARY INFORMATION =====" << endl;
        cout << "Library ID: " << idLibrary << endl;
        cout << "Library Name: " << nameLibrary << endl;
        cout << "Number of books: " << numBooks << endl;

        cout << "\n===== BOOK LIST =====" << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << "\nBook " << i + 1 << ":" << endl;
            books[i].outputInfo();
        }
    }

    void addBook(Book a) {
        books[numBooks] = a;
        numBooks++;
    }

    Book getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return books[i];
            }
        }

        // Không tìm thấy
        Book emptyBook;
        emptyBook.id = -1;
        return emptyBook;
    }

    Book* getBooks() {
        return books;
    }
};

int main() {
    Library library;

    library.inputLibrary();
    library.outputLibrary();

    // Tìm sách theo ID
    int idBook;
    cout << "\nEnter book ID to search: ";
    cin >> idBook;

    Book book = library.getBookInfo(idBook);

    if (book.id != -1) {
        cout << "\n===== BOOK FOUND =====" << endl;
        book.outputInfo();
    }
    else {
        cout << "Book not found!" << endl;
    }

    return 0;
}