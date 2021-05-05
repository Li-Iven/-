/*  Ивенкова Любовь Васильевна, М8О-208Б-19

    https://github.com/Li-Iven/oop_exercise_03

    Вариант 28: Трапеция, Ромб, 5-угольник

Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. 
Все классы должны поддерживать набор общих методов:
1.  Вычисление геометрического центра фигуры;
2.  Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3.  Вычисление площади фигуры.

Создать программу, которая позволяет:
•   Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
•   Сохранять созданные фигуры в динамический массив std::vector<Figure*>.
•   Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, 
    координаты вершин и площадь.
•   Необходимо уметь вычислять общую площадь фигур в массиве.
•   Удалять из массива фигуру по индексу.
*/

#include <iostream>
#include <vector>
#include "Figure.h"

using namespace std;

void menu() {
    cout << "Меню:" << endl;
    cout << "1 - Ввести фигуру" << endl;
    cout << "2 - Вывести координаты фигуры" << endl;
    cout << "3 - Удалить фигуру по индексу" << endl;
    cout << "4 - Найти геометрический центр фигуры" << endl;
    cout << "5 - Найти площадь фигуры" << endl;
    cout << "6 - Найти геом. центры всех введённых фигур" << endl;
    cout << "7 - Найти площади всех введённых фигур" << endl;
    cout << "8 - Вывести координаты всех введённых фигур" << endl;
    cout << "9 - Найти общую площадь всех введённых фигур" << endl;
    cout << "10 - Меню" << endl;
    cout << "0 - Выход" << endl;
}


int main()
{
    setlocale(LC_ALL, "RUS");

    vector<Figure*> figures;
    Figure* figure;

    double sum;

    int x;
    menu();
    cout << ">>>>> ";
    while (cin >> x) {
        switch (x) {
        case 0:
            return 0;
            break;
        case 1:
            cout << "\nКакую фигуру вы хотите ввести?\n 1. Трапеция\n 2. Ромб\n 3. 5-угольник\n\n>>> ";
            int type;
            cin >> type;
            switch (type) {
            case 1:
                figure = new Trapeze();
                figure->InputCoordinates();
                if (figure->Check()) {
                    figures.push_back(figure);
                    cout << "\nФигура введена\n";
                }
                else cout << "Это не равносторонняя трапеция!\n";
                break;
            case 2:
                figure = new Rhombus();
                figure->InputCoordinates();
                if (figure->Check()) {
                    figures.push_back(figure);
                    cout << "\nФигура введена\n";
                }
                else cout << "Это не ромб!\n";
                break;
            case 3:
                figure = new Pentagon();
                figure->InputCoordinates();
                if (figure->Check()) {
                    figures.push_back(figure);
                    cout << "\nФигура введена\n";
                }
                else cout << "Это не 5-угольник!\n";
                break;
            default:
                cout << "Всего три вида фигур!\n";
                break;
            }
            break;
        case 2:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else figures[figures.size() - 1]->Print();
            break;
        case 3:
            size_t index;
            cout << "\nВведите индекс эл-та, который вы хотите удалить:\n\n>>> ";
            cin >> index;
            if (index < figures.size()) {
                figures.erase(figures.begin() + index);
                cout << "\nЭл-т удалён!\n";
            }
            else cout << "Индекс больше количества введённых фигур!\n";
            break;
        case 4:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else figures[figures.size() - 1]->GeomCenter();
            break;
        case 5:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else cout << figures[figures.size() - 1]->Area();
            break;
        case 6:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else {
                for (size_t i = 0; i < figures.size(); i++) {
                    cout << "\nГеом. центр " << i + 1 << " фигуры:\n";
                    figures[i]->GeomCenter();
                    cout << "\n";
                }
            }
            break;
        case 7:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else {
                for (size_t i = 0; i < figures.size(); i++) {
                    cout << "\nПлощадь " << i + 1 << " фигуры:\n";
                    cout << figures[i]->Area() << "\n";
                }
            }
            break;
        case 8:
            if (figures.size() == 0) cout << "Нет введённых фигур\n";
            else {
                for (size_t i = 0; i < figures.size(); i++) {
                    cout << "\nКоординаты " << i + 1 << " фигуры:\n";
                    figures[i]->Print();
                    cout << "\n";
                }
            }
            break;
        case 9:
            sum = 0;
            for (auto ptr : figures) {
                sum += ptr->Area();
            }
            cout << sum;
            break;
        case 10:
            menu();
            break;
        default: 
            cout << "Неизвестная команда!\n";
            menu();
            break;
        }
        std::cout << " " << std::endl;
        std::cout << ">>>>> ";
    }
    cout << "Программа завершена!" << std::endl;
    return 0;
}
