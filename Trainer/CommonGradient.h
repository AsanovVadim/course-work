#ifndef COURSEWORK_COMMONGRADIENT_H
#define COURSEWORK_COMMONGRADIENT_H

#include "GradientCalculator.h"

class CommonGradient : public GradientCalculator {
public:
    std::vector<double> Gradient(const std::vector<double>& weights, const DataMatrix& data) const override;
};

#endif //COURSEWORK_COMMONGRADIENT_H
