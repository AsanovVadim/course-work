#ifndef COURSEWORK_DATAMATRIX_H
#define COURSEWORK_DATAMATRIX_H

#include <string>
#include <vector>

/*
 * Исходные данные представляются в виде матрицы
 * DataMatrix позволяет читать её из файла
 * Класс хранит имена колонок и высчитывает индекс зависимой переменной
 * Также выводит небольшую сводку
 */

class DataMatrix {
public:
    explicit DataMatrix(const std::string& path);
    size_t DependentVarInd() const;
    void Info() const;

private:
    std::vector<std::string> _columnNames;
    std::vector<std::vector<double>> _data;
    std::string _dependentVarName;
};

#endif //COURSEWORK_DATAMATRIX_H
