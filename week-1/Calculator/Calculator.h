#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename T>
class Calculator{
    public:
        
        T addition(T num1, T num2);
        T subtraction(T num1, T num2);
        T multiplication(T num1, T num2);
        T division(T num1, T num2);
        T square(T num1);
        T exponentiation(T num1, T num2);
        T modulus(T num1, T num2);
};

#include "calculator.cpp"


template class Calculator<int>;
template class Calculator<float>;
template class Calculator<double>;


#endif
