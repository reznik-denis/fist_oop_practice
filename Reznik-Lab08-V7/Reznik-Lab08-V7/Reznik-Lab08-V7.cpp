// Reznik-Lab08-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Написати функцію, що для квадратного рівняння із заданими коефіцієнтами, повертає значення дискримінант 
//та обчислює корені квадратного рівняння із заданими коефіцієнтами і повертає їх за допомогою 
//параметрів - вказівників та через зовнішні змінні.

#include <iostream>  // Підключаємо бібліотеку для роботи з вводу/виводу (cin, cout).
#include <cmath>     // Підключаємо бібліотеку для математичних операцій, таких як sqrt (квадратний корінь).
using namespace std; // Використовуємо стандартний простір імен, щоб не писати std:: перед кожним елементом бібліотек.

double solveQuadraticEquation(double a, double b, double c, double* root1, double* root2) {
    // Обчислення дискримінанту квадратного рівняння (b^2 - 4ac)
    double D = b * b - 4 * a * c;

    // Якщо дискримінант від'ємний, повідомляємо, що корнів немає.
    if (D < 0) {
        cout << "No real roots." << endl; // Виводимо повідомлення про відсутність дійсних коренів.
        return D; // Повертаємо дискримінант, який є від'ємним.
    }

    // Якщо дискримінант дорівнює нулю, рівняння має один корінь.
    if (D == 0) {
        *root1 = -b / (2 * a);   // Обчислюємо єдиний корінь (x = -b / 2a).
        *root2 = *root1;         // Другий корінь рівний першому, оскільки вони однакові.
    }
    else {
        // Якщо дискримінант позитивний, рівняння має два корені.
        *root1 = (-b + sqrt(D)) / (2 * a); // Перший корінь (x1 = (-b + sqrt(D)) / 2a).
        *root2 = (-b - sqrt(D)) / (2 * a); // Другий корінь (x2 = (-b - sqrt(D)) / 2a).
    }

    return D; // Повертаємо дискримінант.
}

int main() {
    double a, b, c;   // Оголошуємо змінні для коефіцієнтів квадратного рівняння.
    double root1, root2;  // Оголошуємо змінні для коренів рівняння.

    cout << "Enter coefficients a, b, c for the quadratic equation (ax^2 + bx + c = 0): " << endl;
    cin >> a >> b >> c; // Вводимо коефіцієнти a, b, c для рівняння.

    // Перевіряємо, чи коефіцієнт a не є нулем (для квадратного рівняння a не може бути нульовим).
    if (a == 0) {
        cout << "The coefficient 'a' must be non-zero for a quadratic equation." << endl;
        return 1; // Якщо a = 0, програма завершиться з кодом помилки 1.
    }

    // Викликаємо функцію для обчислення дискримінанту та коренів.
    double D = solveQuadraticEquation(a, b, c, &root1, &root2);

    cout << "Discriminant (D): " << D << endl;  // Виводимо значення дискримінанту.

    // Якщо дискримінант не від'ємний, виводимо корені рівняння.
    if (D >= 0) {
        cout << "Root 1: " << root1 << endl; // Виводимо перший корінь.
        cout << "Root 2: " << root2 << endl; // Виводимо другий корінь.
    }

    return 0; // Завершення програми з успішним статусом (0).
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
