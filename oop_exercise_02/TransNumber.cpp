/* —оздать класс TransNumber дл€ работы с трансцендентными числами. “рансцендентное число представлено парой (a, b),
   где a Ц действительна€ часть, b Ц трансцендентна€ часть. “рансцендентна€ часть представл€ет собой действительное число b,
   умноженное на константу sqrt(2). –еализовать арифметические операции (по аналогии с операци€ми над комплексными числами 
   в алгебраической форме), и операции сравнени€ по значению (a + b * sqrt(2)).
   јрифметические операции, а также сравнени€ (больше, меньше и равно) необходимо реализовать в виде перегрузки операторов.
   Ќеобходимо реализовать пользовательский литерал дл€ работы с константами типа TransNumber.*/

#include "TransNumber.h"
#include<cmath>
#include <iostream>

TransNumber::TransNumber() {
    this->real = 0;
    this->trans = 0;
}

void TransNumber::SetValue(long double real, long double trans) {
    this->real = real;
    this->trans = trans;
}

int TransNumber::Print() {
    std::cout << this->real << " + " << this->trans << "*sqrt(2)" << std::endl;
    return 0;
}

//сложение: (a, b) + (c, d) = (a + c, b + d);

TransNumber TransNumber::operator+ (TransNumber x) {
    TransNumber res;
    res.real = this->real + x.real;
    res.trans = this->trans + x.trans;
    return res;
}

//вычитание: (a, b) Ц(c, d) = (a Ц c, b Ц d);

TransNumber TransNumber::operator- (TransNumber x) {
    TransNumber res;
    res.real = this->real - x.real;
    res.trans = this->trans - x.trans;
    return res;
}

//умножениe: (a, b) * (c, d) = (ac + 2bd, ad + bc);

TransNumber TransNumber::operator* (TransNumber x) {
    TransNumber res;
    res.real = this->real * x.real + 2*this->trans * x.trans;
    res.trans = this->real * x.trans + this->trans * x.real;
    return res;
}

//делениe: (a, b) / (c, d) = (ac - 2bd, bc Ц ad) / (c^2 - 2d^2);

TransNumber TransNumber::operator/ (TransNumber x) {
    TransNumber res;
    res.real = (this->real * x.real - 2*this->trans * x.trans) / (x.real * x.real - 2*x.trans * x.trans);
    res.trans = (this->trans * x.real - this->real * x.trans) / (x.real * x.real - 2*x.trans * x.trans);
    return res;
}

bool TransNumber::CheckNull() {
    if ((this->real * this->real - 2 * this->trans * this->trans) == 0) return true;
    else return false;
}

bool TransNumber::operator< (TransNumber x) {
    if ((this->real + (this->trans*sqrt(2))) < (this->real + (this->trans*sqrt(2)))) return true;
}

bool TransNumber::operator> (TransNumber x) {
    if ((this->real + (this->trans*sqrt(2))) > (this->real + (this->trans*sqrt(2)))) return true;
}

bool TransNumber::operator== (TransNumber x) {
    if ((this->real + (this->trans*sqrt(2))) == (this->real + (this->trans*sqrt(2)))) return true;
}

double operator ""_real(long double x) {
    return x;
}

double operator ""_trans(long double x) {
    return x;
}