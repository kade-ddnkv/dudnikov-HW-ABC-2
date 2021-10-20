#include "TableOutput.h"

void printWithTableView(const std::string &type, const double &max_distance,
                        const int &fuel_tank_capacity, const double &fuel_consumption,
                        const std::string &additional_info, const int &additional_result, std::ofstream &out) {
    out << std::left << std::setw(7) << type
        << std::setw(16) << max_distance
        << std::setw(14) << fuel_tank_capacity
        << std::setw(14) << std::setprecision(2) << fuel_consumption
        << std::setw(15) << additional_info
        << std::setw(10) << additional_result
        << "\n";
}

void printHeader(std::ofstream &out) {
    out << std::left << std::setw(7) << "TYPE"
         << std::setw(16) << "MAX_DISTANCE"
         << std::setw(14) << "FUEL_CAP"
         << std::setw(14) << "FUEL_CONS"
         << std::setw(25) << "ADDITIONAL_INFO" << "\n";
}

void printTitle(const std::string &title, std::ofstream &out) {
    out << std::string(50, '-')
         << "\n" << title << "\n"
         << std::string(50, '-')
         << "\n";
}
