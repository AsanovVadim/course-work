#include "Ridge.h"
#include "VectorLib.h"

/*
 * Ridge добавляет у функции потерь lambda * sum(wi^2)
 * Производная этого кусочка по wi равен lambda * 2 * wi
 * Таким образом с градиенту добавятся соотвествущие значения
 */
std::vector<double> Ridge::Gradient(const std::vector<double>& weights, const DataMatrix& data) const {
    std::vector<double> gradientExtension = weights;
    for (auto& component : gradientExtension) {
        component = _lambda * 2 * component;
    }
    return _gradientCalculator->Gradient(weights, data) + gradientExtension;
}
