#ifndef COURSEWORK_PREDICTOR_H
#define COURSEWORK_PREDICTOR_H

#include "DataMatrix.h"
#include <vector>

/*
 * Класс реализуется вычисление значения на основе входной точки
 * Может вычислять ошибку на переданных данных и правильных ответах
 * Процесс вычисления самого значения будет по-разному реализован в потомках
 */
class Predictor {
public:
    // вычиялет значение можели в точке data при весах weights
    virtual double Predict(const std::vector<double>& weights, const std::vector<double>& data) const = 0;

    // вычисляет ошибку (mse) на матрице data (в которой есть и описывающие переменные и правильные ответы)
    virtual double Predict(const std::vector<double>& weights, const DataMatrix& data) const;
};

#endif //COURSEWORK_PREDICTOR_H
