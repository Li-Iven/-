/* Ивенкова Любовь Васильевна, М8О-208Б-19

   https://github.com/Li-Iven/oop_exercise_02

   Вариант 15.
   Создать класс TransNumber для работы с трансцендентными числами. Трансцендентное число представлено парой (a, b), 
   где a – действительная часть, b – трансцендентная часть. Трансцендентная часть представляет собой действительное число b, 
   умноженное на константу sqrt(2). Реализовать арифметические операции (по аналогии с операциями над комплексными числами 
   в алгебраической форме), и операции сравнения по значению (a + b * sqrt(2) ).  
   Арифметические операции, а также сравнения (больше, меньше и равно) необходимо реализовать в виде перегрузки операторов.
   Необходимо реализовать пользовательский литерал для работы с константами типа TransNumber.*/

#include <iostream>
#include <algorithm>
#include "TransNumber.h"
using namespace std;

void menu() {
    cout << "Меню:" << endl;
    cout << "1 - Вывести число" << endl;
    cout << "2 - Найти сумму чисел" << endl;
    cout << "3 - Найти разность чисел" << endl;
    cout << "4 - Найти произведение чисел" << endl;
    cout << "5 - Найти частное чисел" << endl;
    cout << "6 - Сравнить числа" << endl;
    cout << "7 - Изменить число" << endl;
    cout << "8 - Вывести меню" << endl;
    cout << "9 - Пример работы литералов" << endl;
    cout << "0 - Выход" << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    long double real, trans;
    TransNumber TransNumber1;
    TransNumber TransNumber2;

    cout << " **Эта программа предназначена для работы с трансцендентными числами. \n \
Трансцендентное число представлено парой (a, b), где a – действительная часть, \n \
b – трансцендентная часть. Трансцендентная часть представляет собой действительное число b, \n \
умноженное на константу sqrt(2).**\n" << endl;

    cout << "Введите действительную часть первого числа: ";
    cin >> real;
    cout << "Введите трансцендентную часть первого числа: ";
    cin >> trans;
    TransNumber1.SetValue(real, trans);
    cout << "Введите действительную часть второго числа: ";
    cin >> real;
    cout << "Введите трансцендентную часть второго числа: ";
    cin >> trans;
    TransNumber2.SetValue(real, trans);

    int a;
    menu();
    cout << ">>>>> ";
    cin >> a;
    while (a != 0) {
        cout << "> ";
        if (a == 1) {
            cout << "Какое число вы хотите вывести- 1 или 2?" << endl;
            int x;
            cin >> x;
            if (x == 1)
                TransNumber1.Print();
            else if (x == 2)
                TransNumber2.Print();
            else cout << "Вы не вводили такое число!";
        }
        if (a == 2) {
            TransNumber res = TransNumber1 + TransNumber2;
            if (res.CheckNull()) cout << "0\n";
            else res.Print();
        }
        if (a == 3) {
            int x;
            TransNumber res;
            cout << "Как вы хотите произвести вычитание: " << endl;
            cout << "1) 1-ое число - 2-ое число" << endl;
            cout << "2) 2-ое число - 1-ое число" << endl;
            cout << ">>> ";
            cin >> x;
            if (x==1) res = TransNumber1 - TransNumber2;
            else res = TransNumber2 - TransNumber1;
            if (res.CheckNull()) cout << "0\n";
            else res.Print();
        }
        if (a == 4) {
            TransNumber res = TransNumber1 * TransNumber2;
            if (res.CheckNull()) cout << "0\n";
            else res.Print();
        }
        if (a == 5) {
            int x;
            TransNumber res;
            cout << "Как вы хотите произвести деление: " << endl;
            cout << "1) 1-ое число / 2-ое число" << endl;
            cout << "2) 2-ое число / 1-ое число" << endl;
            cout << ">>> ";
            cin >> x;
            if (x == 1) {
                if (TransNumber2.CheckNull()) cout << "Деление на 0!" << endl;
                else {
                    res = TransNumber1 / TransNumber2;
                    if (res.CheckNull()) cout << "0\n";
                    else res.Print();
                }
            }
            else {
                if (TransNumber1.CheckNull()) cout << "Деление на 0!" << endl;
                else {
                    res = TransNumber2 / TransNumber1;
                    if (res.CheckNull()) cout << "0\n";
                    else res.Print();
                }
            }     
        }
        if (a == 6) {
            int x;
            cout << "Выберите, что вы хотите проверить:" << endl;
            cout << "1 - Число 1 < Числа 2" << endl;
            cout << "2 - Число 1 > Числа 2" << endl;
            cout << "3 - Число 1 == Числу 2" << endl;
            cout << ">>> ";
            cin >> x;
            if (x == 1)
                if (TransNumber1 < TransNumber2)
                    cout << "Верно";
                else cout << "Не верно";
            if (x == 2) 
                if (TransNumber1 > TransNumber2)
                    cout << "Верно";
                else cout << "Не верно";
            if (x == 3) 
                if (TransNumber1 == TransNumber2)
                    cout << "Верно";
                else cout << "Не верно";
        }
        if (a == 7) {
            cout << "Какое число вы хотите изменить - 1 или 2?" << endl;
            int x;
            cin >> x;
            if (x == 1) {
                cout << "Введите действительную часть числа: ";
                cin >> real;
                cout << "Введите трансцендентную часть числа: ";
                cin >> trans;
                TransNumber1.SetValue(real, trans);
            }
            else if (x == 2) {
                cout << "Введите действительную часть числа: ";
                cin >> real;
                cout << "Введите трансцендентную часть числа: ";
                cin >> trans;
                TransNumber2.SetValue(real, trans);
            }
            else cout << "Вы не вводили такое число!";
        }
        if (a == 8) {
            menu();
        }
        if (a == 9) {
            TransNumber z;
            z.SetValue(2.33_real, 7.999_trans);
            z.Print();
        }
        std::cout << " " << std::endl;
        std::cout << ">>>>> ";
        std::cin >> a;
    }
    std::cout << "Программа завершена!" << std::endl;
    return 0;
}
