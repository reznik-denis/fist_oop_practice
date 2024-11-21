// Reznik-Lab09-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Варіант 7.
//1. Описати структуру з ім‘ям  BOOK, яка містить  наступні поля :
//-Name  – назва книги;
//-Avtor – автори книги;
//-Data –дата друку(структура: month, year - місяць, рік);
//-Cost - ціна книги.
//2. Написати програму, що використовує дану структуру і виконує наступні дії :
//-вводить з клавіатури масив даних SHOP, що складається з N змінних типу BOOK;
//-Впорядковує записи по зростанню поля Avtor;

//для розв’язку наступної задачі запис структури в текстовий файл та считування данних з текстового файлу.


#include <iostream> // Підключаємо бібліотеку для вводу/виводу в консоль.
#include <algorithm> // Підключаємо бібліотеку для роботи з алгоритмами, такими як sort().
#include <string>
#include <fstream>
using namespace std; // Використовуємо простір імен std для спрощення запису, щоб не писати "std::" перед кожною стандартною функцією або класом.

struct Date { // Оголошуємо структуру для зберігання інформації про місяць і рік.
    string month; // Змінна для місяця (рядок).
    int year;     // Змінна для року (ціле число).
};

struct BOOK {  // Оголошуємо структуру для зберігання інформації про книгу.
    string Name;         // Змінна для збереження назви книги.
    string Author;       // Змінна для збереження автора книги.
    struct Date date_print; // Структура Date, що зберігає місяць і рік друку книги.
    int Cost;            // Змінна для вартості книги.
};

bool compareByAuthorName(const BOOK& a, const BOOK& b) {
    return a.Name < b.Name;
}

//void writeToFile(BOOK* group, int N, const string& filename) {
//    ofstream file(filename);
//    if (file.is_open()) {
//        for (int i = 0; i < N; ++i) {
//            file << i + 1 << ". Name: " << group[i].Name
//                << ", Author: " << group[i].Author
//                << ", Date publication: " << group[i].date_print.month
//                << " " << group[i].date_print.year
//                << " year, Cost:" << group[i].Cost;
// 
//            file << endl;
//        }
//        file.close();
//        cout << "Data write success!" << filename << endl;
//    }
//    else {
//        cout << "Error opening file!" << endl;
//    }
//}
void writeToFile(BOOK* group, int N, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << N << endl; // Запис кількості книг
        for (int i = 0; i < N; ++i) {
            file << group[i].Name << "|"
                << group[i].Author << "|"
                << group[i].date_print.month << "|"
                << group[i].date_print.year << "|"
                << group[i].Cost << endl; // Використовуємо "|" як роздільник
        }
        file.close();
        cout << "Data write success! File: " << filename << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }
}


//void readFromFile(BOOK*& group, int& N, const string& filename) {
//    ifstream file(filename);
//    if (file.is_open()) {
//        file >> N;
//        delete[] group;
//        group = new BOOK[N];
//        for (int i = 0; i < N; ++i) {
//            file >> group[i].Name >> group[i].Author 
//                >> group[i].date_print.month 
//                >> group[i].date_print.year >> group[i].Cost;
//        }
//        file.close();
//        cout << "Data read success!" << filename << endl;
//    }
//    else {
//        cout << "Error opening file!" << endl;
//    }
//}
void readFromFile(BOOK*& group, int& N, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> N; // Зчитуємо кількість книг
        file.ignore(); // Пропускаємо символ нового рядка після N
        delete[] group;
        group = new BOOK[N];
        for (int i = 0; i < N; ++i) {
            string line;
            getline(file, line); // Зчитуємо весь рядок
            size_t pos = 0;

            // Парсимо дані за допомогою роздільника "|"
            pos = line.find("|");
            group[i].Name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find("|");
            group[i].Author = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find("|");
            group[i].date_print.month = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find("|");
            group[i].date_print.year = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            group[i].Cost = stoi(line); // Решта - це вартість
        }
        file.close();
        cout << "Data read success! File: " << filename << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }
}


void filterByYear(BOOK* SHOP, int N, int year_book) {
    cout << "Books printed in " << year_book << ":\n"; 
    for (int i = 0; i < N; ++i) { 
        if (SHOP[i].date_print.year >= year_book) { 
            cout << "Name: " << SHOP[i].Name << ", Author: " << SHOP[i].Author 
                << ", Year: " << SHOP[i].date_print.year << ", Month: " << SHOP[i].date_print.month
                << ", Cost: " << SHOP[i].Cost << endl;
        }
    }
}

void displayBooks(BOOK* group, int n) {
    cout << "All books in memory:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". Name: " << group[i].Name
            << ", Author: " << group[i].Author
            << ", Date publication: " << group[i].date_print.month 
            << " " << group[i].date_print.year 
            << " year, Cost:" << group[i].Cost;
        
        cout << endl;
    }
}

int main()
{
    int N = 0;  
    BOOK* SHOP = nullptr;  
    string filename = "shopCatalog.txt";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter books\n";
        cout << "2. Show all books\n";
        cout << "3. Show books by year\n";
        cout << "4. Write books in file\n";
        cout << "5. Read books from file\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "How many books do you want to enter" << endl;
            cin >> N;
            delete[] SHOP;
            SHOP = new BOOK[N];

            for (int i = 0; i < N; ++i) {
                cout << "Enter book name ";
                cin.ignore(); // Очищаємо буфер після попереднього вводу
                getline(cin, SHOP[i].Name);
                cout << "Enter book author ";
                getline(cin, SHOP[i].Author);
                cout << "Enter month of printing book ";
                cin >> SHOP[i].date_print.month; 
                cout << "Enter year of printing book ";
                cin >> SHOP[i].date_print.year;  
                cout << "Enter cost of book ";
                cin >> SHOP[i].Cost; 
                cout << endl;
            }

            sort(SHOP, SHOP + N, compareByAuthorName);

            break;
        }
        case 2:
            displayBooks(SHOP, N);
            break;
        case 3:
            int year_book;
            cout << "Please, enter year of books you want to see" << endl;
            cin >> year_book;
            filterByYear(SHOP, N, year_book);
            break;
        case 4:
            writeToFile(SHOP, N, filename);
            break;
        case 5:
            readFromFile(SHOP, N, filename);
            break;
        case 6:
            delete[] SHOP;
            cout << "Exit out." << endl;
            return 0;
        default:
            cout << "Wrong choose. Try again." << endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu