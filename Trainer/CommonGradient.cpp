#include "CommonGradient.h"
#include "VectorLib.h"

/*
 * класс реализовывает градиентный спуск для метода наименьшиих квадратов
 * то есть Q(w, X, y) = 1/n * sum(((x,w) - y)^2) -> min методом градиентного спуска
 * для этого необходимо высчитывать вектор градиента в точке w (переменные веса)
 * производная по каждой переменной wi равна 2/n * sum(((x,w) - y) * xi)
 */
std::vector<double> CommonGradient::Gradient(const std::vector<double>& weights, const DataMatrix& data) const {
    auto [n, m] = data.Shape();
    std::vector<double> gradient(m - 1);
    for (size_t variableInd = 0; variableInd < gradient.size(); ++variableInd) {
        double sum = 0;
        for (size_t i = 0 ; i < n; ++i) {
            auto descriptiveVars = data.DescribingVarsAt(i);
            auto dependentVar = data.DependentVarAt(i);
            sum += (Dot(weights, descriptiveVars) - dependentVar) * descriptiveVars[variableInd];
        }
        gradient[variableInd] = 2 * sum / n;
    }
    return gradient;
}
