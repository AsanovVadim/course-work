#ifndef COURSEWORK_LINEARREGRESSIONPREDICTOR_H
#define COURSEWORK_LINEARREGRESSIONPREDICTOR_H

#include "Predictor.h"

class LinearRegressionPredictor: public Predictor {
public:
    double Predict(const std::vector<double>& weights, const std::vector<double>& data) const override;
};

#endif //COURSEWORK_LINEARREGRESSIONPREDICTOR_H
