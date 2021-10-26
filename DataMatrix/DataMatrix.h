#ifndef COURSEWORK_DATAMATRIX_H
#define COURSEWORK_DATAMATRIX_H

#include <string>
#include <vector>

/*
 * Исходные данные представляются в виде матрицы
 * DataMatrix позволяет читать её из файла
 * Класс хранит имена колонок и высчитывает индекс зависимой переменной
 * Также выводит небольшую сводку
 * По каждой стороке (набору входных данных) может выделять зависимую переменную и объясняющие
 */

class DataMatrix {
public:
    explicit DataMatrix(const std::string& path);
    size_t DependentVarInd() const;
    void Info() const;
    std::pair<size_t, size_t> Shape() const {
        return {_data.size(), _data[0].size()};
    }
    std::vector<double> operator[] (size_t ind) const {
        return _data[ind];
    }
    std::vector<double> operator[] (size_t ind) {
        return _data[ind];
    }

    double DependentVarAt(size_t ind) const;
    std::vector<double>DescribingVarsAt(size_t ind) const;

private:
    std::vector<std::string> _columnNames;
    std::vector<std::vector<double>> _data;
    std::string _dependentVarName;
};

#endif //COURSEWORK_DATAMATRIX_H
