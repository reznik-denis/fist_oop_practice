// Reznik-Lab10-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Варіант 7.
//Написати клас  BOOK, яка містить  наступні поля :
//-Name  – назва книги;
//-Avtor – автори книги;
//-Data –дата друку;
//-Cost - ціна книги.

#include <iostream>
#include <string>
using namespace std;

class BOOK {
private:
    string Name;
    string Author;
    string Date;
    double Cost;

public:
    BOOK() : Name(""), Author(""), Date(""), Cost(0.0) {}
    BOOK(string name, string author, string date, double cost)
        : Name(name), Author(author), Date(date), Cost(cost) {
    }
    ~BOOK() {
        cout << "Destructor called for book: " << Name << endl;
    }
    void setName(const string& name) {
        Name = name;
    }
    string getName() const {
        return Name;
    }
    void setAuthor(const string& author) {
        Author = author;
    }
    string getAuthor() const {
        return Author;
    }
    void setDate(const string& date) {
        Date = date;
    }
    string getDate() const {
        return Date;
    }
    void setCost(double cost) {
        Cost = cost;
    }
    double getCost() const {
        return Cost;
    }
    void inputInfo() {
        cout << "Enter book name: ";
        getline(cin, Name);
        cout << "Enter book author: ";
        getline(cin, Author);
        cout << "Enter publication date (MM.YYYY): ";
        getline(cin, Date);
        cout << "Enter book cost: ";
        cin >> Cost;
        cin.ignore();
    }
    void displayInfo() const {
        cout << "Name: " << Name << endl;
        cout << "Author: " << Author << endl;
        cout << "Date: " << Date << endl;
        cout << "Cost: $" << Cost << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cin.ignore();
    BOOK* books = new BOOK[n];
    for (int i = 0; i < n; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        books[i].inputInfo();
    }
    cout << "\nBooks details:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        books[i].displayInfo();
    }
    cout << "What number of book do you want to change?" << endl;
    int num;
    cin >> num;
    
    while (true) {
        cout << "What value do you want to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Author" << endl;
        cout << "3. Date" << endl;
        cout << "4. Cost" << endl;
        cout << "5. Finish edit" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
        case 1: {
            cout << "Enter name" << endl;
            string name;
            cin.ignore();
            getline(cin, name);
            books[num].setName(name);
            break;
        }
        case 2: {
            cout << "Enter author" << endl;
            string author;
            cin.ignore();
            getline(cin, author);
            books[num].setAuthor(author);
            break;
        }
        case 3: {
            cout << "Enter date" << endl;
            string date;
            cin >> date;
            books[num].setDate(date);
            break;
        }
        case 4: {
            cout << "Enter cost" << endl;
            double cost;
            cin >> cost;
            books[num].setCost(cost);
            break;
        }
        case 5: {
            cout << "Exit" << endl;
            cout << "Your new book" << endl;
            books[num].displayInfo();
            return 0;
        }
        default:
            cout << "You enter wrong choose" << endl;
        }
    }
    delete[] books;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
