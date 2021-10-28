#ifndef COURSEWORK_LASSO_H
#define COURSEWORK_LASSO_H

#include "GradientCalculator.h"

/*
 * Формально Lasso это L1 - регуляризатор,
 * но функционально он влияет только на процесс обучения
 * и только тем, что изменяет функцию потесь и, соотвественно, её градиент
 * Таким образом Lasso это такой же вычислятор градиента, только основанный на другом "ббазовом" вычисляторе
 * lambda - параметр регуляризации
 */

class Lasso: public GradientCalculator {
public:
    Lasso(GradientCalculator* gc, double lambda): _gradientCalculator(gc), _lambda(lambda) {};
    ~Lasso() {
        delete _gradientCalculator;
    }
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;

private:
    GradientCalculator* _gradientCalculator;
    double _lambda;
};

#endif //COURSEWORK_LASSO_H
