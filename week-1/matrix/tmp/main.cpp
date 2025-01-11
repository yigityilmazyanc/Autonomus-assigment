#include <iostream>
#include "matrix.hpp"

void printMenu() {
    std::cout << "Select an operation:\n";
    std::cout << "1. Add Matrices\n";
    std::cout << "2. Subtract Matrices\n";
    std::cout << "3. Multiply Matrices\n";
    std::cout << "4. Transpose a Matrix\n";
    std::cout << "5. Calculate Determinant\n";
    std::cout << "6. Calculate Trace\n";
    std::cout << "7. Identity Matrix\n";
    std::cout << "8. Dot product Matrix\n";
    std::cout << "9. Inverse Matrix\n";
    std::cout << "10. Negatif of the Matrix\n";
    std::cout << "11. Magnatude of the Matrix\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

// matrixNs::Matrix<int> matrixNs::inputMatrix() {
//     size_t rows, cols;
//     std::cout << "Enter number of rows: ";
//     std::cin >> rows;
//     std::cout << "Enter number of columns: ";
//     std::cin >> cols;

//     std::vector<int> elements;
//     std::cout << "Enter the elements of the matrix row by row:\n";
//     for (size_t i = 0; i < rows * cols; ++i) {
//         int value;
//         std::cin >> value;
//         elements.push_back(value);
//     }

//     matrixNs::Matrix<int> res(rows, cols);
//     return res;
// } // namespace name



 int main(){
    std::cout<<"İşlem yapılacak matrisin tipini seçiniz"<<std::endl;
    std::cout<<"1. int"<<std::endl;
    std::cout<<"2. double"<<std::endl;
    int type;
    std::cin>>type;
    if(type==1){
        try{
            int choice;
            do {
                printMenu();
                std::cin >> choice;

                switch (choice){
                    case 1:{
                        std::cout<<"İlk matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat1 = matrixNs::inputMatrix();
                        std::cout<<"İkinci matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat2 = matrixNs::inputMatrix();

                        std::cout << "Result:\n" << mat1.add(mat2) << std::endl;
                        break;
                    }
                    case 2:{
                        std::cout<<"İlk matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat1 = matrixNs::inputMatrix();
                        std::cout<<"İkinci matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat2 = matrixNs::inputMatrix();

                        std::cout << "Result:\n" << mat1.subtract(mat2) << std::endl;
                        break;
                    }
                    case 3:{
                        std::cout<<"İlk matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat1 = matrixNs::inputMatrix();
                        std::cout<<"İkinci matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat2 = matrixNs::inputMatrix();

                        std::cout << "Result:\n" << mat1.multiply(mat2) << std::endl;
                        break;
                    }
                    case 4:{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat = matrixNs::inputMatrix();
                        std::cout << "Result:\n" << mat.transpose() << std::endl;
                        break;
                    }
                    case 5:{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                        std::cout << "Result: " << mat.determinant() << std::endl;
                        break;
                    }
                    case 6:{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                        std::cout << "Result: " << mat.trace() << std::endl;
                    }
                    case 7:{
                        size_t size;
                        std::cout<<"Kaçlık birim matrix olsun"<<std::endl;
                        std::cin>>size;
                        std::cout <<"Result: \n" << matrixNs::Matrix<int>::identity(size)<<std::endl;
                        break;
                    }
                    case 8:{
                        std::cout<<"İlk matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat1 = matrixNs::inputMatrix();
                        std::cout<<"İkinci matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat2 = matrixNs::inputMatrix();

                        std::cout << "Result= \n"<<mat1.dot(mat2)<<std::endl;
                        break;                
                    }
                    case 9:{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                        std::cout<<"Result= \n"<<mat.inverse()<<std::endl;
                        break;
                    }
                    case 10:{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat = matrixNs::inputMatrix();
                        std::cout<<"Result= "<<mat.neg()<<std::endl;
                        break;
                    }
                    case 11 :{
                        std::cout<<"Matrisi gir"<<std::endl;
                        matrixNs::Matrix<int> mat = matrixNs::inputMatrix();
                        std::cout<<"Result= \n"<<mat.magnitude()<<std::endl;
                    }default:{
                        std::cout<<"İşlem bulunamadı"<<std::endl;
                    }
                }
            }while (choice != 0);
        }catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }
    }else if(type==2){
        try{
            int choice;
            do {
                printMenu();
                std::cin >> choice;

                switch (choice){
                case 1:{
                    std::cout<<"İlk matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat1 = matrixNs::inputMatrixDouble();
                    std::cout<<"İkinci matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat2 = matrixNs::inputMatrixDouble();

                    std::cout << "Result:\n" << mat1.add(mat2) << std::endl;
                    break;
                }
                case 2:{
                    std::cout<<"İlk matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat1 = matrixNs::inputMatrixDouble();
                    std::cout<<"İkinci matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat2 = matrixNs::inputMatrixDouble();

                    std::cout << "Result:\n" << mat1.subtract(mat2) << std::endl;
                    break;
                }
                case 3:{
                    std::cout<<"İlk matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat1 = matrixNs::inputMatrixDouble();
                    std::cout<<"İkinci matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat2 = matrixNs::inputMatrixDouble();

                    std::cout << "Result:\n" << mat1.multiply(mat2) << std::endl;
                    break;
                }
                case 4:{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                    std::cout << "Result:\n" << mat.transpose() << std::endl;
                    break;
                }
                case 5:{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                    std::cout << "Result: " << mat.determinant() << std::endl;
                    break;
                }
                case 6:{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                }
                case 7:{
                    size_t size;
                    std::cout<<"Kaçlık birim matrix olsun"<<std::endl;
                    std::cin>>size;
                    std::cout <<"Result: \n" << matrixNs::Matrix<double>::identity(size)<<std::endl;
                    break;
                }
                case 8:{
                    std::cout<<"İlk matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat1 = matrixNs::inputMatrixDouble();
                    std::cout<<"İkinci matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat2 = matrixNs::inputMatrixDouble();

                    std::cout << "Result= \n"<<mat1.dot(mat2)<<std::endl;
                    break;                
                }
                case 9:{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                    std::cout<<"Result= \n"<<mat.inverse()<<std::endl;
                    break;
                }
                case 10:{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                    std::cout<<"Result= "<<mat.neg()<<std::endl;
                    break;
                }
                case 11 :{
                    std::cout<<"Matrisi gir"<<std::endl;
                    matrixNs::Matrix<double> mat = matrixNs::inputMatrixDouble();
                    std::cout<<"Result= \n"<<mat.magnitude()<<std::endl;
                }default:{
                    std::cout<<"İşlem bulunamadı"<<std::endl;
                }
                }
            }while (choice != 0);
            }catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }
    }else{
        std::cout<<"Geçersiz tip"<<std::endl;
    }
    return 0;
}



