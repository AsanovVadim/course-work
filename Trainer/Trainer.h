#ifndef COURSEWORK_TRAINER_H
#define COURSEWORK_TRAINER_H

#include <vector>

/*
 * Абстрактный класс, представляющий собой тренера для линейных моделей
 * обучается на данных и возвращает вектор весов
 * В дочерних классах будет переопределяться вычисление градиента, который будет использоваться в Fit()
 * precision - точность, достижение которой останавливаем обучение
 * (норма разности между соседними итерациами вычисления весов)
 */
class Trainer {
public:
    Trainer(double precision) : _precision(precision) {};
    virtual std::vector<double> Fit() = 0;

protected:
    virtual std::vector<double> Gradient(std::vector<double> weights) const = 0;
    double _precision;
};

#endif //COURSEWORK_TRAINER_H
