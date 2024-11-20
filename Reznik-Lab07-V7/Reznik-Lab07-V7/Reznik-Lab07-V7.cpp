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


#include <iostream> // Підключаємо бібліотеку для вводу/виводу в консоль.
#include <algorithm> // Підключаємо бібліотеку для роботи з алгоритмами, такими як sort().
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

// Функція для порівняння книг за назвою в алфавітному порядку.
bool compareByAuthorName(const BOOK& a, const BOOK& b) {
    return a.Name < b.Name;  // Порівнюємо імена книг по зростанню.
}

// Функція для фільтрації книг за роком видання.
void filterByYear(BOOK *SHOP, int N, int year_book) {
    cout << "Books printed in " << year_book << ":\n"; // Виводимо заголовок, який вказує на рік для фільтрації.
    for (int i = 0; i < N; ++i) { // Ітерація по кожному елементу масиву SHOP.
        if (SHOP[i].date_print.year >= year_book) { // Якщо рік видання книги більше або дорівнює введеному року.
            cout << "Name: " << SHOP[i].Name << ", Author: " << SHOP[i].Author // Виводимо інформацію про книгу.
                << ", Year: " << SHOP[i].date_print.year << ", Month: " << SHOP[i].date_print.month
                << ", Cost: " << SHOP[i].Cost << endl; // Виводимо рік, місяць і вартість книги.
        }
    }
}

int main() // Початок головної функції програми.
{
    int N = 0;  // Змінна для зберігання кількості книг.

    cout << "How many books do you want to enter" << endl; // Запитуємо користувача, скільки книг він хоче ввести.
    cin >> N;  // Зчитуємо кількість книг, які потрібно ввести.

    BOOK* SHOP = new BOOK[N];  // Виділяємо динамічну пам'ять для масиву книг з розміром N.

    // Заповнення даних для кожної книги.
    for (int i = 0; i < N; ++i) {
        cout << "Enter book name ";
        cin >> SHOP[i].Name;  // Вводимо назву книги.
        cout << "Enter book author ";
        cin >> SHOP[i].Author; // Вводимо автора книги.
        cout << "Enter month of printing book ";
        cin >> SHOP[i].date_print.month; // Вводимо місяць друку книги.
        cout << "Enter year of printing book ";
        cin >> SHOP[i].date_print.year;  // Вводимо рік друку книги.
        cout << "Enter cost of book ";
        cin >> SHOP[i].Cost;  // Вводимо вартість книги.
        cout << endl;
    }

    sort(SHOP, SHOP + N, compareByAuthorName);  // Сортуємо масив SHOP за назвою книги в алфавітному порядку за допомогою алгоритму sort.

    int year_book;  // Змінна для зберігання введеного року для фільтрації.

    cout << "Please, enter year of books you want to see" << endl; // Запитуємо користувача, книги якого року він хоче побачити.
    cin >> year_book;  // Зчитуємо рік для фільтрації.

    filterByYear(SHOP, N, year_book);  // Викликаємо функцію для фільтрації книг за роком видання.

    delete[] SHOP;  // Звільняємо пам'ять, виділену для масиву SHOP.

    return 0;  // Завершуємо програму з успішним статусом.
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu