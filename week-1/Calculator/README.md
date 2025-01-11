Calculator Application

This project is a console-based Calculator application implemented in C++ using templates to support operations on different data types (int, float, and double). It provides basic arithmetic operations and some advanced operations, all while maintaining type flexibility and error handling.

Features
Basic Operations:

1.Addition (+)

2.Subtraction (-)

3.Multiplication (*)

4.Division (/)

5.Advanced Operations:

6.Modulus (%) (only for integer types)

7.Square (sqrt(s))

8.Exponentiation (^)

Template-based Implementation:
Operations can be performed on int, float, or double data types.

Error Handling:
Handles invalid inputs (e.g., division by zero or invalid modulus operations).

Code Overview

calculator.h

Defines the Calculator class template, which includes methods for arithmetic and advanced operations.

calculator.cpp

Implements the methods defined in Calculator.h. Includes template-based logic for various operations.

main.cpp

Provides a console interface for the user to perform calculations. The user selects the data type (int, float, or double) and the desired operation.

Example output:
1. int
2. float
(other) double mi sec: 1
Operasyonu seçin (+, -, *, /, %, sqrt(s), ^): +
Sayilari girin: 10 20
Sonuc: 30
Islem yapmaya devam etmek istiyor musunuz? (Y/N): N
Program sonlandirildi.



