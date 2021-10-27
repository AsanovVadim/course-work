#ifndef COURSEWORK_TRAINER_H
#define COURSEWORK_TRAINER_H

#include "DataMatrix.h"
#include <vector>

/*
 * Абстрактный класс, представляющий собой тренера для линейных моделей
 * обучается на данных и возвращает вектор весов
 * В дочерних классах будет переопределяться вычисление градиента, который используется в Fit()
 * precision - точность, достижение которой останавливаем обучение
 * (норма разности между соседними итерациами вычисления весов)
 */
class Trainer {
public:
    Trainer(double precision, const DataMatrix& data) : _precision(precision), _data(data) {};
    std::vector<double> Fit();

protected:
    virtual std::vector<double> Gradient(std::vector<double> weights) const = 0;

    double _precision;
    DataMatrix _data;
};

#endif //COURSEWORK_TRAINER_H
