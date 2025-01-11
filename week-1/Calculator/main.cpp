#include <iostream>
#include "Calculator.h"
#include <limits>

template <typename T>
void performCalculation() {
    Calculator<T> calc;
    T num1, num2;
    char op;

    try {
        std::cout << "Operasyonu seçin (+, -, *, /, %, sqrt(s), ^): ";
        std::cin >> op;

        if (op == 's') {
            std::cout << "Sayiyi girin: ";
            std::cin >> num1;
            std::cout << "Sonuc: " << calc.square(num1) << std::endl;
        } else {
            std::cout << "Sayilari girin: ";
            std::cin >> num1 >> num2;
            switch (op) {
                case '+': std::cout << "Sonuc: " << calc.addition(num1, num2) << std::endl; break;
                case '-': std::cout << "Sonuc: " << calc.subtraction(num1, num2) << std::endl; break;
                case '*': std::cout << "Sonuc: " << calc.multiplication(num1, num2) << std::endl; break;
                case '/': std::cout << "Sonuc: " << calc.division(num1, num2) << std::endl; break;
                case '%': std::cout << "Sonuc: " << calc.modulus(num1, num2) << std::endl; break;
                case '^': std::cout << "Sonuc: " << calc.exponentiation(num1, num2) << std::endl; break;
                default: std::cout << "Gecersiz islem." << std::endl; break;
            }
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Beklenmeyen bir hata olustu: " << e.what() << std::endl;
    }
} // performCalculation fonksiyonunun kapanış süslü parantezi burada olmalı


int main() {
    std::string input;
    char devammitemam;
    
    do{
        std::cout << "1.int\n2.float\n(other)double mi sec: ";
        std::cin >> input;
        try {
            if (input == "1") {
                performCalculation<int>();
            } else if (input == "2") {
                performCalculation<float>();
            } else {
                performCalculation<double>();
            }
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "Islem yapmaya devam etmek istiyor musunuz? (Y/N): ";
        std::cin >> devammitemam;
    }while(devammitemam == 'y' || devammitemam == 'Y');
    std::cout << "Program sonlandirildi." << std::endl;
    return 0;
}