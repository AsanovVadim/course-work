#include "MSEStochGradTrainer.h"
#include "VectorLib.h"
#include <vector>

/*
 * класс реализовывает стохастический градиентный спуск для метода наименьшиих квадратов
 * то есть Q(w, X, y) = 1/n * sum(((x,w) - y)^2) -> min методом стохастического градиентного спуска
 * для этого необходимо высчитывать вектор градиента в точке w (переменные веса) но не для всех наборов X
 * а для одного случайно выбранного
 * производная по каждой переменной wi равна 2 * ((x,w) - y) * xi
 */
std::vector<double> MSEStochasticGradientTrainer::Gradient(std::vector<double> weights) const {
    auto [n, m] = _data.Shape();
    std::vector<double> gradient(m - 1);

    size_t randomSampleInd = std::rand() % n;
    auto descriptiveVars = _data.DescribingVarsAt(randomSampleInd);
    auto dependentVar = _data.DependentVarAt(randomSampleInd);
    for (size_t variableInd = 0; variableInd < gradient.size(); ++variableInd) {
        auto gradientDirection = (Dot(weights, descriptiveVars) - dependentVar) * descriptiveVars[variableInd];
        gradient[variableInd] = 2 * gradientDirection;
    }
    return gradient;
}