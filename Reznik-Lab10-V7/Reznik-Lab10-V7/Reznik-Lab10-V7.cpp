// Reznik-Lab10-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Варіант 7.
//Написати клас  BOOK, яка містить  наступні поля :
//-Name  – назва книги;
//-Avtor – автори книги;
//-Data –дата друку;
//-Cost - ціна книги.

#include <iostream>  // Підключаємо бібліотеку для роботи з введенням-виведенням в консоль.
#include <string>    // Підключаємо бібліотеку для роботи з рядковими даними.
using namespace std; // Використовуємо простір імен std для спрощення запису стандартних функцій.

class BOOK { // Оголошуємо клас BOOK
private:
    string Name;   // Назва книги (захищене поле)
    string Author; // Автор книги (захищене поле)
    string Date;   // Дата публікації книги (захищене поле)
    double Cost;   // Вартість книги (захищене поле)

public:
    // Конструктор за замовчуванням, ініціалізує всі поля до порожніх рядків або 0.0.
    BOOK() : Name(""), Author(""), Date(""), Cost(0.0) {}

    // Конструктор з параметрами для створення об'єкту з заданими значеннями
    BOOK(string name, string author, string date, double cost)
        : Name(name), Author(author), Date(date), Cost(cost) {
    }

    // Деструктор, який виводить повідомлення при знищенні об'єкта.
    ~BOOK() {
        cout << "Destructor called for book: " << Name << endl;
    }

    // Гетер для отримання значення Name.
    void setName(const string& name) {
        Name = name;
    }

    // Сетер для встановлення значення Name.
    string getName() const {
        return Name;
    }

    // Гетер для отримання значення Author.
    void setAuthor(const string& author) {
        Author = author;
    }

    // Сетер для встановлення значення Author.
    string getAuthor() const {
        return Author;
    }

    // Гетер для отримання значення Date.
    void setDate(const string& date) {
        Date = date;
    }

    // Сетер для встановлення значення Date.
    string getDate() const {
        return Date;
    }

    // Гетер для отримання значення Cost.
    void setCost(double cost) {
        Cost = cost;
    }

    // Сетер для встановлення значення Cost.
    double getCost() const {
        return Cost;
    }

    // Функція для введення інформації про книгу з консолі.
    void inputInfo() {
        cout << "Enter book name: ";
        getline(cin, Name); // Зчитуємо цілий рядок з можливістю зчитування пробілів
        cout << "Enter book author: ";
        getline(cin, Author);
        cout << "Enter publication date (MM.YYYY): ";
        getline(cin, Date);
        cout << "Enter book cost: ";
        cin >> Cost;
        cin.ignore(); // Очищаємо буфер після зчитування числового вводу
    }

    // Функція для виводу інформації про книгу в консоль.
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
    cin.ignore(); // Очищаємо буфер після зчитування числового вводу
    BOOK* books = new BOOK[n]; // Динамічно виділяємо пам'ять для масиву книг

    // Заповнення масиву книг
    for (int i = 0; i < n; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        books[i].inputInfo(); // Викликаємо метод для зчитування інформації про книгу
    }

    cout << "\nBooks details:" << endl;

    // Вивід інформації про книги
    for (int i = 0; i < n; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        books[i].displayInfo(); // Викликаємо метод для виводу інформації про книгу
    }

    cout << "What number of book do you want to change?" << endl;
    int num;
    cin >> num;

    while (true) { // Цикл для змінювання властивостей книг
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
            cin.ignore(); // Очищаємо буфер після зчитування попереднього значення
            string name; // Оголошуємо змінну для запису нового значення
            getline(cin, name); // Зчитуємо цілий рядок
            books[num].setName(name); //Встановлюємо нове значення поля
            break;
        }
        case 2: {
            cout << "Enter author" << endl;
            cin.ignore();
            string author;
            getline(cin, author);
            books[num].setAuthor(author);
            break;
        }
        case 3: {
            cout << "Enter date" << endl;
            cin.ignore();
            string date;
            getline(cin, date);
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
            books[num].displayInfo(); //Викликаємо метод для виведення книги з новленими полями
            return 0; //Виходимо з циклу
        }
        default:
            cout << "You enter wrong choice" << endl;
        }
    }

    delete[] books; // Звільнення динамічної пам'яті перед завершенням програми
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
