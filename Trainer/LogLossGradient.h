#ifndef COURSEWORK_LOGLOSSGRADIENT_H
#define COURSEWORK_LOGLOSSGRADIENT_H

#include "GradientCalculator.h"

class LogLossGradient : public GradientCalculator {
public:
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;
};

#endif //COURSEWORK_LOGLOSSGRADIENT_H
