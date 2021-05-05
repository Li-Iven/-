#include "Rectangle.h"
#include <iostream>
#include <algorithm>


Rectangle::Rectangle(){
}

int check(int x1, int y1, int x2, int y2) {
    if (x1==x2 || y1==y2) return -1;
    else if (x1>x2 || y1>y2) return -2;
}

void Rectangle::set_value(int x1, int y1, int x2, int y2){
    Rectangle::x1 = x1;
    Rectangle::y1 = y1;
    Rectangle::x2 = x2;
    Rectangle::y2 = y2;
}

int Rectangle::get_value_x1(){
    int a = Rectangle::x1;
    return a;  
}

int Rectangle::get_value_y1(){
    int a = Rectangle::y1;
    return a;  
}

int Rectangle::get_value_x2(){
    int a = Rectangle::x2;
    return a;  
}

int Rectangle::get_value_y2(){
    int a = Rectangle::y2;
    return a;  
}

int Rectangle::area(){
    int s = (Rectangle::x2 - Rectangle::x1)*(Rectangle::y2 - Rectangle::y1);
    return s;
}

int Rectangle::perimetr(){
    int p = 2*(Rectangle::x2 - Rectangle::x1)+\
    +2*(Rectangle::y2 - Rectangle::y1);
    return p;
}

int Rectangle::movie(int x, int y){
    Rectangle::set_value(Rectangle::x1+x,Rectangle::y1+y,\
        Rectangle::x2+x,Rectangle::y2+y); 
        return 0;
}

double Rectangle::size(double d){
    Rectangle::set_value(Rectangle::x1,Rectangle::y1,\
        (Rectangle::x2)*d,Rectangle::y2*d); 
        return 0;
}

int Rectangle::comparision_area(int n){
    int m = Rectangle::area();
    if (m > n) std::cout << 1;
    if (m < n) std::cout << 2;
    if (m == n) std::cout << "Они равны";
    return 0;
}

int Rectangle::comparision_perimetr(int n){
    int m = Rectangle::perimetr();
    if (m > n) std::cout << 1;
    if (m < n) std::cout << 2;
    if (m == n) std::cout << "Они равны";
    return 0;
}

int Rectangle::intersection(int x3, int y3, int x4, int y4){
    if (Rectangle::y1 >= y4 || y3 >= Rectangle::y2 || x4 <= Rectangle::x1 || Rectangle::x2 <= x3) 
        std::cout << "Прямоуголники не пересекаются";
    else {
        int d1 = std::max(Rectangle::x1, x3);
        int h1 = std::max(Rectangle::y1, y3);
        int d2 = std::min(Rectangle::x2, x4);
        int h2 = std::min(Rectangle::y2, y4);
        std::cout << d1 << " " << h1 << " " << d2 << " " << h2 <<"\n";  
    }
    return 0;
}

int Rectangle::unification(int x3, int y3, int x4, int y4){
    int d1 = std::min (Rectangle::x1, x3);
    int h1 = std::min(Rectangle::y1, y3);
    int d2 = std::max(Rectangle::x2, x4);
    int h2 = std::max(Rectangle::y2, y4);
    std::cout << d1 << " " << h1 << " " << d2 << " " << h2 <<"\n";
    return 0;
}