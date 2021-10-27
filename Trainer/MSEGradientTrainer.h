#ifndef COURSEWORK_MSEGRADIENTTRAINER_H
#define COURSEWORK_MSEGRADIENTTRAINER_H

#include "Trainer.h"

class MSEGradientTrainer : public Trainer {
public:
    MSEGradientTrainer(double precision, const DataMatrix& data): Trainer(precision, data) {};

private:
    std::vector<double> Gradient(std::vector<double> weights) const override;
};

#endif //COURSEWORK_MSEGRADIENTTRAINER_H
