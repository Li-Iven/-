#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Figure {

public:
    virtual ~Figure() {};
    virtual void InputCoordinates() = 0;
    virtual void GeomCenter() = 0;
    virtual double Area() = 0;
    virtual bool Check() = 0;
    virtual void Print() = 0;
};

class Trapeze : public Figure { //ориентаци€ точек по х
public: 
    Trapeze() {
        CoordinatesX.resize(4);
        CoordinatesY.resize(4);
    }
    ~Trapeze() {};
    void InputCoordinates() {
        std::cout << "\n¬ведите координаты трапеции (от самой левой до самой правой)\n";
        for (int i = 0; i < 4; i++) {
            std::cin >> CoordinatesX[i] >> CoordinatesY[i];
        }
    }
    double distance(int x1, int y1, int x2, int y2) {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }
    bool Check() {
        double LateralSide1 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[1], CoordinatesY[1]);
        double LateralSide2 = distance(CoordinatesX[2], CoordinatesY[2], CoordinatesX[3], CoordinatesY[3]);
        if ((CoordinatesY[3] - CoordinatesY[0]) != 0 || (CoordinatesY[2] - CoordinatesY[1]) != 0 || (LateralSide1 != LateralSide2) || LateralSide1==0 || LateralSide2==0)
            return false;
        else return true;
    }
    void GeomCenter() {
        double centerX = 0, centerY = 0;
        for (int i = 0; i < 4; i++) {
            centerX += CoordinatesX[i];
        }
        for (int i = 0; i < 4; i++) {
            centerY += CoordinatesY[i];
        }
        std::cout << "(" << centerX/4 << "; " << centerY/4 << ")\n";
    }
    void Print() {
        for (int i = 0; i < 4; i++) {
            std::cout << "(" << CoordinatesX[i] << "; " << CoordinatesY[i] << ")\n";
        }
    }
    double Area() {
        int footing1 = CoordinatesX[3] - CoordinatesX[0];
        int footing2 = CoordinatesX[2] - CoordinatesX[1];
        int high = abs(CoordinatesY[3] - CoordinatesY[1]);
        double area = 0.5 * (footing1+footing2) * high;
        return area;
    }
protected:
    std::vector<int> CoordinatesX;
    std::vector<int> CoordinatesY;
};

class Rhombus : public Figure { //ориентаци€ точек по у
public:
    Rhombus() {
        CoordinatesX.resize(4);
        CoordinatesY.resize(4);
    }
    ~Rhombus() {};
    void InputCoordinates() {
        std::cout << "\n¬ведите координаты ромба (по часовой стрелке)\n";
        for (int i = 0; i < 4; i++) {
            std::cin >> CoordinatesX[i] >> CoordinatesY[i];
        }
    }
    double distance(int x1, int y1, int x2, int y2) {
        return sqrt((x2 - x1)* (x2 - x1) + (y2 - y1)* (y2 - y1));
    }
    bool Check() {
        double LateralSide0 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[1], CoordinatesY[1]);
        double LateralSide1 = distance(CoordinatesX[1], CoordinatesY[1], CoordinatesX[2], CoordinatesY[2]);
        double LateralSide2 = distance(CoordinatesX[2], CoordinatesY[2], CoordinatesX[3], CoordinatesY[3]);
        if (LateralSide0==LateralSide1==LateralSide2)
            return true;
        else return false;
    }
    void GeomCenter() {
        double centerX = 0, centerY = 0;
        for (int i = 0; i < 4; i++) {
            centerX += CoordinatesX[i];
        }
        for (int i = 0; i < 4; i++) {
            centerY += CoordinatesY[i];
        }
        std::cout << "(" << centerX/4 << "; " << centerY/4 << ")\n";
    }
    void Print() {
        for (int i = 0; i < 4; i++) {
            std::cout << "(" << CoordinatesX[i] << "; " << CoordinatesY[i] << ")\n";
        }
    }
    double Area() {
        double diagonal1 = distance(CoordinatesX[1], CoordinatesY[1], CoordinatesX[3], CoordinatesY[3]);
        double diagonal2 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[2], CoordinatesY[2]);
        double area = 0.5 * diagonal1 * diagonal2;
        return area;
    }
protected:
    std::vector<int> CoordinatesX;
    std::vector<int> CoordinatesY;
};

class Pentagon : public Figure {
public:
    Pentagon() {
        CoordinatesX.resize(5);
        CoordinatesY.resize(5);
    }
    ~Pentagon() {};

    void InputCoordinates() {
        std::cout << "\n¬ведите координаты фигуры\n";
        for (int i = 0; i < 5; i++) {
            std::cin >> CoordinatesX[i] >> CoordinatesY[i];
        }
    }
    void GeomCenter() {
        double centerX = 0, centerY = 0;
        for (int i = 0; i < 5; i++) {
            centerX += CoordinatesX[i];
        }
        for (int i = 0; i < 5; i++) {
            centerY += CoordinatesY[i];
        }
        std::cout << "(" << centerX/5 << "; " << centerY/5 << ")\n";
    }
    bool Check() { 
        double side1 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[1], CoordinatesY[1]);
        double side2 = distance(CoordinatesX[1], CoordinatesY[1], CoordinatesX[2], CoordinatesY[2]);
        double side3 = distance(CoordinatesX[2], CoordinatesY[2], CoordinatesX[3], CoordinatesY[3]);
        double side4 = distance(CoordinatesX[3], CoordinatesY[3], CoordinatesX[4], CoordinatesY[4]);
        double side5 = distance(CoordinatesX[4], CoordinatesY[4], CoordinatesX[0], CoordinatesY[0]);

        if (side1 != 0 && side2 != 0 && side3 != 0 && side4 != 0 && side5 != 0) return true;
        else return false;
    }
    void Print() {
        for (int i = 0; i < 5; i++) {
            std::cout << "(" << CoordinatesX[i] << "; " << CoordinatesY[i] << ")\n";
        }
    }
    double distance(int x1, int y1, int x2, int y2) {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }
    double Area() {
        double d1 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[2], CoordinatesY[2]);
        double d2 = distance(CoordinatesX[2], CoordinatesY[2], CoordinatesX[4], CoordinatesY[4]);
        double side1 = distance(CoordinatesX[0], CoordinatesY[0], CoordinatesX[1], CoordinatesY[1]);
        double side2 = distance(CoordinatesX[1], CoordinatesY[1], CoordinatesX[2], CoordinatesY[2]);
        double side3 = distance(CoordinatesX[2], CoordinatesY[2], CoordinatesX[3], CoordinatesY[3]);
        double side4 = distance(CoordinatesX[3], CoordinatesY[3], CoordinatesX[4], CoordinatesY[4]);
        double side5 = distance(CoordinatesX[4], CoordinatesY[4], CoordinatesX[0], CoordinatesY[0]);

        double p1 = 0.5 * (d1 + side1 + side2);
        double p2 = 0.5 * (d2 + side3 + side4);
        double p3 = 0.5 * (d1 + d2 + side5);
        double area1 = sqrt(p1*(p1-d1)*(p1-side1)*(p1-side2));
        double area2 = sqrt(p2*(p2-d2)*(p2-side3)*(p2-side4));
        double area3 = sqrt(p3*(p3-d1)*(p3-d2)*(p3-side5));

        return area1 + area2 + area3;
    }
protected:
    std::vector<int> CoordinatesX;
    std::vector<int> CoordinatesY;
};