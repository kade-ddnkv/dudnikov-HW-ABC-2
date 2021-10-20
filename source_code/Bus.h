#pragma once
#include "RoadTransport.h"
#include "TableOutput.h"
#include "Random.h"
#include <fstream>

class Bus : public RoadTransport {
    // Пассажировместимость.
    int16_t passenger_capacity_;

public:
    virtual ~Bus() {}
    // Ввод параметров автобуса из потока.
    virtual void read(std::ifstream& in);
    // Программная генерация параметров автобуса.
    virtual void generate(bool realistic_random);
    // Вывод параметров автобуса в поток.
    virtual void print(std::ofstream& out);
};
