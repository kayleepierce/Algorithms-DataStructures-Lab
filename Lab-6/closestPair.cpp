/*
 * Name: Kaylee Pierce
 * Date Submitted: 10/20/2023
 * Lab Section: 002
 * Assignment Name: Lab 6 - Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    double x;
    double y;
};

double closestPair(string filename);
double distance(point p1, point p2); // Helper function to calculate distance

/*int main()
{
    double min;
    string filename;
    cout << "File with a list of points within a unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between the closest pair of points: " << min << endl;
    return 0;
}*/

// Function to find closest pair of points in a given file
double closestPair(string filename) {
    ifstream file(filename);
    int n;
    file >> n;
    // Use square root of the number of points because it is scalable with number of points
    int b = sqrt(n);
    vector<point> points(n);

    for (int i = 0; i < n; ++i) { // Read points from file and store in vector
        file >> points[i].x >> points[i].y;
    }

    double minimumDistance = numeric_limits<double>::max();

    for (int i = 0; i < n; ++i) { // Compare all points in file to find closest pair
        for (int j = i + 1; j < n; ++j) {
            double d = distance(points[i], points[j]);
            if (d < minimumDistance) {
                minimumDistance = d;
            }
        }
    }

    return minimumDistance;
}

// Function used to calculate distance
double distance(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}