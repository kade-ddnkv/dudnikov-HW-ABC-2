#include <iostream>
#include <cstring>
#include "Container.h"
#include "Car.h"
#include <chrono>
#include <ctime>

// Метод помощи, вызываемый при команде "ABCproject -help"
void help() {
    std::cout << "Two options of starting program:\n"
              << "Input data from file:\n"
              << "    command -f infile outfile\n"
              << "Generate random data:\n"
              << "    command -r number(from 1 to 10000) realistic_random(1 or 0) outfile";
}

void errMessageIncorrectCommand() {
    std::cout << "incorrect command line!\n"
              << "Expected:\n"
              << "    command -f infile outfile\n"
              << "Or:\n"
              << "    command -r number(from 1 to 10000) realistic_random(1 or 0) outfile";
}

void errMessageIncorrectNumber() {
    std::cout << "incorrect number!\n"
              << "Set number from 1 to 10000.";
}

void errMessageIncorrectRealisticRandom() {
    std::cout << "incorrect boolean value!\n"
              << "Set realistic_random qualifier to 1 or 0.";
}

// Основной метод.
int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // Обновление сида для случайных чисел.
    srand(time(nullptr));

    if (argc < 2 || (argc >= 2 && !strcmp(argv[1], "-help"))) {
        help();
        return 0;
    }

    std::cout << "Started!"
              << "\n";
    std::ofstream out;

    // Инициализация контейнера.
    Container c(10000);


    // Заполнение контейнера.

    auto begin = std::chrono::steady_clock::now();

    if (!strcmp(argv[1], "-f") && argc == 4) {
        std::ifstream in(argv[2]);
        c.read(in);
        in.close();
        out.open(argv[3]);
    } else if (!strcmp(argv[1], "-r") && argc == 5) {
        int size = atoi(argv[2]);
        bool realistic_random = atoi(argv[3]);
        if (size < 1 || size > 10000) {
            errMessageIncorrectNumber();
            return 2;
        } else if (strcmp(argv[3], "0") && strcmp(argv[3], "1")) {
            errMessageIncorrectRealisticRandom();
            return 3;
        }
        c.generate(size, realistic_random);
        out.open(argv[4]);
    } else {
        errMessageIncorrectCommand();
        return 1;
    }

    // Вывод времени считывания/генерации данных.
    auto end_of_read = std::chrono::steady_clock::now();
    std::cout
        << "Read time = " << std::fixed << std::setprecision(3)
        << std::chrono::duration_cast<std::chrono::microseconds>(end_of_read - begin).count() /
               1000000.0
        << "[s]\n";

    // Основная функция программы.

    printTitle("Entered data", out);
    c.print(out);

    out << "\n";

    c.heapSort();

    printTitle("After heap sort", out);
    out << "Is correctly sorted: " << (c.isSortedByDescendingOrder() ? "YES" : "NO") << "\n";
    c.print(out);

    // Вывод времени сортировки данных.
    auto end_of_sort = std::chrono::steady_clock::now();
    std::cout << "Sort time = " << std::fixed << std::setprecision(3)
              << std::chrono::duration_cast<std::chrono::microseconds>(end_of_sort - end_of_read)
                         .count() /
                     1000000.0
              << "[s]\n";

    // Очищение данных.
    out.close();
    // Деструктор контейнера вызовется автоматически.

    std::cout << "Finished!"
              << "\n";
    return 0;
}
