#include "RoadTransport.h"
#include "Truck.h"
#include "Bus.h"
#include "Car.h"

RoadTransport* RoadTransport::staticRead(std::ifstream& in) {
    char type;
    in >> type;

    RoadTransport* rt;
    switch (type) {
        case 't':
            rt = new Truck;
            break;
        case 'b':
            rt = new Bus;
            break;
        case 'c':
            rt = new Car;
            break;
        default:
            throw std::invalid_argument(
                "Unsupported road transport.\n"
                "Check for symbol <" +
                std::string(type, 1) +
                "> in input file.\n"
                "Or delete blank lines in the end of file");
    }
    rt->read(in);
    return rt;
}

void RoadTransport::read(std::ifstream& in) {
    in >> fuel_tank_capacity_ >> fuel_consumption_;
    // Проверка на корректность данных.
    if (fuel_tank_capacity_ <= 0) {
        throw std::invalid_argument(
            "Wrong fuel tank capacity in road transport!\n"
            "Check input file for <" +
            std::to_string(fuel_tank_capacity_) + "> number\n");
    }
    if (fuel_consumption_ <= 0) {
        throw std::invalid_argument(
            "Wrong fuel consumption in road transport!\n"
            "Check input file for <" +
            std::to_string(fuel_consumption_) + "> number\n");
    }
}

RoadTransport* RoadTransport::staticGenerate(bool realistic_random) {
    int key = rand() % 3;
    RoadTransport* rt;
    switch (key) {
        case 0:
            rt = new Truck;
            break;
        case 1:
            rt = new Bus;
            break;
        case 2:
            rt = new Car;
            break;
    }
    rt->generate(realistic_random);
    return rt;
}

void RoadTransport::generate(bool realistic_random) {
    fuel_tank_capacity_ = randPositiveInt32();
    fuel_consumption_ = randPositiveDouble();
}

double RoadTransport::maxDistance() {
    return fuel_tank_capacity_ / (fuel_consumption_ / 100);
}
