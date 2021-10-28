#include "LinearRegressionPredictor.h"
#include "VectorLib.h"

double LinearRegressionPredictor::Predict(const std::vector<double>& weights, const std::vector<double>& data) const {
    return Dot(weights, data);
}
