#include "LogRegFactory.h"
#include "LogLossGradient.h"
#include "LogLossStochastic.h"
#include "Lasso.h"
#include "Ridge.h"
#include "LogRegressionPredictor.h"


Model* LogRegFactory::CreateLogReg(bool withStochastic, double precision) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new LogLossStochasticGradient();
    } else {
        gradientCalculator = new LogLossGradient();
    }

    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LogRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LogRegFactory::CreateLogRegLasso(bool withStochastic, double precision, double lambda) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new LogLossStochasticGradient();
    } else {
        gradientCalculator = new LogLossGradient();
    }

    gradientCalculator = new Lasso(gradientCalculator, lambda);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LogRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LogRegFactory::CreateLogRegRidge(bool withStochastic, double precision, double lambda) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new LogLossStochasticGradient();
    } else {
        gradientCalculator = new LogLossGradient();
    }

    gradientCalculator = new Ridge(gradientCalculator, lambda);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LogRegressionPredictor();
    return new Model(trainer, predictor);
}

Model* LogRegFactory::CreateLogRegLassoRidge(bool withStochastic,
                                             double precision,
                                             double lambdaLasso,
                                             double lambdaRidge) const {
    GradientCalculator* gradientCalculator;
    if (withStochastic) {
        gradientCalculator = new LogLossStochasticGradient();
    } else {
        gradientCalculator = new LogLossGradient();
    }

    gradientCalculator = new Lasso(gradientCalculator, lambdaLasso);
    gradientCalculator = new Ridge(gradientCalculator, lambdaRidge);
    auto trainer = new Trainer(precision, gradientCalculator);
    Predictor* predictor = new LogRegressionPredictor();
    return new Model(trainer, predictor);
}
