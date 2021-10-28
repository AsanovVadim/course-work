#include "Trainer.h"
#include "VectorLib.h"

const double STEP_SIZE = 0.01;
const double MAX_ITERATIONS = 1'000'000;

std::vector<double> Trainer::Fit(const DataMatrix& data) const {
    auto [n, m] = data.Shape();
    std::vector<double>weights(m - 1, 0); // всего m столбов, один из них зависимый, Инициализируем веса нулями

    double difference = 2 * _precision;   //норма разности весов между соседними итерациями
    int iterationNumber = 0;
    std::vector<double> new_weights(weights.size());

    while (difference > _precision && iterationNumber < MAX_ITERATIONS) {
        //метод Gradient() будет реализован в gradientCalculator.
        //сам алогитм минимизации у всех одинаковый и берется из этого класса
        new_weights = weights - STEP_SIZE * _gradientCalculator->Gradient(weights, data);
        difference = Norm(new_weights - weights, 2);
        weights = new_weights;
        iterationNumber += 1;
    }
    return weights;
}