#ifndef COURSEWORK_TRAINER_H
#define COURSEWORK_TRAINER_H

#include "DataMatrix.h"
#include "GradientCalculator.h"
#include <vector>

/*
 * класс, представляющий собой тренера для линейных моделей
 * обучается на данных и возвращает вектор весов
 * Содержит в себе вычислятор градиента, который используется в Fit()
 * precision - точность, достижение которой останавливаем обучение
 * (норма разности между соседними итерациами вычисления весов)
 */
class Trainer {
public:
    Trainer(double precision, const DataMatrix& data, GradientCalculator* gc) : _gradientCalculator(gc),
                                                                                _precision(precision),
                                                                                _data(data) {};
    ~Trainer() {
        delete _gradientCalculator;
    }
    std::vector<double> Fit();

protected:
    GradientCalculator* _gradientCalculator;
    double _precision;
    DataMatrix _data;

};

#endif //COURSEWORK_TRAINER_H
