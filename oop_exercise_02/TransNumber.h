/* ������� ����� TransNumber ��� ������ � ���������������� �������. ��������������� ����� ������������ ����� (a, b), 
   ��� a � �������������� �����, b � ��������������� �����. ��������������� ����� ������������ ����� �������������� ����� b, 
   ���������� �� ��������� sqrt(2). ����������� �������������� �������� (�� �������� � ���������� ��� ������������ ������� 
   � �������������� �����), � �������� ��������� �� �������� (a + b * sqrt(2)).  
   �������������� ��������, � ����� ��������� (������, ������ � �����) ���������� ����������� � ���� ���������� ����������.
   ���������� ����������� ���������������� ������� ��� ������ � ����������� ���� TransNumber.*/

#pragma once 

class TransNumber {
  public:
    TransNumber();
    void SetValue(long double, long double);
    int Print();

    //���������� ����������

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

