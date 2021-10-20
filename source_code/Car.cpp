#include "Car.h"

void Car::read(std::ifstream& in) {
    RoadTransport::read(in);
    in >> max_speed_;
    // Проверка на корректность данных.
    if (max_speed_ <= 0) {
        throw std::invalid_argument(
            "Wrong max speed in car!\n"
            "Check input file for <" +
            std::to_string(max_speed_) + "> number\n");
    }
}

void Car::generate(bool realistic_random) {
    // Данные могут быть сгенерированы похожими на настоящие.
    if (realistic_random) {
        fuel_tank_capacity_ = randPositiveInt(50, 90);
        fuel_consumption_ = randPositiveDouble(5, 9);
        max_speed_ = static_cast<int16_t>(randPositiveInt(160, 190));
    } else {
        RoadTransport::generate(realistic_random);
        max_speed_ = randPositiveInt16();
    }
}

void Car::print(std::ofstream& out) {
    printWithTableView("car", maxDistance(), fuel_tank_capacity_, fuel_consumption_,
                       "max_speed", max_speed_, out);
}
