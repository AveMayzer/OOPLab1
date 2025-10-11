#pragma once
#include "number.h"
#include "Array.h"

class Polynom
{
private:
    Array* roots;          // массив корней
    Array* coefficients;   // массив коэффициентов
    number an;             // ведущий коэффициент
    int degree;            // степень полинома

    void calculateCoefficients(); // вычисление коэффициентов по корням

public:
    Polynom();                              // конструктор по умолчанию (0-й полином)
    Polynom(int n, number leadingCoeff);    // конструктор для полинома n-й степени
    ~Polynom();

    void inputPolynomial();                 // ввод полинома
    void changeLeadingCoefficient(number newAn); // изменение ведущего коэффициента
    void changeRoot(int index, number newRoot);  // изменение корня по индексу
    number calculateValue(number x);        // вычисление значения в точке x
    void resize(int newDegree);            // изменение размерности
    
    void printFactorForm();                // вывод в факторной форме (форма 2)
    void printStandardForm();              // вывод в стандартной форме (форма 1)
    
    int getDegree() const;                 // получение степени
    Array* getRoots() const;               // получение корней (только чтения)
    Array* getCoefficients() const;        // получение коэффициентов (только чтения)
    number getLeadingCoefficient() const;  // получение ведущего коэффициента
};

