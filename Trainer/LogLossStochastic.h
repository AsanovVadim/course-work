#ifndef COURSEWORK_LOGLOSSSTOCHASTIC_H
#define COURSEWORK_LOGLOSSSTOCHASTIC_H

#include "GradientCalculator.h"

class LogLossStochasticGradient : public GradientCalculator {
public:
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;
};

#endif //COURSEWORK_LOGLOSSSTOCHASTIC_H
