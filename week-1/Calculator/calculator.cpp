#include "Calculator.h"
#include <iostream>
#include <cmath>

template <typename T>
T Calculator<T>::addition(T num1, T num2){
    return num1 + num2;
}

template <typename T>
T Calculator<T>::subtraction(T num1, T num2){
    return num1 - num2;
}

template <typename T>
T Calculator<T>::multiplication(T num1, T num2){
    return num1 * num2;
}

template <typename T>
T Calculator<T>::division(T num1, T num2){
    if(num2==0) throw std::invalid_argument("0'a bölünmez");
    return num1 / num2;
}

template <typename T>
T Calculator<T>::square(T num1){
    return num1*num1;
}

template <typename T>
T Calculator<T>::exponentiation(T num1, T num2){
    return pow(num1, num2);
}

template <typename T>
T Calculator<T>::modulus(T num1, T num2){
    if constexpr (std::is_integral<T>::value) {
        if(num1 % num2>=0){
           return num1 % num2; 
        }else{
            return num2 + (num1 % num2);
        }
        
    } else {
        throw std::invalid_argument("Mod alma sadece integer işlemlerde geçerli");
    }
}
