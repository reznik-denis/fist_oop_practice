// Reznik-Lab05-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Дано двовимірний масив з N*М цілих чисел. Виконати дзеркальне відображення матриці по вертикалі (необов’язково квадратної матриці).

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int row = 0;
    int cols = 0;
    cout << "Enter size of array N M " << endl;
    cin >> row >> cols;

    int** mas = new int* [row];
    for (int i = 0; i < row; i++) {
        mas[i] = new int[cols];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            mas[i][j] = rand() % 100;
        }
    }
    cout << "You have an array size " << row << "*" << cols << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int old = mas[i][j];
            mas[i][j] = mas[i][cols - j - 1];
            mas[i][cols - j - 1] = old;
        }
    }

    cout << "Your array after vertical mirror " << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mas[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
