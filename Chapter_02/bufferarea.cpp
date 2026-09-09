#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point {
    double x, y;
};
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
vector<Point> pointsInBuffer(Point center, double radius, const vector<Point>& points) {
    vector<Point> inside;
    for (auto p : points) {
        if (distance(center, p) <= radius) {
            inside.push_back(p);
        }
    }
    return inside;
}

int main() {
    Point center;
    cout << "Enter center coordinates (x y): ";
    cin >> center.x >> center.y;

    vector<double> radii = {1.0, 2.0, 5.0};
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter point coordinates (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    for (double r : radii) {
        cout << "\nBuffer radius " << r << " km contains:\n";
        vector<Point> inside = pointsInBuffer(center, r, points);
        if (inside.empty()) {
            cout << "No points inside.\n";
        } else {
            for (auto p : inside) {
                cout << "(" << p.x << ", " << p.y << ")\n";
            }
        }
    }

    return 0;
}
