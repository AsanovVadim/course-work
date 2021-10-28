#ifndef COURSEWORK_VECTORLIB_H
#define COURSEWORK_VECTORLIB_H

#include <vector>
#include <numeric>
#include <cmath>
#include <stdexcept>

template <typename T>
T Dot(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Unable to perform operation on vectors with different length.");
    }
    double res = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        res += v1[i] * v2[i];
    }
    return res;
}

template <typename T>
std::vector<T> operator- (const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Unable to perform operation on vectors with different length.");
    }
    std::vector<T> res(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        res[i] = v1[i] - v2[i];
    }
    return res;
}

template <typename T>
std::vector<T> operator+ (const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Unable to perform operation on vectors with different length.");
    }
    std::vector<T> res(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        res[i] = v1[i] + v2[i];
    }
    return res;
}

template <typename NumberType>
NumberType Norm(const std::vector<NumberType>& v, int order) {
    NumberType init = 0;
    if (order == 1) {
        return std::accumulate(v.begin(), v.end(), init, [](auto x, auto y) { return x + std::abs(y); });
    }
    if (order == 2) {
        return std::sqrt(std::accumulate(v.begin(), v.end(), init, [](auto x, auto y) { return x + y*y; }));
    }
    return 0;
}

template <typename NumberType>
std::vector<NumberType> operator* (NumberType num, const std::vector<NumberType>& v) {
    std::vector<NumberType> res(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        res[i] = v[i] * num;
    }
    return res;
}

#endif //COURSEWORK_VECTORLIB_H
