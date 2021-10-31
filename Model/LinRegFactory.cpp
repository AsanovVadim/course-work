#include "LinRegFactory.h"
#include "CommonGradient.h"
#include "StochasticGradient.h"
#include "Lasso.h"
#include "Ridge.h"
#include "LinearRegressionPredictor.h"

Model* LinRegFactory::CreateLinReg(bool withStochastic, double precision) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new StochasticGradient();
    } else {
        gradientCalculator = new CommonGradient();
    }

    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LinearRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LinRegFactory::CreateLinRegLasso(bool withStochastic, double precision, double lambda) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new StochasticGradient();
    } else {
        gradientCalculator = new CommonGradient();
    }

    gradientCalculator = new Lasso(gradientCalculator, lambda);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LinearRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LinRegFactory::CreateLinRegRidge(bool withStochastic, double precision, double lambda) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new StochasticGradient();
    } else {
        gradientCalculator = new CommonGradient();
    }

    gradientCalculator = new Ridge(gradientCalculator, lambda);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LinearRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LinRegFactory::CreateLinRegLassoRidge(bool withStochastic,
                                             double precision,
                                             double lambdaLasso,
                                             double lambdaRidge) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new StochasticGradient();
    } else {
        gradientCalculator = new CommonGradient();
    }

    gradientCalculator = new Lasso(gradientCalculator, lambdaLasso);
    gradientCalculator = new Ridge(gradientCalculator, lambdaRidge);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LinearRegressionPredictor();
    return new Model(trainer, predictor);
}
