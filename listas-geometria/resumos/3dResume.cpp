#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Point3D {
    T x, y, z;
};
template <typename T>
struct Sphere{
    // Ponto central e raio
    Point3D<T> C;
    T r;
    double area() const {
        return 4.0 * PI * r * r;
    }
    double volume() const {
        return 4.0 * PI * r * r * r / 3.0;
    }
};
template <typename T>
struct Cube{
    // Medida do lado
    T L;
    // Medida da diagonal em uma face
    double face_diagonal() const{
        return L * sqrt(2.0);
    }
    // Medida da diagonal que atravessa o cubo
    double space_diagonal() const{
        return L * sqrt(3.0);
    }
    double area() const {
        return 6.0 * L * L;
    }
    double volume() const {
        return L * L * L;
    }
};
template <typename T>
struct Cylinder {
    // Raio e altura
    T r, h;
    double area() const {
        return 2 * acos(-1.0) * r * (r + h);
    }
    double volume() const {
        return acos(-1.0) * r * r * h;
    }
};
template <typename T>
struct Cone {
    T r, H;
    double volume() const {
        return acos(-1.0) * r * r * H / 3.0
    }
    double area() const {
        return acos(-1.0) * r * r + acos(-1.0) * r * sqrt(r * r + H * H);
    }
    //Volume do tronco do cone. rm - raio menor e h - altura do tronco
    double frustum(double rm, double h) const {
        return acos(-1.0) * h * (r * r + rm * r + rm * rm) / 3.0;
    }
};