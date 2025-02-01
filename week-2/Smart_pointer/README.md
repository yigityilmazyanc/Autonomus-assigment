# Smart Pointers in C++

This repository contains various implementations and examples of different pointer types in C++, including raw pointers and smart pointers like `unique_ptr`, `shared_ptr`, and `weak_ptr`. The goal is to demonstrate how these pointers work, their advantages, and their drawbacks.

## Files and Descriptions

### 1. `void.cpp`
This file demonstrates basic pointer usage with raw pointers.
- Shows how to store and access an integer variable using a pointer.
- Highlights basic pointer syntax and memory addressing.

### 2. `smart_pointers.cpp`
This file provides an overview of different smart pointers available in C++.
- Implements a custom smart pointer class.
- Demonstrates `std::auto_ptr`, `std::unique_ptr`, `std::shared_ptr`, and their functionalities.
- Explains how smart pointers manage memory automatically to prevent leaks.

### 3. `unique.cpp`
This file demonstrates the use of `std::unique_ptr`.
- `std::unique_ptr` ensures exclusive ownership of an object.
- Shows how to transfer ownership using `std::move()`.
- Prevents multiple references to the same object, reducing the risk of dangling pointers.

### 4. `shared.cpp`
This file demonstrates the use of `std::shared_ptr`.
- `std::shared_ptr` allows multiple shared ownership of an object.
- Demonstrates reference counting and automatic deallocation when the last `shared_ptr` is destroyed.

### 5. `weak.cpp`
This file demonstrates the use of `std::weak_ptr`.
- `std::weak_ptr` avoids circular references in `std::shared_ptr`.
- Shows how to check if a weak pointer is still valid using `expired()`.
- Demonstrates how `lock()` can be used to safely access a `shared_ptr`.

## Smart Pointer Overview
| Smart Pointer   | Description | Advantages | Disadvantages |
|----------------|-------------|------------|--------------|
| `std::unique_ptr` | Owns and manages an object exclusively | Prevents accidental copying | Cannot be shared |
| `std::shared_ptr` | Enables multiple shared ownership of an object | Automatic reference counting | Possible circular dependencies |
| `std::weak_ptr` | Observes an object managed by `shared_ptr` without affecting ownership | Prevents circular dependencies | Must be converted to `shared_ptr` before use |
| Custom Smart Pointer | A user-implemented smart pointer | Custom behavior | Requires manual implementation |

## Compilation
To compile any of the examples, use:
```sh
 g++ filename.cpp -o output
 ./output
```
For example, to compile `shared.cpp`:
```sh
 g++ shared.cpp -o shared
 ./shared
```

## Conclusion
This repository demonstrates different pointer management techniques in C++. Understanding these pointers is crucial for writing efficient and memory-safe C++ programs.

