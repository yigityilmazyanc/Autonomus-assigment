#ifndef MATRIX_HPP 
#define MATRIX_HPP 

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cmath>



namespace matrixNs {

template <typename T>
class Matrix {
public:
    size_t rows;
    size_t cols;
    std::vector<std::vector<T>> data;

    Matrix(size_t numRow, size_t numCol);
    Matrix(size_t numRow, size_t numCol, const std::vector<T>& values);

    size_t getRows() const;
    size_t getCols() const;
    Matrix<T> transpose() const;
    T trace() const;
    T determinant() const;
    float magnitude() const;
    Matrix<T> inverse() const;
    T dot(const Matrix& other) const;
    Matrix<T> multiply(const Matrix& other) const;
    Matrix<T> subtract(const Matrix& other) const;
    Matrix<T> neg() const;
    Matrix<T> add(const Matrix& other) const;

    static Matrix zeroes(size_t numRows, size_t numCol);
    static Matrix ones(size_t numRow, size_t numCol);
    static Matrix identity(size_t size);

    // operator overloading
    Matrix<T> operator+(const Matrix& other) const;
    Matrix<T> operator-(const Matrix& other) const;

    static Matrix<int> inputMatrix();
    static Matrix<double> inputMatrixDouble();

};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);

} 

#include "matrix.cpp"   



#endif 
