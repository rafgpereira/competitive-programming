#include <bits/stdc++.h>
using namespace std;

using Point = pair<double, double>;

#define x first
#define y second
#define PI 3.141592653589793

Point rotate(const Point& P, int angleDeg) {

    double angleRad = PI*angleDeg/180.0;

    double rotatedX = cos(angleRad) * P.x - sin(angleRad) * P.y;
    double rotatedY = sin(angleRad) * (-P.x) + cos(angleRad) * P.y;

    return Point {rotatedX, rotatedY};
}

int main() {
    int angle;
    Point P;
    cin >> P.x >> P.y >> angle ;
    Point rotatedP = rotate(P, angle);
    cout << fixed << setprecision(20);
    cout << rotatedP.x << " " << rotatedP.y;
}