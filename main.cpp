#include "DataMatrix.h"
#include "LinRegFactory.h"

#include <fstream>
#include <iostream>

int main() {
    try {
        std::string path;
        std::cout << "Enter file path:" << std::endl;
        std::cin >> path;
        DataMatrix dm(path);
        dm.Info();

        auto mf = new LinRegFactory();
        auto model = mf->CreateLinRegLasso(true, 0.0000000000000001, 0.01);

        model->Fit(dm);
        model->PrintWeights();

        double mse = model->Predict(dm);
        std::cout << "mse = " << mse << std::endl;

        std::cout << "Prediction:\n";
        auto columns = dm.GetColumnNames();
        std::vector<double> point;
        for (size_t i = 1; i < columns.size(); ++i) {
            if (i == dm.DependentVarInd()) {
                continue;
            }
            std::cout << "Enter " << columns[i] << std::endl;
            double num;
            std::cin >> num;
            point.push_back(num);
            std::cout << std::endl;
        }
        std::cout << columns[dm.DependentVarInd()] << " = " << model->Predict(point) << std::endl;

        return 0;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
