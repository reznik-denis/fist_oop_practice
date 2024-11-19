// Reznik-Lab02-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Визначити позицію цифри з мінімальним значенням у трьохзначному числі. Нумерація починається з 1. Наприклад, х=413 -> y=позиція [2]=1.

#include <iostream> // Підключаємо бібліотеку для роботи з введенням/виведенням
using namespace std; // Використовуємо простір імен std для спрощення запису

int main() // Оголошення функції main, яка повертає ціле значення
{
    int value; // Змінна для збереження введеного користувачем числа
    int digit; // Змінна для збереження поточної цифри
    cout << "Please write an integer value, as example xxx" << endl;// Вивід інструкції для користувача з проханням ввести ціле число формату xxx
    cin >> value; // Зчитування введеного значення з клавіатури та збереження у змінну `value`

    digit = value % 10; // Визначаємо останню цифру числа (остача від ділення на 10)
    int position = 3; // Початкова позиція останньої цифри (задається як 3)
    value /= 10; // Видаляємо останню цифру числа (ділимо на 10 і залишаємо цілу частину)

    for (int i = 2; i > 0; i--) {// Цикл, який проходить по залишених цифрах числа (зменшуємо позицію з 2 до 1)
        int new_digit = value % 10; // Отримуємо наступну цифру числа
        if (new_digit < digit) { // Якщо нова цифра менша за поточну мінімальну цифру
            digit = new_digit; // Оновлюємо мінімальну цифру
            position = i; // Змінюємо позицію на поточну позицію цифри
        }
        value /= 10; // Видаляємо оброблену цифру (ділимо число на 10)
    }

    cout << "Position " << position << ". Digit value " << digit << endl;// Виводимо позицію та значення найменшої цифри
    return 0; // Завершення виконання функції
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu