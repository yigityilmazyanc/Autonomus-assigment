3D Point Operations

This project is a console-based application written in C++ that provides various functionalities to work with 3D points. It supports operations such as calculating distances, comparing points, determining regions, and more.

Features

1. Distance Calculations:

Distance from Origin: Calculate the Euclidean distance of a point from the origin (0,0,0).

Distance Between Two Points: Compute the Euclidean distance between two points in 3D space.

2. Point Comparisons:

Compare Distances to Origin: Determine which of two points is farther from the origin and display the result.

3. Region Determination:

Identify the region of a point in 3D space based on its coordinates. The space is divided into quadrants and axes, such as:

Origin

X, Y, Z Axes

XY, YZ, XZ Planes

Eight octants in 3D space.

4. Same Region Check:

Check if two points are in the same region of 3D space.

Code Overview

Key Structures and Enums

Point Structure

The Point structure represents a 3D point with x, y, and z coordinates.

struct Point {
    float x, y, z;
};

Region Enum

Defines various regions and quadrants of 3D space.

enum class Region {
    Orijin, X_Eksen, Y_Eksen, Z_Eksen,
    XY_Duzlemi, YZ_Duzlemi, XZ_Duzlemi,
    Birinci, Ikinci, Ucuncu, Dorduncu,
    Besinci, Altinci, Yedinci, Sekizinci
};

Functions

Distance Functions

zero_distance: Calculates the distance from the origin.

distance: Computes the distance between two points.

Comparison and Region Functions

compare: Compares the distances of two points from the origin and identifies the farther point.

region: Determines the region of a point based on its coordinates.

is_in_same_region: Checks if two points are in the same region.

Main Menu

The application provides a user-friendly menu for interacting with these functionalities:

Calculate the distance of a point from the origin.

Find the distance between two points.

Compare distances of two points from the origin.

Determine the region of a point.

Check if two points are in the same region.

Example Interaction

Choose an operation:
1. Distance to (0,0,0)
2. Distance between two points
3. Compare distances to origin
4. Find the region of a point
5. Check if two points are in the same region
Enter your choice (1-5): 1
Enter the x, y, z values of the point: 3 4 5
Distance from origin: 7.07107
Do you want to continue? (y/n): n
