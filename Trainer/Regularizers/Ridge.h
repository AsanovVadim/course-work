#ifndef COURSEWORK_RIDGE_H
#define COURSEWORK_RIDGE_H

#include "GradientCalculator.h"

/*
 * Ridge является таким же вычислятором градиента как и Lasso хотя формально является L2-регуляризатором
 */

class Ridge: public GradientCalculator {
public:
    Ridge(GradientCalculator* gc, double lambda): _gradientCalculator(gc), _lambda(lambda) {};
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;
    ~Ridge() { delete _gradientCalculator; };

private:
    GradientCalculator* _gradientCalculator;
    double _lambda;
};

#endif //COURSEWORK_RIDGE_H
