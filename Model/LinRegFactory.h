#ifndef COURSEWORK_LINREGFACTORY_H
#define COURSEWORK_LINREGFACTORY_H

#include "Model.h"

class LinRegFactory {
public:
    Model* CreateLinReg(bool withStochastic, double precision) const;
    Model* CreateLinRegLasso(bool withStochastic, double precision, double lambda) const;
    Model* CreateLinRegRidge(bool withStochastic, double precision, double lambda) const;
    Model* CreateLinRegLassoRidge(bool withStochastic, double precision, double lambdaLasso, double lambdaRidge) const;
};

#endif //COURSEWORK_LINREGFACTORY_H
