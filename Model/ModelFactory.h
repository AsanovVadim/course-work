#ifndef COURSEWORK_MODELFACTORY_H
#define COURSEWORK_MODELFACTORY_H

#include "Model.h"

class ModelFactory {
public:
    Model* CreateLinReg(bool withStochastic, double precision) const;
    Model* CreateLinRegLasso(bool withStochastic, double precision, double lambda) const;
    Model* CreateLinRegRidge(bool withStochastic, double precision, double lambda) const;
    Model* CreateLinRegLassoRidge(bool withStochastic, double precision, double lambdaLasso, double lambdaRidge) const;
};

#endif //COURSEWORK_MODELFACTORY_H
