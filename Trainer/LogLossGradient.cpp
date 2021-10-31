#include "LogLossGradient.h"
#include "VectorLib.h"

#include <cmath>
/*
 * класс реализует градиент для log-loss
 * то есть функции Q(w, X, y) = sum(ln(1+exp(-y * (w, x))))
 * производная по каждой переменной wi равна sum(1/(1+exp(-y * (w, x))) * exp(-y * (w, x)) * (-y) * xi)
 */
std::vector<double> LogLossGradient::Gradient(const std::vector<double>& weights, const DataMatrix& data) const {
    auto [n, m] = data.Shape();
    std::vector<double> gradient(m - 1);
    for (size_t variableInd = 0; variableInd < gradient.size(); ++variableInd) {
        double sum = 0;
        for (size_t i = 0 ; i < n; ++i) {
            auto descriptiveVars = data.DescribingVarsAt(i);
            auto dependentVar = data.DependentVarAt(i);
            auto exp = std::exp(-dependentVar * Dot(weights, descriptiveVars));
            sum +=  1/(1 + exp) * exp * (-dependentVar) * descriptiveVars[variableInd];
        }
        gradient[variableInd] = sum;
    }
    return gradient;
}