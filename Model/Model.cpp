#include "Model.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

void Model::Fit(const DataMatrix& data) {
    _weightNames = data.GetColumnNames();
    _weightNames.erase(_weightNames.begin() + data.DependentVarInd());

    std::cout << "Fitting..." << std::endl;
    _weights = _trainer->Fit(data);
    std::cout << "Fitted." << std::endl;
}

double Model::Predict(const DataMatrix &data) const {
    //если вызвали Predict() перед Fit() то weights пустой и предиктор сломается
    if (_weights.empty()) {
        throw std::runtime_error("It is not allowed for model to predict before being fitted");
    }
    return _predictor->Predict(_weights, data);
}

// в этот Predict() передаются только настроящие переменные, переменная смещения добавится автоматически
double Model::Predict(const std::vector<double> &data) const {
    //если вызвали Predict() перед Fit() то weights пустой и предиктор сломается
    if (_weights.empty()) {
        throw std::runtime_error("It is not allowed for model to predict before being fitted");
    }
    std::vector<double> dataWithBias = {1};
    dataWithBias.insert(dataWithBias.end(), data.begin(), data.end());
    return _predictor->Predict(_weights, dataWithBias);
}

weight_with_names Model::GetWeights() const {
    return {_weights, _weightNames};
}

void  Model::PrintWeights() const {
    auto [weight, names] = GetWeights();
    std::cout << "Model weights:" << std::endl;
    std::cout << std::fixed;

    for (const auto& n : names) {
        std::cout << std::setw(10) << n << ' ';
    }
    std::cout << std::endl;

    for (const auto& w : weight) {
        std::cout << std::setw(10) << w << ' ';
    }
    std::cout << std::endl;
}
