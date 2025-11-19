

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//---------------------------------------------
// Class: Book
//---------------------------------------------
class Book {
private:
    string bookID;
    int serialNumber;
    string title;
    string author;
    string publisher;
    double price;
    bool isIssued;

public:
    // Constructors
    Book(string bookID, int serialNumber, string title, string author, string publisher, double price) {
        this->bookID=bookID;
        this->serialNumber=serialNumber;
        this->title=title;
        this->author=author;
        this->publisher=publisher;
        this->price=price;
    }

    // Getters
    string getBookID() const {return bookID;}
    int getSerialNumber() const {return serialNumber;}
    string getTitle() const {return title;}
    string getAuthor() const {return author;}
    string getPublisher() const {return publisher;}
    double getPrice() const {return price;}
    bool getIssuedStatus() const {return isIssued;}

    // Setters
    void setIssuedStatus(bool status) {isIssued=status;}
};

//---------------------------------------------
// Abstract Class: Member
//---------------------------------------------
class Member {
protected:
    string memberID;
    string name;
    string email;
    string address;
    int issuedCount;

public:
    Member(string memberID, string name, string email, string address) {
        this->memberID=memberID;
        this->name=name;
        this->email=email;
        this->address=address;
    }

    // Virtual Destructor
    virtual ~Member() {}

    // Getters
    string getMemberID() const {return memberID;}
    string getName() const {return name;}
    string getEmail() const {return email;}
    string getAddress() const {return address;}

    // Pure virtual function for issue limit
    virtual int getIssueLimit() const = 0;

    // Manage issued books
    void incrementIssuedCount() {issuedCount++;}
    void decrementIssuedCount() {issuedCount--;}
    int getIssuedCount() const {return issuedCount;};
};

//---------------------------------------------
// Derived Class: Student
//---------------------------------------------
class Student : public Member {
public:
    Student(string memberID, string name, string email, string address);
    int getIssueLimit() const;
};

//---------------------------------------------
// Derived Class: Faculty
//---------------------------------------------
class Faculty : public Member {
public:
    Faculty(string memberID, string name, string email, string address);
    int getIssueLimit() const;
};

//---------------------------------------------
// Class: Transaction
//---------------------------------------------
class Transaction {
private:
    string memberID;
    string bookID;
    int serialNumber;
    string dateOfTransaction;
    bool returned;

public:
    Transaction(string memberID, string bookID, int serialNumber, string dateOfTransaction, bool returned = false);

    // Getters
    string getMemberID() const;
    string getBookID() const;
    int getSerialNumber() const;
    string getDateOfTransaction() const;
    bool isReturned() const;

    // Setters
    void markReturned();
};

//---------------------------------------------
// Class: Library
//---------------------------------------------
class Library {
private:
    vector<Book> books;
    vector<Member*> members;
    vector<Transaction> transactions;

    // Helper functions
    Member* findMemberByID(const string& memberID);
    Book* findBookByIDAndSerial(const string& bookID, int serialNumber);
    bool isBookAvailable(const string& bookID);
    bool isBookIssuedToMember(const string& memberID, const string& bookID, int serialNumber);

public:
    // Book management
    void addBook(const Book& book);
    void displayAllBooks() const;

    // Member management
    void addMember(Member* member);
    void displayAllMembers() const;

    // Transaction management
    void issueBook(const string& memberID, const string& bookID, const string& dateOfTransaction);
    void returnBook(const string& memberID, const string& bookID, int serialNumber, const string& dateOfTransaction);
    void displayAllTransactions() const;
};
