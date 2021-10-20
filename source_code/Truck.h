#pragma once
#include "RoadTransport.h"
#include "TableOutput.h"
#include "Random.h"
#include <fstream>

class Truck: public RoadTransport {
    // Грузоподъемность (в кг).
    int load_capacity_;

public:
    virtual ~Truck() {}
    // Ввод параметров грузовика из потока.
    virtual void read(std::ifstream& in);
    // Программная генерация параметров грузовика.
    virtual void generate(bool realistic_random);
    // Вывод параметров грузовика в поток.
    virtual void print(std::ofstream& out);
};
