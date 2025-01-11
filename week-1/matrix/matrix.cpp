#include "matrix.hpp"

namespace matrixNs{
  

    template <typename T>
    Matrix<T>::Matrix(size_t numRow, size_t numCol)
        : rows(numRow), cols(numCol), data(numRow, std::vector<T>(numCol)){}

    template <typename T>
    Matrix<T>::Matrix(size_t numRow, size_t numCol, const std::vector<T>& values)
        : rows(numRow), cols(numCol), data(numRow, std::vector<T>(numCol)){
            if (values.size() != rows*cols){
                throw std::invalid_argument("Geçersiz değer ilk girilen ilk girilen değerin rowunun boyutu ikinci girilen değerin colunun boyutu ile boyutuna eşit olmalıdır");
            }
            for (size_t i=0; i<rows; ++i){
                for(size_t j=0; j<cols; ++j){
                    data[i][j] = values[i*cols + j];
                }
            }
            
        }
       

    template <typename T>
    Matrix<T> Matrix<T>::zeroes(size_t rows, size_t cols){
        return Matrix(rows, cols, std::vector<T>(rows * cols, 0));
    }
    template <typename T>
    Matrix<T> Matrix<T>::ones(size_t rows, size_t cols){
        return Matrix(rows, cols, std::vector<T>(rows * cols, 1));
    }
    template <typename T>
    Matrix<T> Matrix<T>::identity(size_t size){
        Matrix mat(size,size, std::vector<T>(size * size, 0));
        for(size_t i=0; i<size; ++i){
            mat.data[i][i] = 1;
        }
        return mat;
    }
    template <typename T>
    size_t Matrix<T>::getRows() const{
        return rows;
    }
    template <typename T>
    size_t Matrix<T>::getCols() const{
        return cols;
    }
    template <typename T>
    Matrix<T> Matrix<T>::transpose()const{
        Matrix result(cols, rows);
        for(size_t i=0; i<rows; ++i){
            for(size_t j=0; j<cols; ++j){
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    template <typename T>
    T Matrix<T>::trace() const{
        if(rows != cols){
            throw std::invalid_argument("Geçersiz işlem sadece kare matrisler için");
        }
        int sum=0;
        for(size_t i=0; i<rows; ++i){
            sum += data[i][i];
        }
        return sum;
    }
    template <typename T>
    T Matrix<T>::determinant() const {
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


    template <typename T>
    Matrix<T> Matrix<T>::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Sadece kare Matrix<T>ler!!!");
    }

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

    throw std::logic_error("Desteklenmeyen matris boyutu");
}
    template <typename T>
    Matrix<T> Matrix<T>::add(const Matrix& other) const{
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
    template <typename T>
    Matrix<T> Matrix<T>::neg() const {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = -data[i][j];
        return result;
    }
    template <typename T>
    Matrix<T> Matrix<T>::subtract(const Matrix& other) const{
        return add(other.neg());
    }
    template <typename T>
    Matrix<T> Matrix<T>::multiply(const Matrix& other) const {
        
        if (cols != other.rows) 
            throw std::logic_error("ilk matrixsin sütun sayısı ikinci matrixin satır sayısına eşit olmalıdır");


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
    template <typename T>
    T Matrix<T>::dot(const Matrix& other) const {
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
    template <typename T>
    float Matrix<T>::magnitude() const{
        float sum = 0;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                sum += data[i][j] * data[i][j];
            }
        }
        return std::sqrt(sum);
    }
    template <typename T>
    Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
        return add(other);
    }
    template <typename T>
    Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
        return subtract(other);
    }
    template <typename U>
    std::ostream& operator<<(std::ostream& os,const Matrix<U>& matrix){
        for(const auto& row : matrix.data){
            for(const auto& value: row){
                os<<value<<" ";
            }
            os<<"\n";
        }
        return os;
    }    

    Matrix<int> inputMatrix(){
        size_t rows, cols;
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of columns: ";
        std::cin >> cols;

        std::vector<int> elements;
        std::cout << "Enter the elements of the matrix row by row:\n";
        for (size_t i = 0; i < rows * cols; ++i) {
            int value;
            std::cin >> value;
            elements.push_back(value);
        }

        matrixNs::Matrix<int> res(rows, cols, elements);
        return res;
    }

    Matrix<double> inputMatrixDouble(){
        size_t rows, cols;
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of columns: ";
        std::cin >> cols;

        std::vector<double> elements;
        std::cout << "Değerleri satır satır girin\n";
        for (size_t i = 0; i < rows * cols; ++i) {
            double value;
            std::cin >> value;
            elements.push_back(value);
        }

        matrixNs::Matrix<double> res(rows, cols, elements);
        return res;
    }
}
