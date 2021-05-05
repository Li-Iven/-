#pragma once

class Rectangle {
    public:
        Rectangle();
        int check(int, int, int, int);
        void set_value(int, int, int, int);
        int get_value_x1();
        int get_value_y1();
        int get_value_x2();
        int get_value_y2();
        int area();
        int perimetr();
        int movie(int, int);
        double size(double);
        int comparision_area(int);
        int comparision_perimetr(int);
        int intersection(int, int, int, int);
        int unification(int, int, int, int);
    private:
        int x1, y1, x2, y2;
};