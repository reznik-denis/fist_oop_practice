// Reznik-Lab08-V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

//Написати функцію, що для квадратного рівняння із заданими коефіцієнтами, повертає значення дискримінант 
//та обчислює корені квадратного рівняння із заданими коефіцієнтами і повертає їх за допомогою 
//параметрів - вказівників та через зовнішні змінні.

#include <iostream>
#include <cmath>
using namespace std;

double solveQuadraticEquation(double a, double b, double c, double* root1, double* root2) {
    double D = b * b - 4 * a * c;

    if (D < 0) {
        cout << "No real roots." << endl;
        return D;
    }

    if (D == 0) {
        *root1 = -b / (2 * a);
        *root2 = *root1;
    }
    else {
        *root1 = (-b + sqrt(D)) / (2 * a);
        *root2 = (-b - sqrt(D)) / (2 * a);
    }

    return D;
}

int main() {
    double a, b, c;
    double root1, root2;

    cout << "Enter coefficients a, b, c for the quadratic equation (ax^2 + bx + c = 0): " << endl;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "The coefficient 'a' must be non-zero for a quadratic equation." << endl;
        return 1;
    }

    double D = solveQuadraticEquation(a, b, c, &root1, &root2);

    cout << "Discriminant (D): " << D << endl;

    if (D >= 0) {
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
