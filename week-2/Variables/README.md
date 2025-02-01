# Data Type Memory Info

## Overview
This C++ program demonstrates how different data types occupy memory, including their sizes, pointer sizes, and their minimum and maximum values. It helps visualize the storage requirements of fundamental data types in C++.

## Features
- Displays the size of various built-in and standard integer types.
- Displays the size of pointers to these data types.
- Shows the minimum and maximum values that each type can hold.
- Uses `std::numeric_limits` to determine the limits of each data type.

## Dependencies
- C++11 or later

## How to Compile and Run

To compile the program, use a C++ compiler such as `g++`:

```sh
 g++ -std=c++11 main.cpp -o data_info
```

To run the compiled program:

```sh
 ./data_info
```

## Expected Output

The program will output:
1. A table showing each data type's memory size and the memory size of its pointer.
2. A table displaying the minimum and maximum values each data type can hold.

Example snippet of output:

```
----------------------------------------------------------------------------------------------
Data type:                                Size        Psize      
----------------------------------------------------------------------------------------------
char:                                     1          8          
unsigned char:                            1          8          
signed char:                              1          8          
wchar_t:                                  4          8          
...
----------------------------------------------------------------------------------------------
Type                                      Min                                Max
----------------------------------------------------------------------------------------------
char:                                     -128                               127
unsigned char:                            0                                  255
int:                                      -2147483648                        2147483647
...
```

The actual output will depend on the system architecture and compiler implementation.

