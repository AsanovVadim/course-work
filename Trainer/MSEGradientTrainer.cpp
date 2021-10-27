#include "MSEGradientTrainer.h"
#include "VectorLib.h"

const double STEP_SIZE = 0.01;
const double MAX_ITERATIONS = 1'000'000;

MSEGradientTrainer::MSEGradientTrainer(double precision, const DataMatrix &data): Trainer(precision), _data(data) {}

/*
 * класс реализовывает градиентный спуск для метода наименьшиих квадратов
 * то есть Q(w, X, y) = 1/n * sum(((x,w) - y)^2) -> min методом градиентного спуска
 * для этого необходимо высчитывать вектор градиента в точке w (переменные веса)
 * производная по каждой переменной wi равна 2/n * sum(((x,w) - y) * xi)
 */
std::vector<double> MSEGradientTrainer::Gradient(std::vector<double> weights) const {
    auto [n, m] = _data.Shape();
    std::vector<double> gradient(m - 1);
    for (size_t variableInd = 0; variableInd < gradient.size(); ++variableInd) {
        double sum = 0;
        for (size_t i = 0 ; i < n; ++i) {
            auto descriptiveVars = _data.DescribingVarsAt(i);
            auto dependentVar = _data.DependentVarAt(i);
            sum += (Dot(weights, descriptiveVars) - dependentVar) * descriptiveVars[variableInd];
        }
        gradient[variableInd] = 2 * sum / n;
    }
    return gradient;
}

std::vector<double> MSEGradientTrainer::Fit() {
    auto [n, m] = _data.Shape();
    std::vector<double>weights(m - 1, 0); // всего m столбов, один из них зависимый, Инициализируем веса нулями

    double difference = 2 * _precision;              //норма разности весов между соседними итерациями
    int iterationNumber = 0;
    std::vector<double> new_weights(weights.size());

    while (difference > _precision && iterationNumber < MAX_ITERATIONS) {
        new_weights = weights - STEP_SIZE * Gradient(weights);
        difference = Norm(new_weights - weights, 2);
        weights = new_weights;
        iterationNumber += 1;
    }
    return weights;
}