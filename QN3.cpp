/*Define a class Libary with bookTitle , author and numberofCopiees as data members.
 Implement methods to add new books,issue books and return books.
 Ensure that the number of copies is approximately updates for each opearation.*/
#include <iostream>
#include <string>
using namespace std;

class Library {
    string bookTitle, author;
    int numberofCopies;

public:
    void setdata() {
        cout << "Enter the details of the book:" << endl;
        cout << "Book Title: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Author: ";
        getline(cin, author);
        cout << "Number of copies: ";
        cin >> numberofCopies;
    }

    void Newbooks() {
        setdata();
    }

    void issuebook() {
        if (numberofCopies > 0) {
            numberofCopies--;
            cout << "Book issued successfully. Remaining copies: " << numberofCopies << endl;
        } else {
            cout << "No copies left to issue." << endl;
        }
    }

    void returnbook() {
        numberofCopies++;
        cout << "Book returned successfully. Total copies: " << numberofCopies << endl;
    }

    string getbooktitle() { return bookTitle; }
};

int main() {
    int count;
    string decision, Book_title;
    Library IOE[1000];
    cout << "Enter the number of book details: ";
    cin >> count;

    // Add book details
    for (int i = 0; i < count; i++) {
        IOE[i].setdata();
    }

    // Menu for operations
    cout << "Type 'add' to add new book.\n"
         << "Type 'issue' to issue a book.\n"
         << "Type 'return' to return a book.\n";
    cin.ignore(); // Clear the buffer before taking a new line input
    getline(cin, decision);

    if (decision == "add") {
        IOE[count].Newbooks();
        count++; // Increase the count after adding a new book
    } else if (decision == "issue") {
        cout << "Enter the book title to be issued: ";
        getline(cin, Book_title);
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (IOE[i].getbooktitle() == Book_title) {
                IOE[i].issuebook();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No book under such title is found." << endl;
        }
    } else if (decision == "return") {
        cout << "Enter the title of the book you want to return: ";
        getline(cin, Book_title);
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (IOE[i].getbooktitle() == Book_title) {
                IOE[i].returnbook();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No book under such title is found." << endl;
        }
    } else {
        cout << "Invalid input." << endl;
        exit(0);
    }

    return 0;
}
