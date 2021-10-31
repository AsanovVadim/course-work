#include "LogLossStochastic.h"
#include "VectorLib.h"

#include <cmath>
/*
 * класс реализует стохастический градиент для log-loss
 * то есть функции Q(w, X, y) = sum(ln(1+exp(-y * (w, x)))) но в одной случайно выбранной точке x
 * производная по каждой переменной wi равна 1/(1+exp(-y * (w, x))) * exp(-y * (w, x)) * (-y) * xi
 *
 */
std::vector<double> LogLossStochasticGradient::Gradient(const std::vector<double>& weights, const DataMatrix& data) const {
    auto [n, m] = data.Shape();
    std::vector<double> gradient(m - 1);

    size_t randomSampleInd = std::rand() % n;
    auto descriptiveVars = data.DescribingVarsAt(randomSampleInd);
    auto dependentVar = data.DependentVarAt(randomSampleInd);
    for (size_t variableInd = 0; variableInd < gradient.size(); ++variableInd) {
        auto exp = std::exp(-dependentVar * Dot(weights, descriptiveVars));
        gradient[variableInd] = 1/(1 + exp) * exp * (-dependentVar) * descriptiveVars[variableInd];
    }
    return gradient;
}