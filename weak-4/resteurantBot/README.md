# C++ Menu Management System

## Overview

This project is a C++ implementation of a menu management system. It allows users to navigate and interact with a menu stored in a JSON file. The system reads, processes, and displays menu items, including their prices and taste balance attributes.

## Table of Contents

- Features
- File Structure
- Dependencies
- Build Instructions
- Usage
- Example Output
- Future Improvements
- Contact

## Features

- Reads a menu from a JSON file (\`\`).
- Supports various categories such as appetizers, main courses, desserts, and drinks.
- Displays item details, including taste balance attributes.
- Provides a structured and extensible codebase using C++ classes.

## File Structure

```
├── main.cpp         # Entry point of the program
├── Menu.hpp         # Header file for the Menu class
├── Menu.cpp         # Implementation file for the Menu class
├── menu.json        # JSON file containing menu data
├── CMakeLists.txt   # CMake build configuration file
└── README.md        # Documentation file
```

## Dependencies

This project requires:

- A C++ compiler supporting C++17 or later.
- The [JSON for Modern C++](https://github.com/nlohmann/json) library for handling JSON data.
- CMake version 3.10 or later.
- JSONCPP library for JSON parsing.

## Build Instructions

1. Ensure CMake is installed:

   ```bash
   cmake --version
   ```

   It should be at least 3.10.

2. Create a build directory and navigate to it:

   ```bash
   mkdir build && cd build
   ```

3. Run CMake configuration:

   ```bash
   cmake ..
   ```

4. Compile the project:

   ```bash
   make
   ```

5. Run the executable:

   ```bash
   ./cafe_executable
   ```

## Usage

1. Run the compiled program:
   ```bash
   ./cafe_executable
   ```
2. The program will display menu items categorized into different sections.

## Example Output

```
Welcome to the Menu System!

Starters:
1. Bruschetta - $8
2. Spinach and Artichoke Dip - $10
...

Main Courses:
1. Grilled Salmon - $18
2. Chicken Alfredo - $15
...
```

## Future Improvements

- Implement user interaction for selecting menu items.
- Add functionality to filter and search for items.
- Introduce a graphical user interface (GUI).



