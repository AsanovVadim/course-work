#ifndef COURSEWORK_STOCHASTICGRADIENT_H
#define COURSEWORK_STOCHASTICGRADIENT_H

#include "GradientCalculator.h"

class StochasticGradient : public GradientCalculator {
public:
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;
};

#endif //COURSEWORK_STOCHASTICGRADIENT_H
