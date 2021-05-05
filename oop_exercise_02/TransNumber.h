/* Создать класс TransNumber для работы с трансцендентными числами. Трансцендентное число представлено парой (a, b), 
   где a – действительная часть, b – трансцендентная часть. Трансцендентная часть представляет собой действительное число b, 
   умноженное на константу sqrt(2). Реализовать арифметические операции (по аналогии с операциями над комплексными числами 
   в алгебраической форме), и операции сравнения по значению (a + b * sqrt(2)).  
   Арифметические операции, а также сравнения (больше, меньше и равно) необходимо реализовать в виде перегрузки операторов.
   Необходимо реализовать пользовательский литерал для работы с константами типа TransNumber.*/

#pragma once 

class TransNumber {
  public:
    TransNumber();
    void SetValue(long double, long double);
    int Print();

    //Перегрузка операторов

    TransNumber operator+ (TransNumber);
    TransNumber operator- (TransNumber);
    TransNumber operator* (TransNumber);
    TransNumber operator/ (TransNumber);
    bool CheckNull();

    bool operator< (TransNumber);
    bool operator> (TransNumber);
    bool operator== (TransNumber);

  private:
    double real;
    double trans;

};

double operator ""_real(long double);
double operator ""_trans(long double);

