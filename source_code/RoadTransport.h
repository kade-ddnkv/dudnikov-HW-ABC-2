#pragma once
#include <fstream>
#include "Random.h"

// Базовая структура дорожного транспорта.
class RoadTransport {
protected:
    // Емкость топливного бака (в литрах).
    int fuel_tank_capacity_;
    // Расход топлива (в литрах) на 100 км.
    double fuel_consumption_;

public:
    virtual ~RoadTransport(){};

    // Возвращает введенный транспорт (определяет тип транспорта по вводу и запускает генерацию
    // соответствующего типа).
    static RoadTransport* staticRead(std::ifstream& in);
    // Ввод данных по одному транспорту из потока (зависит от типа транспорта).
    virtual void read(std::ifstream& in);
    // Возвращает сгенерированный транспорт (генерирует тип транспорта и запускает соответствующий
    // генератор дальше).
    static RoadTransport* staticGenerate(bool realistic_random);
    // Программная генерация данных на один транспорт.
    virtual void generate(bool realistic_random);
    // Вывод параметров транспорта в поток (зависит от типа транспорта).
    virtual void print(std::ofstream& out) = 0;
    // Вычисление максимальной дистанции, которую может проехать транспорт.
    virtual double maxDistance();
};
