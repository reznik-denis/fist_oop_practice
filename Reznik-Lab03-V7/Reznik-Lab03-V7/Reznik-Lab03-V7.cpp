// Reznik-Lab03-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Для заданого парного числа визначити подвійний факторіал. Наприклад, 6!! = 2 * 4* 6 –> 48.

#include <iostream> // Підключаємо бібліотеку для роботи з введенням/виведенням
using namespace std; // Використовуємо простір імен std для спрощення запису

int main() // Початок головної функції програми
{
    int value; // Оголошуємо змінну для збереження введеного користувачем числа
    cout << "Please write an integer even value for calculate even factorial" << endl;
    // Виводимо повідомлення для користувача з проханням ввести парне ціле число
    cin >> value; // Зчитуємо введене значення з клавіатури та зберігаємо у змінну `value`

    double even_factorial = 1; // Оголошуємо змінну для збереження результату парного факторіалу, початкове значення — 1

    for (int i = value; i > 0; i -= 2) {
        // Цикл обчислення парного факторіалу: починаємо з `value` і зменшуємо на 2, поки не досягнемо 0 або меншого значення
        even_factorial *= i; // Множимо поточне значення на `i` і оновлюємо результат
    }

    cout << "Even factorial " << value << " equal " << even_factorial << endl;
    // Виводимо результат парного факторіалу в форматі: "Even factorial [введене значення] equal [результат]"
    return 0; // Завершення програми з успішним статусом
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu