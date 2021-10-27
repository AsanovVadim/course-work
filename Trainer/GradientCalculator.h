#ifndef COURSEWORK_GRADIENTCALCULATOR_H
#define COURSEWORK_GRADIENTCALCULATOR_H

#include "DataMatrix.h"
#include <vector>

/*
 * Абстрактный класс, который реализует вычисление градиента на данных data в точке weights
 * Наследники класса по-своему реализуют процесс вычисления градиента
 * Класс используется в Trainer где Gradient вызывается в методе Fit()
 */

class GradientCalculator {
public:
    virtual std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const = 0;
};

#endif //COURSEWORK_GRADIENTCALCULATOR_H
