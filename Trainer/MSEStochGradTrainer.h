#ifndef COURSEWORK_MSESTOCHGRADTRAINER_H
#define COURSEWORK_MSESTOCHGRADTRAINER_H

#include "Trainer.h"
#include "DataMatrix.h"

class MSEStochasticGradientTrainer : public Trainer {
public:
    MSEStochasticGradientTrainer(double precision, const DataMatrix& data): Trainer(precision, data) {};

private:
    std::vector<double> Gradient(std::vector<double> weights) const override;
};

#endif //COURSEWORK_MSESTOCHGRADTRAINER_H
