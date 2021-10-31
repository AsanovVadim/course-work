#ifndef COURSEWORK_LOGREGFACTORY_H
#define COURSEWORK_LOGREGFACTORY_H

#include "Model.h"

class LogRegFactory {
public:
    Model* CreateLogReg(bool withStochastic, double precision) const;
    Model* CreateLogRegLasso(bool withStochastic, double precision, double lambda) const;
    Model* CreateLogRegRidge(bool withStochastic, double precision, double lambda) const;
    Model* CreateLogRegLassoRidge(bool withStochastic, double precision, double lambdaLasso, double lambdaRidge) const;
};

#endif //COURSEWORK_LOGREGFACTORY_H
