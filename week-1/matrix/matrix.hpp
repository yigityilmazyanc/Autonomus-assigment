#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cmath>

namespace matrixNs {

template <typename T>
class Matrix {
public:
    
    Matrix(size_t rows, size_t cols, T value = 0)
        : rows(rows), cols(cols), data(rows, std::vector<T>(cols, value)){}

    
    Matrix(size_t rows, size_t cols, const std::vector<T>& values)
        : rows(rows), cols(cols), data(rows, std::vector<T>(cols)){
            if (values.size() != rows*cols){
                throw std::invalid_argument("Geçersiz değer");
            }
            data.resize(rows, std::vector<int>(cols));
            for (size_t i=0; i<rows; ++i){
                for(size_t j=0; j<cols; ++j){
                    data[i][j] = values[i*cols + j];
                }
            }
            
        }
    
    Matrix<T> zeroes(size_t rows, size_t cols){
        return Matrix(rows, cols, 0);
    }
    
    Matrix<T> ones(size_t rows, size_t cols){
        return Matrix(rows, cols, 1);
    }
    
    static Matrix<T> identity(size_t size){
        Matrix mat(size, size, 0);
        for(size_t i=0; i<size; ++i){
            mat.data[i][i] = 1;
        }
        return mat;
    }
    
    size_t getRows() const{
        return rows;
    }
    
    size_t getCols() const{
        return cols;
    }
    
    Matrix<T> transpose()const{
        Matrix<T> result(cols, rows);
        for(size_t i=0; i<rows; ++i){
            for(size_t j=0; j<cols; ++j){
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    
    T trace() const{
        if(rows != cols){
            throw std::invalid_argument("Geçersiz işlem");
        }
        int sum=0;
        for(size_t i=0; i<rows; ++i){
            sum += data[i][i];
        }
        return sum;
    }
    
T determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Sadece kare Matrix<T>ler içindir");
    }

    if (rows == 1) {
        return data[0][0];
    } else if (rows == 2) {
        return static_cast<T>(data[0][0] * data[1][1] - data[0][1] * data[1][0]);
    } else if (rows == 3) {
        return static_cast<T>(
            data[0][0] * data[1][1] * data[2][2] +
            data[0][1] * data[1][2] * data[2][0] +
            data[0][2] * data[1][0] * data[2][1] -
            data[0][2] * data[1][1] * data[2][0] -
            data[0][0] * data[1][2] * data[2][1] -
            data[0][1] * data[1][0] * data[2][2]
        );
    }
    throw std::logic_error("Şu anda sadece 1x1, 2x2 ve 3x3 matrisler destekleniyor.");
}

    
Matrix<T> inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Sadece kare Matrix<T>ler!!!");
    }

    // Determinant'ı double veya float olarak hesaplayın
    double det = static_cast<double>(determinant());
    if (det == 0) {
        throw std::logic_error("Determinant 0'dan farklı olmalı");
    }

    if (rows == 1) {
        return Matrix(1, 1, {static_cast<T>(1.0 / data[0][0])});
    } else if (rows == 2) {
        return Matrix(2, 2, {
            static_cast<T>(data[1][1] / det), 
            static_cast<T>(-data[0][1] / det), 
            static_cast<T>(-data[1][0] / det), 
            static_cast<T>(data[0][0] / det)
        });
    } else if (rows == 3) {
        return Matrix(3, 3, {
            static_cast<T>((data[1][1] * data[2][2] - data[1][2] * data[2][1]) / det),
            static_cast<T>((data[0][2] * data[2][1] - data[0][1] * data[2][2]) / det),
            static_cast<T>((data[0][1] * data[1][2] - data[0][2] * data[1][1]) / det),
            static_cast<T>((data[1][2] * data[2][0] - data[1][0] * data[2][2]) / det),
            static_cast<T>((data[0][0] * data[2][2] - data[0][2] * data[2][0]) / det),
            static_cast<T>((data[0][2] * data[1][0] - data[0][0] * data[1][2]) / det),
            static_cast<T>((data[1][0] * data[2][1] - data[1][1] * data[2][0]) / det),
            static_cast<T>((data[0][1] * data[2][0] - data[0][0] * data[2][1]) / det),
            static_cast<T>((data[0][0] * data[1][1] - data[0][1] * data[1][0]) / det)
        });
    }

    // Eğer başka bir durum varsa, burada hata fırlatabilirsiniz
    throw std::logic_error("Desteklenmeyen matris boyutu");
}
    
    Matrix<T> add(const Matrix& other) const{
        if(rows !=other.rows || cols!=other.cols){
            throw std::invalid_argument("Geçersiz işlem");
        }
        Matrix result(rows, cols);
        for(size_t i=0; i<rows; ++i){
            for(size_t j=0; j<cols; ++j){
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    Matrix<T> neg() const {
        Matrix<int> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = -data[i][j];
        return result;
    }
    
    Matrix<T> subtract(const Matrix& other) const{
        return add(other.neg());
    }
    
    Matrix<T> multiply(const Matrix& other) const {
        
        if (cols != other.rows) 
            throw std::logic_error("Number of columns of the first Matrix<T> must equal the number of rows of the second Matrix<T>");


        Matrix result(rows, other.cols); 

        for (size_t i = 0; i < rows; ++i) {  
            for (size_t j = 0; j < other.cols; ++j) {  
                result.data[i][j] = 0; 
                for (size_t k = 0; k < cols; ++k) {  
                    result.data[i][j] += data[i][k] * other.data[k][j]; 
                }
            }
        }
        return result;
    }
    
    T dot(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::logic_error("Matrices must have the same dimensions for dot multiplication");
        int result = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result += data[i][j] * other.data[i][j];
            }
        }
        return result;
    }
    
    float magnitude() const{
        float sum = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                sum += data[i][j] * data[i][j];
            }
        }
        return std::sqrt(sum);
    }
    
    Matrix<T> operator+(const Matrix& other) const {
        return add(other);
    }
    
    Matrix<T> operator-(const Matrix& other) const {
        return subtract(other);
    }
    std::vector<std::vector<T>> data;
private:
    size_t rows;
    size_t cols;
};;

// operator<< fonksiyonunun tanımı
template <typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix) {
    for (const auto& row : matrix.data) {
        for (const auto& value : row) {
            os << value << " ";
        }
        os << "\n";
    }
    return os;

};

} // namespace matrixNs

#endif // MATRIX_H
