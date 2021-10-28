#ifndef COURSEWORK_MODEL_H
#define COURSEWORK_MODEL_H

#include "Trainer.h"
#include "Predictor.h"
#include <vector>

using weight_with_names = std::pair<std::vector<double>, std::vector<std::string>>;

/*
 * Обобщенный класс модели, который производит обучение и прогноз
 * (вычисление ошибки с имеющимся ответом или просто значение по входным данным)
 * в зависимости от того, какой тренер и предиктор в него были переданы
 * Есть возможность вернуть или вывести значения весов с названиями соотвествуюих переменных
 */
class Model {
public:
    Model(Trainer* tr, Predictor* pr): _trainer(tr), _predictor(pr) {};
    ~Model() {
        delete _trainer;
        delete _predictor;
    }
    void Fit(const DataMatrix& data);
    double Predict(const std::vector<double>& data) const;
    double Predict(const DataMatrix& data) const;
    weight_with_names GetWeights() const;
    void PrintWeights() const;

private:
    Trainer* _trainer;
    Predictor* _predictor;
    std::vector<double> _weights;
    std::vector<std::string> _weightNames;
};

#endif //COURSEWORK_MODEL_H
