#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdint>

int main() {

    char letter = 'A';
    unsigned char grade = 'A';
    signed char signedGrade = 'A';
    wchar_t emre = L'Ç';
    char16_t char16 = u'A';
    char32_t char32 = U'A';

    int age = 21;
    short int weight = 180;
    unsigned short int height = 180;
    long int height2 = 180;
    unsigned int score = 400;
    unsigned long int score2 = 40;
    long long int distance = 4000000;
    unsigned long long int distance2 = 4000000;

    std::int8_t int8 = 10;
    std::uint8_t uint8 = 10;
    std::int16_t int16 = 10;
    std::uint16_t uint16 = 10;
    std::int32_t int32 = 10;
    std::uint32_t uint32 = 10;
    std::int64_t int64 = 10;
    std::uint64_t uint64 = 10;

    float metre = 1.5;
    double pi = 3.141532;
    long double pi2 = 3.141532;
    bool flag = true;

    std::cout << std::left << std::setw(40) << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "Data type: " << std::left << std::setw(11) << "Size" << std::left << std::setw(11) << "Psize" << std::endl;
    std::cout << std::left << std::setw(40) << "----------------------------------------------------------------------------------------------" << std::endl;

    std::cout << std::left << std::setw(40) << "char: " << std::left << std::setw(11) << sizeof(letter) << std::left << std::setw(11) << sizeof(char*) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned char: " << std::left << std::setw(11) << sizeof(grade) << std::left << std::setw(11) << sizeof(unsigned char*) << std::endl;
    std::cout << std::left << std::setw(40) << "signed char: " << std::left << std::setw(11) << sizeof(signedGrade) << std::left << std::setw(11) << sizeof(signed char*) << std::endl;
    std::cout << std::left << std::setw(40) << "wchar_t: " << std::left << std::setw(11) << sizeof(emre) << std::left << std::setw(11) << sizeof(wchar_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "char16_t: " << std::left << std::setw(11) << sizeof(char16) << std::left << std::setw(11) << sizeof(char16_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "char32_t: " << std::left << std::setw(11) << sizeof(char32) << std::left << std::setw(11) << sizeof(char32_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "int: " << std::left << std::setw(11) << sizeof(age) << std::left << std::setw(11) << sizeof(int*) << std::endl;
    std::cout << std::left << std::setw(40) << "short int: " << std::left << std::setw(11) << sizeof(weight) << std::left << std::setw(11) << sizeof(short int*) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned short int: " << std::left << std::setw(11) << sizeof(height) << std::left << std::setw(11) << sizeof(unsigned short int*) << std::endl;
    std::cout << std::left << std::setw(40) << "long int: " << std::left << std::setw(11) << sizeof(height2) << std::left << std::setw(11) << sizeof(long int*) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned int: " << std::left << std::setw(11) << sizeof(score) << std::left << std::setw(11) << sizeof(unsigned int*) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned long int: " << std::left << std::setw(11) << sizeof(score2) << std::left << std::setw(11) << sizeof(unsigned long int*) << std::endl;
    std::cout << std::left << std::setw(40) << "long long int: " << std::left << std::setw(11) << sizeof(distance) << std::left << std::setw(11) << sizeof(long long int*) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned long long int: " << std::left << std::setw(11) << sizeof(distance2) << std::left << std::setw(11) << sizeof(unsigned long long int*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::int8_t: " << std::left << std::setw(11) << sizeof(int8) << std::left << std::setw(11) << sizeof(std::int8_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint8_t: " << std::left << std::setw(11) << sizeof(uint8) << std::left << std::setw(11) << sizeof(std::uint8_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::int16_t: " << std::left << std::setw(11) << sizeof(int16) << std::left << std::setw(11) << sizeof(std::int16_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint16_t: " << std::left << std::setw(11) << sizeof(uint16) << std::left << std::setw(11) << sizeof(std::uint16_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::int32_t: " << std::left << std::setw(11) << sizeof(int32) << std::left << std::setw(11) << sizeof(std::int32_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint32_t: " << std::left << std::setw(11) << sizeof(uint32) << std::left << std::setw(11) << sizeof(std::uint32_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::int64_t: " << std::left << std::setw(11) << sizeof(int64) << std::left << std::setw(11) << sizeof(std::int64_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint64_t: " << std::left << std::setw(11) << sizeof(uint64) << std::left << std::setw(11) << sizeof(std::uint64_t*) << std::endl;
    std::cout << std::left << std::setw(40) << "float: " << std::left << std::setw(11) << sizeof(metre) << std::left << std::setw(11) << sizeof(float*) << std::endl;
    std::cout << std::left << std::setw(40) << "double: " << std::left << std::setw(11) << sizeof(pi) << std::left << std::setw(11) << sizeof(double*) << std::endl;
    std::cout << std::left << std::setw(40) << "long double: " << std::left << std::setw(11) << sizeof(pi2) << std::left << std::setw(11) << sizeof(long double*) << std::endl;
    std::cout << std::left << std::setw(40) << "bool: " << std::left << std::setw(11) << sizeof(flag) << std::left << std::setw(11) << sizeof(bool*) << std::endl;

    std::cout << std::left << std::setw(35) << "----------------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(40) << "Type" << std::left << std::setw(32) << "Min" << std::left << std::setw(32) << "Max" << std::endl;
    std::cout << std::left << std::setw(35) << "----------------------------------------------------------------------------------------------" << std::endl;

    std::cout << std::left << std::setw(40) << "char: " << std::left << std::setw(32) << int(std::numeric_limits<char>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<char>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned char: " << std::left << std::setw(32) << int(std::numeric_limits<unsigned char>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<unsigned char>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "signed char: " << std::left << std::setw(32) << int(std::numeric_limits<signed char>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<signed char>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "wchar_t: " << std::left << std::setw(32) << int(std::numeric_limits<wchar_t>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<wchar_t>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "char16_t: " << std::left << std::setw(32) << int(std::numeric_limits<char16_t>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<char16_t>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "char32_t: " << std::left << std::setw(32) << int(std::numeric_limits<char32_t>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<char32_t>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "int: " << std::left << std::setw(32) << std::numeric_limits<int>::lowest() << std::left << std::setw(32) << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "short int: " << std::left << std::setw(32) << std::numeric_limits<short int>::lowest() << std::left << std::setw(32) << std::numeric_limits<short int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned short int: " << std::left << std::setw(32) << std::numeric_limits<unsigned short int>::lowest() << std::left << std::setw(32) << std::numeric_limits<unsigned short int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "long int: " << std::left << std::setw(32) << std::numeric_limits<long int>::lowest() << std::left << std::setw(32) << std::numeric_limits<long int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned int: " << std::left << std::setw(32) << std::numeric_limits<unsigned int>::lowest() << std::left << std::setw(32) << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned long int: " << std::left << std::setw(32) << std::numeric_limits<unsigned long int>::lowest() << std::left << std::setw(32) << std::numeric_limits<unsigned long int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "long long int: " << std::left << std::setw(32) << std::numeric_limits<long long int>::lowest() << std::left << std::setw(32) << std::numeric_limits<long long int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "unsigned long long int: " << std::left << std::setw(32) << std::numeric_limits<unsigned long long int>::lowest() << std::left << std::setw(32) << std::numeric_limits<unsigned long long int>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::int8_t: " << std::left << std::setw(32) << int(std::numeric_limits<std::int8_t>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<std::int8_t>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint8_t: " << std::left << std::setw(32) << int(std::numeric_limits<std::uint8_t>::lowest()) << std::left << std::setw(32) << int(std::numeric_limits<std::uint8_t>::max()) << std::endl;
    std::cout << std::left << std::setw(40) << "std::int16_t: " << std::left << std::setw(32) << std::numeric_limits<std::int16_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::int16_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint16_t: " << std::left << std::setw(32) << std::numeric_limits<std::uint16_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::uint16_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::int32_t: " << std::left << std::setw(32) << std::numeric_limits<std::int32_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::int32_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint32_t: " << std::left << std::setw(32) << std::numeric_limits<std::uint32_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::uint32_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::int64_t: " << std::left << std::setw(32) << std::numeric_limits<std::int64_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::int64_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "std::uint64_t: " << std::left << std::setw(32) << std::numeric_limits<std::uint64_t>::lowest() << std::left << std::setw(32) << std::numeric_limits<std::uint64_t>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "float: " << std::left << std::setw(32) << std::numeric_limits<float>::lowest() << std::left << std::setw(32) << std::numeric_limits<float>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "double: " << std::left << std::setw(32) << std::numeric_limits<double>::lowest() << std::left << std::setw(32) << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "long double: " << std::left << std::setw(32) << std::numeric_limits<long double>::lowest() << std::left << std::setw(32) << std::numeric_limits<long double>::max() << std::endl;
    std::cout << std::left << std::setw(40) << "bool: " << std::left << std::setw(32) << std::numeric_limits<bool>::lowest() << std::left << std::setw(32) << std::numeric_limits<bool>::max() << std::endl;

    return 0;
}