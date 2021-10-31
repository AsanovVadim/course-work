#include "LogRegressionPredictor.h"
#include "VectorLib.h"

double LogRegressionPredictor::Predict(const std::vector<double>& weights, const std::vector<double>& data) const {
    auto positiveProba = 1 / (1 + std::exp(-Dot(weights, data)));
    return positiveProba > 0.5 ? 1 : -1;
}

/*
 * Так как решается задача классификации нужно считать другую ошибку
 * в данном случает будем считать точность (процент правильно классифицированных объектов)
 */
double LogRegressionPredictor::Predict(const std::vector<double> &weights, const DataMatrix &data) const {
    double accuracy = 0;
    auto [n, m] = data.Shape();

    for (size_t i = 0; i < n; ++i) {
        auto variables = data.DescribingVarsAt(i);
        auto answer = data.DependentVarAt(i);
        auto correct = Predict(weights, variables) == answer ? 1 : 0;
        accuracy += correct;
    }
    return accuracy / n;
}