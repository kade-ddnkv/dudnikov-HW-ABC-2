#include "Bus.h"

void Bus::read(std::ifstream& in) {
    RoadTransport::read(in);
    in >> passenger_capacity_;
    // Проверка на корректность данных.
    if (passenger_capacity_ <= 0) {
        throw std::invalid_argument(
            "Wrong passenger capacity in bus!\n"
            "Check input file for <" +
            std::to_string(passenger_capacity_) + "> number\n");
    }
}

void Bus::generate(bool realistic_random) {
    if (realistic_random) {
        fuel_tank_capacity_ = randPositiveInt(150, 300);
        fuel_consumption_ = randPositiveDouble(18, 35);
        passenger_capacity_ = static_cast<int16_t>(randPositiveInt(10, 80));
    } else {
        RoadTransport::generate(realistic_random);
        passenger_capacity_ = randPositiveInt16();
    }
}

void Bus::print(std::ofstream& out) {
    printWithTableView("bus", maxDistance(), fuel_tank_capacity_, fuel_consumption_,
                       "passenger_cap", passenger_capacity_, out);
}
