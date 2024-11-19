// Reznik-Lab01-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

#include <iostream> // Підключаємо бібліотеку для введення/виведення
using namespace std; // Використовуємо простір імен std, щоб спростити звернення до об'єктів std

int main()
{
    auto inch = 2.54; // Оголошуємо змінну для зберігання значення дюйма у сантиметрах (1 дюйм = 2.54 см)
    float sm; // Оголошуємо змінну для зберігання значення довжини у сантиметрах
    cout << "Please write a distance in sm" << endl; // Виводимо запит на введення довжини в сантиметрах
    cin >> sm; // Читаємо значення довжини у сантиметрах від користувача
    float inches = sm / inch; // Обчислюємо значення довжини в дюймах (ділимо довжину в см на 2.54)
    cout << "Distance is " << inches << " inches" << endl; // Виводимо довжину в дюймах

    float new_inches; // Оголошуємо змінну для зберігання значення довжини у дюймах
    cout << "Please write a distance in inches" << endl; // Виводимо запит на введення довжини в дюймах
    cin >> new_inches; // Читаємо значення довжини у дюймах від користувача
    float new_sm = new_inches * inch; // Обчислюємо значення довжини в сантиметрах (множимо дюйми на 2.54)
    cout << "Distance is " << new_sm << " sm"; // Виводимо довжину в сантиметрах

    return 0; // Повертаємо 0, щоб позначити успішне завершення програми
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
