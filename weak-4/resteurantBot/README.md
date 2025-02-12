# C++ Menu Management System

## Overview
This project is a C++ implementation of a menu management system. It allows users to navigate and interact with a menu stored in a JSON file. The system reads, processes, and displays menu items, including their prices and taste balance attributes.

## Table of Contents
- Features
- Object-Oriented Design Principles
- File Structure
- Dependencies
- Build Instructions
- Usage
- Example Output
- General Coding Practices
- Report on Class Relations
- Future Improvements
- Contact

## Features
- Reads a menu from a JSON file (`menu.json`).
- Supports various categories such as appetizers, main courses, desserts, and drinks.
- Displays item details, including taste balance attributes.
- Implements object-oriented design principles such as inheritance, association, composition, and aggregation.
- Provides a structured and extensible codebase using C++ classes.

## Object-Oriented Design Principles
This project utilizes several key OOP concepts:

### Inheritance
- `MenuItem` is the base class for different food categories (`Starter`, `Salad`, `MainCourse`, `Drink`, `Appetizer`, and `Dessert`).
- These derived classes extend `MenuItem` and implement the `display()` function.

### Association
- `User` has a `Menu` and a `Basket`.
- `Menu` and `Basket` interact with `MenuItem` objects through `std::shared_ptr`.

### Composition
- `Menu` directly contains `menuItems`, which are instances of `MenuItem`.
- `User` contains instances of `Menu` and `Basket`, ensuring that they are part of the user's lifecycle.

### Aggregation
- `Basket` contains `std::shared_ptr<MenuItem>`, meaning the same `MenuItem` can be shared across multiple baskets without direct ownership.

## File Structure
The project is divided into three main files:
```
├── main.cpp         # Entry point of the program, all operations are handled here
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
- JSONCPP library for JSON parsing.
- CMake version 3.10 or later.

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

## General Coding Practices
- **Consistent Coding Style:** Follow a uniform naming and formatting convention.
- **Descriptive Variable Names:** Use meaningful variable names that reflect their purpose.
- **Consistent Indentation:** Maintain clear and structured indentation.
- **Modularization:** Organize code into functions and classes for better readability and maintainability.
- **Comments:** Provide clear and concise comments to explain complex logic.
- **Error Handling and Input Validation:** Implement proper error handling and validation to prevent unexpected crashes.

## Report on Class Relations
In object-oriented programming, four primary relationships exist: inheritance, association, composition, and aggregation. This project incorporates them as follows:

- **Inheritance:** `MenuItem` is the base class, and all specific food types (Starter, Salad, MainCourse, etc.) inherit from it.
- **Association:** The `User` class has an association with `Menu` and `Basket`, as it interacts with them but does not own them.
- **Composition:** `Menu` is composed of multiple `MenuItem` instances, meaning that `Menu` owns and manages their lifecycle.
- **Aggregation:** `Basket` holds `MenuItem` objects using `std::shared_ptr`, meaning that the items exist independently of the basket and can be shared among multiple baskets.

This design ensures proper object-oriented structuring, modularity, and reusability.

## Future Improvements
- Implement user interaction for selecting menu items.
- Add functionality to filter and search for items.
- Introduce a graphical user interface (GUI).



