#include "Truck.h"

void Truck::read(std::ifstream& in) {
    RoadTransport::read(in);
    in >> load_capacity_;
    // Проверка на корректность данных.
    if (load_capacity_ <= 0) {
        throw std::invalid_argument(
            "Wrong load capacity in truck!\n"
            "Check input file for <" +
            std::to_string(load_capacity_) + "> number\n");
    }
}

void Truck::generate(bool realistic_random) {
    if (realistic_random) {
        fuel_tank_capacity_ = randPositiveInt(150, 300);
        fuel_consumption_ = randPositiveDouble(20, 45);
        load_capacity_ = randPositiveInt(3500, 6000);
    } else {
        RoadTransport::generate(realistic_random);
        load_capacity_ = randPositiveInt32();
    }
}

void Truck::print(std::ofstream& out) {
    printWithTableView("truck", maxDistance(), fuel_tank_capacity_, fuel_consumption_,
                       "load_cap", load_capacity_, out);
}
