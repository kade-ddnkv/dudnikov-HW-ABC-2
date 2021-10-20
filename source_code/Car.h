#pragma once
#include "RoadTransport.h"
#include "TableOutput.h"
#include "Random.h"
#include <fstream>

class Car : public RoadTransport {
    // Максимальная скорость (км/час).
    int16_t max_speed_;

public:
    virtual ~Car() {}
    // Ввод параметров машины из потока.
    virtual void read(std::ifstream& in);
    // Программная генерация параметров машины.
    virtual void generate(bool realistic_random);
    // Вывод параметров машины в поток.
    virtual void print(std::ofstream& out);
};
