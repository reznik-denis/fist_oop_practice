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


#include <iostream> // Підключаємо бібліотеку для роботи з введенням і виведенням у консоль (cin, cout, endl).
#include <algorithm> // Бібліотека для роботи з алгоритмами, такими як sort(), find(), і т. д.
#include <string> // Бібліотека для роботи з рядками типу std::string.
#include <fstream> // Бібліотека для роботи з файлами (читання та запис).
using namespace std; // Директива, що дозволяє не писати "std::" перед стандартними об'єктами та функціями.

struct Date { // Оголошення структури для збереження дати друку книги.
    string month; // Змінна для місяця друку (назва місяця у вигляді рядка, наприклад, "January").
    int year; // Змінна для року друку (ціле число, наприклад, 2023).
};

struct BOOK { // Оголошення структури для збереження інформації про книгу.
    string Name; // Назва книги.
    string Author; // Ім'я автора книги.
    struct Date date_print; // Структура Date для збереження дати друку книги.
    int Cost; // Ціна книги у вигляді цілого числа.
};

bool compareByAuthorName(const BOOK& a, const BOOK& b) {
    return a.Name < b.Name; // Функція порівнює назви книг для сортування у порядку зростання.
}

void writeToFile(BOOK* group, int N, const string& filename) {
    ofstream file(filename); // Відкриваємо файл для запису.
    if (file.is_open()) { // Перевіряємо, чи файл відкритий успішно.
        file << N << endl; // Записуємо кількість книг у файл.
        for (int i = 0; i < N; ++i) { // Перебираємо масив книг.
            file << group[i].Name << "|" // Записуємо назву книги та роздільник.
                << group[i].Author << "|" // Записуємо автора та роздільник.
                << group[i].date_print.month << "|" // Записуємо місяць друку.
                << group[i].date_print.year << "|" // Записуємо рік друку.
                << group[i].Cost << endl; // Записуємо вартість книги.
        }
        file.close(); // Закриваємо файл після запису.
        cout << "Data write success! File: " << filename << endl; // Повідомлення про успішний запис.
    }
    else {
        cout << "Error opening file!" << endl; // Помилка відкриття файлу.
    }
}

void readFromFile(BOOK*& group, int& N, const string& filename) {
    ifstream file(filename); // Відкриваємо файл для читання.
    if (file.is_open()) { // Перевіряємо, чи файл відкрився успішно.
        file >> N; // Зчитуємо кількість книг із файлу.
        file.ignore(); // Пропускаємо символ нового рядка.
        delete[] group; // Звільняємо пам'ять, якщо масив уже існував.
        group = new BOOK[N]; // Виділяємо нову пам'ять для книг.
        for (int i = 0; i < N; ++i) {
            string line;
            getline(file, line); // Зчитуємо весь рядок із файлу.
            size_t pos = 0; // Індикатор для пошуку роздільників.

            // Розбиваємо рядок на частини (назва, автор, дата, вартість).
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

            group[i].Cost = stoi(line); // Зчитуємо вартість книги.
        }
        file.close(); // Закриваємо файл після зчитування.
        cout << "Data read success! File: " << filename << endl; // Повідомлення про успішне зчитування.
    }
    else {
        cout << "Error opening file!" << endl; // Помилка відкриття файлу.
    }
}

void filterByYear(BOOK* SHOP, int N, int year_book) {
    cout << "Books printed in " << year_book << ":\n"; // Виводимо заголовок для фільтру.
    for (int i = 0; i < N; ++i) { // Перебираємо всі книги.
        if (SHOP[i].date_print.year >= year_book) { // Якщо рік друку більший або дорівнює заданому.
            cout << "Name: " << SHOP[i].Name << ", Author: " << SHOP[i].Author
                << ", Year: " << SHOP[i].date_print.year << ", Month: " << SHOP[i].date_print.month
                << ", Cost: " << SHOP[i].Cost << endl; // Виводимо дані про книгу.
        }
    }
}

void displayBooks(BOOK* group, int n) {
    cout << "All books in memory:" << endl; // Заголовок для списку книг.
    for (int i = 0; i < n; ++i) { // Перебираємо масив книг.
        cout << i + 1 << ". Name: " << group[i].Name
            << ", Author: " << group[i].Author
            << ", Date publication: " << group[i].date_print.month
            << " " << group[i].date_print.year
            << " year, Cost:" << group[i].Cost; // Виводимо деталі кожної книги.

        cout << endl; // Переходимо до нового рядка після кожної книги.
    }
}

int main() {
    int N = 0; // Змінна для кількості книг.
    BOOK* SHOP = nullptr; // Динамічний масив книг, спочатку порожній.
    string filename = "shopCatalog.txt"; // Назва файлу для запису/читання.

    while (true) { // Нескінченний цикл для роботи меню.
        cout << "\nMenu:\n"; // Виводимо меню.
        cout << "1. Enter books\n";
        cout << "2. Show all books\n";
        cout << "3. Show books by year\n";
        cout << "4. Write books in file\n";
        cout << "5. Read books from file\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice; // Зчитуємо вибір користувача.

        switch (choice) { // Обробляємо вибір за допомогою конструкції switch.
        case 1: { // Введення книг.
            cout << "How many books do you want to enter" << endl;
            cin >> N;
            delete[] SHOP; // Очищуємо пам'ять для попередніх книг.
            SHOP = new BOOK[N]; // Виділяємо пам'ять для нового масиву.

            for (int i = 0; i < N; ++i) { // Зчитуємо дані для кожної книги.
                cout << "Enter book name ";
                cin.ignore(); // Очищаємо буфер після попереднього вводу.
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

            sort(SHOP, SHOP + N, compareByAuthorName); // Сортуємо книги за назвою.
            break;
        }
        case 2:
            displayBooks(SHOP, N); // Виведення всіх книг.
            break;
        case 3:
            int year_book;
            cout << "Please, enter year of books you want to see" << endl;
            cin >> year_book;
            filterByYear(SHOP, N, year_book); // Фільтруємо книги за роком.
            break;
        case 4:
            writeToFile(SHOP, N, filename); // Запис книг у файл.
            break;
        case 5:
            readFromFile(SHOP, N, filename); // Читання книг із файлу.
            break;
        case 6:
            delete[] SHOP; // Очищення пам'яті перед завершенням програми.
            cout << "Exit out." << endl;
            return 0; // Завершення програми.
        default:
            cout << "Wrong choose. Try again." << endl; // Повідомлення про помилковий вибір.
        }
    }

    return 0; // Завершення функції main.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu