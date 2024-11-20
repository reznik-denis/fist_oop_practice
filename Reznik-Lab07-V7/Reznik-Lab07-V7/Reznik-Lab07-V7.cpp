// Reznik-Lab07-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
//-Виводить на екран  всі книги  які були надруковані в заданому році.


#include <iostream>
#include <algorithm>
#include <ctime>     // Підключаємо бібліотеку для роботи з функцією time().
using namespace std; // Використовуємо простір імен std для спрощення запису.

struct Date {
    string month;
    int year;
};

struct BOOK {
    string Name;
    string Author;
    struct Date date_print;
    int Cost;
};

bool compareByAuthorName(const BOOK& a, const BOOK& b) {
    return a.Name < b.Name;  // Порівнюємо імена по зростанню
}

void filterByYear(BOOK *SHOP, int N, int year_book) {
    cout << "Books printed in " << year_book << ":\n";
    for (int i = 0; i < N; ++i) {
        if (SHOP[i].date_print.year >= year_book) {
            cout << "Name: " << SHOP[i].Name << ", Author: " << SHOP[i].Author
                << ", Year: " << SHOP[i].date_print.year << ", Month: " << SHOP[i].date_print.month
                << ", Cost: " << SHOP[i].Cost << endl;
        }
    }
}


int main()
{
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел поточним часом.

    int N = 0;

    cout << "How many books do you want to enter" << endl; 
    cin >> N;

    BOOK *SHOP = new BOOK[N];

    for (int i = 0; i < N; ++i) {
        cout << "Enter book name ";
        cin >> SHOP[i].Name;
        cout << "Enter book author ";
        cin >> SHOP[i].Author;
        cout << "Enter month of printing book ";
        cin >> SHOP[i].date_print.month;
        cout << "Enter year of printing book ";
        cin >> SHOP[i].date_print.year;
        cout << "Enter cost of book ";
        cin >> SHOP[i].Cost;
        cout << endl;
    }

    sort(SHOP, SHOP + N, compareByAuthorName);
    int year_book;

    cout << "Please, enter year of books you want to see" << endl;
    cin >> year_book;

    filterByYear(SHOP, N, year_book);

    delete[] SHOP;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu