#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book;
class BorrowerRecord;
class Book {
private:
    //atts
    string number;
    string author;
    string title;
    BorrowerRecord* borrower;
public:
    string getNumber() {
        return this->number;
    }
    void setNumber(string number) {
        this->number = number;
    }
    string getAuthor() {
        return this->author;
    }

    void setAuthor(string author) {
        this->author = author;
    }
    string getTitle() {
        return this->title;
    }
    BorrowerRecord* getBorrower() {
        return this->borrower;
    }

    // contructors
    Book(string number, string author, string title) {
        this->number = number;
        this->author = author;
        this->title  = title;
        this->borrower= nullptr;
    }
    Book(string number) : Book(number,"", "") {}
    // method
    void display() {
        cout << "Book: \n";
        cout << "-number: " <<this->getNumber() << "\n";
        cout << "-author: " << this->getAuthor() << "\n";
        cout << "-title: "<<this->getTitle() << "\n";
    }

};

class BorrowerRecord {
private:
    string name;
    vector<Book*> books;
public:
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    // Constructor
    BorrowerRecord(string name) {
        this->setName(name);
    }
    void display() {
        cout << "Borrower name: " << this->getName() << "\n";
    }
    void attachBook(Book* book) {
        this->books.push_back(book);
    }
};

class Library {
private:
    //atts
    string name;
    vector<Book *> stock;
    vector<BorrowerRecord *> borrowers;
public:
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }

    // constructors
    Library(string name) {
        this->name = name;
        this->stock = vector<Book *>();
        this->borrowers = vector<BorrowerRecord *>();
    }
    // destructor
    ~Library() {
        for (auto br : this->borrowers) {
            delete br;
        }
        cout << "before clear the borrowers: " << this->borrowers.size() << endl;
        this->borrowers.clear();
        cout << "after clear the borrowers: " << this->borrowers.size() << endl;
    }
    void displayLib() {
        cout << "Library name: " << this->getName() << "\n";
        for (auto br: this->borrowers) {
            br->display();
        }

    }
    void displayListBook() {
        cout << "Stock: " << "\n";
        for (auto book : this->stock) {
            book->display();
            BorrowerRecord* borrower = book->getBorrower();
            if(book->getBorrower() != nullptr) {
                cout << "Borrowed by: " << borrower->getName() << endl;
            }
        }
    }

    void displayBorrowers() {
        cout << "List of Borrowers:" << endl;
        for (auto borrower : this->borrowers) {
            borrower->display();
        }
    }

    void addOneBook(Book *book) {
        this->stock.push_back(book);
    }
    void registerOneBookBorrower(string borrowername) {
        this->borrowers.push_back(new BorrowerRecord(borrowername));
    }
    void lendOneBook(string number, string name) {
    // find the book
    Book* b = nullptr;
    for (Book* book : this->stock) {
        if (book->getBorrower() == nullptr) { // available for loan
            if (book->getNumber() == number) {
                b = book;
                break;
            }
        }
    }
    if (b == nullptr) {
        cout << "Khong tim duoc sach" << endl;
        return;
    }

    BorrowerRecord* br = nullptr;
    for (BorrowerRecord* borrower : this->borrowers) {
        if (borrower->getName() == name) {
            br = borrower;
            break;
        }
    }
    if (br == nullptr) {
        cout << "Khong tim duoc nguoi muon" << endl;
        return;
    }

    br->attachBook(b);
    cout << "Successfully lend book " << number << " to " << name << endl;
}

};

int main() {
    cout << "The library Application\n";
    Book book1("001", "Alex", "Convex Analysis");
    //book1.display();
    Book book2("003");
    //book2.display();
    Library lib1("HCMUSlib");
    // 1. AddOneBook
    lib1.addOneBook(&book1);
    lib1.addOneBook(&book2);
    lib1.displayListBook();
    // 2. Register
    lib1.registerOneBookBorrower("Bob");
    lib1.registerOneBookBorrower("John");
    Book python("005","ABC" ,"Python");
    lib1.addOneBook(&python);
    // 5. LendOneBook
    lib1.lendOneBook("001", "John");
    lib1.lendOneBook("005", "Bob");
    lib1.lendOneBook("003", "A");
    lib1.lendOneBook("101", "Bob");
    lib1.displayListBook();
    lib1.displayBorrowers();
}