// Reznik-Lab03-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Заданий одномірний масив А(10). Знайти найменший по модулі елемент масиву.

#include <iostream> // Підключаємо бібліотеку для роботи з введенням/виведенням
#include <cmath> // Підключаємо бібліотеку для математичних функцій, зокрема для функції abs
using namespace std; // Використовуємо простір імен std для спрощення запису

int main() // Початок головної функції програми
{
    int a[10]; // Оголошуємо масив із 10 цілих чисел
    cout << "Please enter element of array with length 10" << endl; // Виводимо запит на введення елементів масиву

    // Цикл для введення елементів масиву
    for (int i = 0; i < 10; i++) {
        cin >> a[i]; // Зчитуємо елементи масиву з консолі
    }

    int min_value = abs(a[0]); // Ініціалізуємо мінімальне значення абсолютним значенням першого елемента масиву

    // Цикл для пошуку найменшого абсолютного значення у масиві
    for (int i = 1; i < 10; i++) { // Починаємо з другого елемента масиву
        if (abs(a[i]) < min_value) { // Якщо абсолютне значення поточного елемента менше за поточне мінімальне значення
            min_value = abs(a[i]); // Оновлюємо мінімальне значення
        }
    }

    // Виводимо найменше абсолютне значення
    cout << "Minimum absolute value " << min_value << endl;

    return 0; // Завершення програми з успішним статусом
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
