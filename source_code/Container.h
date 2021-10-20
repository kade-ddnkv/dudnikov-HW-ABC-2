#pragma once
#include "RoadTransport.h"
#include <iostream>
#include "TableOutput.h"

class Container {
    int size_;
    int len_;
    // Массив указателей на объекты RoadTransport в куче.
    RoadTransport** storage_ = nullptr;

public:
    explicit Container(int s);
    ~Container();

    // Ввод данных в контейнер из потока.
    void read(std::ifstream& in);
    // Программная генерация данных в контейнер с помощью случайных чисел.
    void generate(int size, bool realistic_random);
    // Вывод данных из контейнера в поток.
    void print(std::ofstream& out);

    // Сортировка данных внутри контейнера методом "пирамидальной сортировки" ("сортировки кучей").
    void heapSort();
    // Проверка, отсортированы ли данные в контейнере.
    bool isSortedByDescendingOrder();
};
