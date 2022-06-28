/**
 * @file calculator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>

template<typename T>
class Calculator {
public:
    Calculator() = default;
    virtual ~Calculator() = default;
    Calculator(const Calculator &) = delete;
    Calculator operator=(const Calculator &) = delete;
    T add(T a, T b);
    T minus(T a, T b);
    T multiple(T a, T b);
    T divide(T , T b);

private:
};

#endif // _CALCULATOR_H_

template<typename T>
T Calculator<T>::add(T a, T b) {
    return a + b;
}

template<typename T>
T Calculator<T>::minus(T a, T b) {
    return a - b;
}

template<typename T>
T Calculator<T>::multiple(T a, T b) {
    return a * b;
}

template<typename T>
T Calculator<T>::divide(T a, T b) {
    if (b == 0) {
        std::cerr << "Error!" << std::endl;
    }
    return a / b;
}