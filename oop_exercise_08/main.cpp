/* Ивенкова Любовь Васильевна, М8О-208Б-19
   https://github.com/Li-Iven/OOP/tree/main/oop_exercise_08
   Вариант 1: треугольник, квадрат, прямоугольник
   Создать приложение, которое будет считывать из стандартного ввода данные фигур, согласно варианту задания, выводить их характеристики на экран и записывать в файл. Фигуры могут задаваться как своими вершинами, так и другими характеристиками (например, координата центра, количество точек и радиус).
   Программа должна:
	1)	Осуществлять ввод из стандартного ввода данных фигур, согласно варианту задания;
	2)	Программа должна создавать классы, соответствующие введенным данных фигур;
	3)	Программа должна содержать внутренний буфер, в который помещаются фигуры. 
	    Для создания буфера допускается использовать стандартные контейнеры STL. 
		Размер буфера задается параметром командной строки. Например, для буфера размером 10 фигур: oop_exercise_08 10
	4)	При накоплении буфера они должны запускаться на асинхронную обработку, после чего буфер должен очищаться;
	5)	Обработка должна производиться в отдельном потоке;
	6)	Реализовать два обработчика, которые должны обрабатывать данные буфера:
	a)	Вывод информации о фигурах в буфере на экран;
	b)	Вывод информации о фигурах в буфере в файл. Для каждого буфера должен создаваться файл с уникальным именем.
	7)	Оба обработчика должны обрабатывать каждый введенный буфер. 
	    Т.е. после каждого заполнения буфера его содержимое должно выводиться как на экран, так и в файл.
	8)	Обработчики должны быть реализованы в виде лямбда-функций и должны хранится в специальном массиве обработчиков. 
	    Откуда и должны последовательно вызываться в потоке – обработчике.
	9)	В программе должно быть ровно два потока (thread). Один основной (main) и второй для обработчиков;
	10)	В программе должен явно прослеживаться шаблон Publish-Subscribe. 
	    Каждый обработчик должен быть реализован как отдельный подписчик.
	11)	Реализовать в основном потоке (main) ожидание обработки буфера в потоке-обработчике. 
	    Т.е. после отправки буфера на обработку основной поток должен ждать, 
		пока поток обработчик выведет данные на экран и запишет в файл.

*/

#include "factory.h"
#include "handler.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

void menu() {
    std::cout << "Enter 0-1 to:" << std::endl;
    std::cout << "1 - add figure" << std::endl;
    std::cout << "0 - exit" << std::endl;
}


int main(int argc, char** argv) {
    size_t buf_size = 2;

    if (argc == 2) {
        std::stringstream argc;
        argc << argv[1];
        argc >> buf_size;
    }

    int choice;
    unsigned long side;
    char r[10];
    Handler handler(buf_size);

    handler.Functions([](const std::list<std::shared_ptr<Figure>>& figs) {
        for (auto& fig : figs) {
            fig->Print();
        }
        });

    static int filename;

    handler.Functions([](const std::list<std::shared_ptr<Figure>>& figs) {
        filename = rand();
        std::string str = std::to_string(filename) + ".txt";
        std::ofstream file(str);
        for (auto items : figs) {
            items->Write(file);
        }
        file.close();
        });

    menu();
    do {
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter name of figure: ";
            std::cin >> r;
            handler.Push(Factory<double>::CreateFigure(r));
            std::cout << "Done!\n";
            break;
        case 0:
            std::cout << "The program is closed, goodbye!\n";
            return false;
            break;
        default:
            std::cout << "Incorrect values! Try again.\n";
            break;
        }
        std::cout << "What's next?\n";
    } while (choice);

    std::cout << std::endl;
    return 0;
}
