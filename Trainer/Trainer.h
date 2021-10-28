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
    Trainer(double precision, GradientCalculator* gc) : _gradientCalculator(gc), _precision(precision) {};
    ~Trainer() {
        delete _gradientCalculator;
    }
    std::vector<double> Fit(const DataMatrix& data) const;

protected:
    GradientCalculator* _gradientCalculator;
    double _precision;
};

#endif //COURSEWORK_TRAINER_H
