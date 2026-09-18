#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Book {
    int idBook;
    string nameBook;
    string author;

    void inputInfo() {
        cout << "Enter the id of the book: ";
        cin >> idBook;
        cin.ignore();
        cout << "Enter the name of the book: ";
        getline(cin, nameBook);
        cout << "Enter the author of the book: ";
        getline(cin, author);
        cout << endl;
    }
    void outputInfo() {
        cout << "========================" << endl;
        cout << "   |   ID      : " << idBook << endl;
        cout << "   |   Name    : " << nameBook << endl;
        cout << "   |   Author  : " << author << endl;
        cout << "========================" << endl;
    }
};
struct Library {
    int idLibrary;
    string nameLibrary;
    int bookNumber;
    Book bookList[MAX];
    // Kiem tra thu vien
    bool checkLibrary(int id, string name) {
        return (id == 123 && name == "A5-103");
    }

    // Nhap thong tin Library va Book
    bool inputLibrary() {
        cout << "*************************" << endl;
        cout << "Enter the id of the library: ";
        cin >> idLibrary;
        cin.ignore();
        cout << "Enter the name of the library: ";
        getline(cin, nameLibrary);
        // Kiem tra Library
        if (!checkLibrary(idLibrary, nameLibrary)) {
            cout << "Sorry we don't have this library" << endl;
            return false;
        }
        // Nhap so luong Book
        do {
            cout << "Enter the number of the book (1 - "
                 << MAX << "): ";
            cin >> bookNumber;
        } while (bookNumber < 1 || bookNumber > MAX);

        // Nhap danh sach Book
        for (int i = 0; i < bookNumber; i++) {
            cout << "\n--- Book " << i + 1 << " ---" << endl;
            bookList[i].inputInfo();
        }
        cout << "*************************" << endl;

        return true;
    }

    // Xuat thong tin Library
    void outputLibrary() {
        cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "ID of the library: " << idLibrary << endl;
        cout << "Name of the library: " << nameLibrary << endl;
        cout << "The number of books we currently have: " << bookNumber << endl;
        // Xuat danh sach Book
        for (int i = 0; i < bookNumber; i++) {
            bookList[i].outputInfo();
        }
    }

    // Them Book
    void addBook(Book s) {
        if (bookNumber < MAX) {
            bookList[bookNumber] = s;
            bookNumber++;
            cout << " --> Add book successfully!" << endl;
        }
        else {
            cout << " --> Sorry there is no space left" << endl;
        }
    }

    void getBookInfo(int idSearch) {

        for (int i = 0; i < bookNumber; i++) {
            if (bookList[i].idBook == idSearch) {
                cout << "===================" << endl;
                cout << " ==> Found the book with the ID: " << idSearch << endl;
                bookList[i].outputInfo();

                return;
            }
        }
        // Chi bao loi sau khi da tim het danh sach
        cout << "Sorry there is no ID: " << idSearch << " match with the book" << endl;
    }

    Book showBookInfo(int idSearch) {
        for (int i = 0; i < bookNumber; i++) {
            if (bookList[i].idBook == idSearch) {
                cout << "===================" << endl;
                cout << " ==> Found the book with the ID: " << idSearch << endl;
                bookList[i].outputInfo();
                // Tra ve toan bo struct Book
                return bookList[i];
            }
        }
        // Neu khong tim thay
        Book emptyBook;
        emptyBook.idBook = -1;
        emptyBook.nameBook = "N/A";
        emptyBook.author = "N/A";
        return emptyBook;
    }
};

int main() {

    Library oopLibrary;

    if (oopLibrary.inputLibrary()) {
        oopLibrary.outputLibrary();
    }
    else {

        return 0;
    }
    int idSearch;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"  << endl;
    cout << "Enter the ID u wanna search (void): ";
    cin >> idSearch;
    oopLibrary.getBookInfo(idSearch);
    cout << "\nEnter the ID u wanna search (Struct): ";
    cin >> idSearch;
    Book s = oopLibrary.showBookInfo(idSearch);
    if (s.idBook != -1) {
        cout << " --> Found the ID  : " << s.idBook << endl;
        cout << "   | Name          : " << s.nameBook << endl;
        cout << "   | Author        : " << s.author << endl;
    }
    else {
        cout << " --> The ID: " << idSearch << " does not exist" << endl;
    }

    return 0;
}

