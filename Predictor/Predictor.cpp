#include "Predictor.h"

/*
 * MSE = 1/n sum((f(x)-y)^2)
 */
double Predictor::Predict(const std::vector<double>& weights, const DataMatrix& data) const {
    double mse = 0;
    auto [n, m] = data.Shape();

    for (size_t i = 0; i < n; ++i) {
        auto variables = data.DescribingVarsAt(i);
        auto answer = data.DependentVarAt(i);
        auto error = Predict(weights, variables) - answer;
        mse += error * error;
    }
    return mse / n;
}