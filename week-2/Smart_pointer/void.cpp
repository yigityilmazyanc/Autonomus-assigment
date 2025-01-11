#include <iostream>

int main(){
    int y = 7;
    int* p= &y;

    std::cout << "Address of y: " << &y << std::endl;
    std::cout << "Value of y: " << y << std::endl;
}