#ifndef COURSEWORK_LOGREGRESSIONPREDICTOR_H
#define COURSEWORK_LOGREGRESSIONPREDICTOR_H

#include "Predictor.h"

class LogRegressionPredictor: public Predictor {
public:
    double Predict(const std::vector<double>& weights, const std::vector<double>& data) const override;
    double Predict(const std::vector<double>& weights, const DataMatrix& data) const override;
};

#endif //COURSEWORK_LOGREGRESSIONPREDICTOR_H
