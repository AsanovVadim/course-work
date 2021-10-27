#ifndef COURSEWORK_MSEGRADIENTTRAINER_H
#define COURSEWORK_MSEGRADIENTTRAINER_H

#include "Trainer.h"
#include "DataMatrix.h"

class MSEGradientTrainer : public Trainer {
public:
    MSEGradientTrainer(double precision, const DataMatrix& data);
    std::vector<double> Fit() override;

private:
    std::vector<double> Gradient(std::vector<double> weights) const override;

    DataMatrix _data;
};

#endif //COURSEWORK_MSEGRADIENTTRAINER_H
