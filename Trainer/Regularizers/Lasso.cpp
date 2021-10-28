#include "Lasso.h"
#include "VectorLib.h"

int Sign(double x) {
    if (x == 0) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

/*
 * Lasso добавляет у функции потерь lambda * sum(|wi|)
 * Производная этого кусочка по wi равен lambda * sign(w1)
 * Таким образом с градиенту добавятся соотвествущие значения
 */

std::vector<double> Lasso::Gradient(const std::vector<double>& weights, const DataMatrix& data) const {
    std::vector<double> gradientExtension = weights;
    for (auto& component : gradientExtension) {
        component = _lambda * Sign(component);
    }
    return _gradientCalculator->Gradient(weights, data) + gradientExtension;
}
