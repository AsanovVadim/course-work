#include "DataMatrix.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

DataMatrix::DataMatrix(const std::string& path) {
    std::ifstream file(path);
    std::cout << "Generating matrix from " << path << std::endl;
    std::string line;
    bool readNames = true;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        if (readNames) {
            _columnNames.push_back("bias");
            std::string name;
            while (std::getline(ss, name, ',')) {
                _columnNames.push_back(name);
            }
            readNames = false;
        } else {
            std::vector<double> row;
            row.push_back(1);
            double x;
            while (ss >> x) {
                ss.ignore(1);
                row.push_back(x);
            }
            _data.push_back(row);
        }
    }

    std::cout << "Enter dependent variable name:";
    std::cin >> _dependentVarName;

    while (std::count(_columnNames.begin(), _columnNames.end(), _dependentVarName) == 0) {
        std::cout << "There is no column " << _dependentVarName << ". Try again" << std::endl;
        std::cout << "Enter dependent variable name:";
        std::cin >> _dependentVarName;
    }
    std::cout << std::endl;
}

size_t DataMatrix::DependentVarInd() const {
    // ищем вхождение заданного имени _dependentVarName и возвращаем его отступ от начала
    return std::find(_columnNames.begin(), _columnNames.end(), _dependentVarName) - _columnNames.begin();
}

void DataMatrix::Info() const {
    auto [n, m] = Shape();
    std::cout << "Data matrix has shape " << n << " x " << m << '\n';

    size_t rowsToShow = n > 3 ? 3 : n;
    std::cout << "First " << rowsToShow << " rows:\n";

    std::cout << std::fixed << std::setprecision(3);
    for (const auto& colName : _columnNames) {
        std::cout  << std::setw(10) << colName << " ";
    }
    std::cout << '\n';
    for (size_t i = 0; i < rowsToShow; ++i) {
        for (const auto& value : _data[i]) {
            std::cout  << std::setw(10) << value << " ";
        }
        std:: cout << '\n';
    }
    std:: cout << '\n';

    std::cout << "Dependent variable is " << _dependentVarName << std::endl;
}

double DataMatrix::DependentVarAt(size_t ind) const {
    return _data[ind][DependentVarInd()];
}

std::vector<double> DataMatrix::DescribingVarsAt(size_t ind) const {
    auto row = _data[ind];
    row.erase(row.begin() + DependentVarInd());
    return row;
}