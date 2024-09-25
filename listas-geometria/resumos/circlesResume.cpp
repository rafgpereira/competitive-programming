#include <bits/stdc++.h>
using namespace std;

template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

template <typename T>
bool equals(T a, T b)
{
    constexpr double EPS{1e-9};
    return is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}

// Distância entre dois pontos - comprimento do segmento
template <typename T>
double dist(const Point<T> &P, const Point<T> &Q)
{
    return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}

// CÍRCULOS
template <typename T>
struct Circle {
    Point<T> C; // Centro do círculo
    T r;        // Raio do círculo
    // Retorna o perímetro
    double perimeter() const{
        return 2.0 * acos(-1.0) * r;
    }
    // Retorna a área
    double area() const{
        return acos(-1.0) * r * r;
    }
    // Retorna o comprimento do arco
    double arc(double angleRad) const{
        return angleRad * r;
    }
    // Retorna o comprimento da corda
    double chord(double angleRad) const{
        return 2 * r * sin(angleRad / 2);
    }
    // Retorna a área do setor circular
    double sector(double angleRad) const{
        return (angleRad * r * r) / 2;
    }
    // Retorna a área de um segmento do círculo
    //  A área extena ao triângulo interno formado pela corda
    double segment(double angleRad) const{
        return ((angleRad - sin(angleRad)) * r * r) / 2.0;
    }
    // Retorna 0 se o ponto está dentro, 1 sobre ou 2 fora do círculo
    int position(const Point<T> &P) const{
        double d = dist(P, C);
        // Converte raio para double para evitar problemas de tipo
        double radius = static_cast<double>(r);
        return equals(d, radius) ? 1 : (d < radius ? 0 : 2);
    }
    // Cria um círculo através de dois pontos e um raio -> Se raio retornado for 0 nao foi possível construir
    // Circle<double> c2 = Circle<double>::from_2_points_and_r(Point<double>{0, 0}, Point<double>{4, 0}, 3);
    static Circle<T> from_2_points_and_r(const Point<T> &P, const Point<T> &Q, T r){
        double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
        double det = r * r / d2 - 0.25;
        if (det < 0.0)
            return Circle<T>{Point<T>(0, 0), 0};
        double h = sqrt(det);
        auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
        auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;
        return Circle<T>{Point<T>(x, y), r};
    }
    // Cria um círculo através de três pontos -> Se raio retornado for 0 nao foi possível construir
    // Circle<double> c2 = Circle<double>::from_3_points(Point<double>{0, 0}, Point<double>{4, 0}, Point<double>{4, 0});
    static Circle<T> from_3_points(const Point<T> &P, const Point<T> &Q, const Point<T> &R){
        auto a = 2 * (Q.x - P.x);
        auto b = 2 * (Q.y - P.y);
        auto c = 2 * (R.x - P.x);
        auto d = 2 * (R.y - P.y);
        auto det = a * d - b * c;
        if (equals(det, 0))
            return Circle<T>{Point<T>(0, 0), 0};
        auto k1 = (Q.x * Q.x + Q.y * Q.y) - (P.x * P.x + P.y * P.y);
        auto k2 = (R.x * R.x + R.y * R.y) - (P.x * P.x + P.y * P.y);
        auto cx = (k1 * d - k2 * b) / det;
        auto cy = (a * k2 - c * k1) / det;
        Point<T> C{cx, cy};
        auto r = dist(P, C);
        return Circle<T>(C, r);
    }
};
// Retorna vetor com os pontos de interseção entre a reta que passa por PQ e o círculo c
template <typename T>
vector<Point<T>> intersection(const Circle<T> &c, const Point<T> &P, const Point<T> &Q){
    auto a = pow(Q.x - P.x, 2.0) + pow(Q.y - P.y, 2.0);
    auto b = 2 * ((Q.x - P.x) * (P.x - c.C.x) + (Q.y - P.y) * (P.y - c.C.y));
    auto d = pow(c.C.x, 2.0) + pow(c.C.y, 2.0) + pow(P.x, 2.0) + pow(P.y, 2.0) + 2 * (c.C.x * P.x + c.C.y * P.y);
    auto D = b * b - 4 * a * d;
    if (D < 0)
        return {};
    else if (equals(D, 0)){
        auto u = -b / (2 * a);
        auto x = P.x + u * (Q.x - P.x);
        auto y = P.y + u * (Q.y - P.y);
        return {Point<T>{x, y}};
    }
    auto u = (-b + sqrt(D)) / (2 * a);
    auto x = P.x + u * (Q.x - P.x);
    auto y = P.y + u * (Q.y - P.y);
    auto P1 = Point<T>{x, y};
    u = (-b - sqrt(D)) / (2 * a);
    x = P.x + u * (Q.x - P.x);
    y = P.y + u * (Q.y - P.y);
    auto P2 = Point<T>{x, y};
    return {P1, P2};
}
//Retorna os pontos de interseção entre dois círculos, se for infinito ou nenhum, retorna vetor vazio.
template <typename T>
vector<Point<T>> intersection(const Circle<T> &c1, const Circle<T> &c2) {
    double d = dist(c1.C, c2.C);
    vector<Point<T>> result;
    if (d > c1.r + c2.r || d < fabs(c1.r - c2.r))
        return result; // Nenhuma interseção
    if (equals(d, 0.0) && equals(c1.r, c2.r))
        return result;// Infinitas - coincidentes
    auto a = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
    auto h = sqrt(c1.r * c1.r - a * a);
    auto x = c1.C.x + (a / d) * (c2.C.x - c1.C.x);
    auto y = c1.C.y + (a / d) * (c2.C.y - c1.C.y);
    auto P = Point<T>{x, y};
    x = P.x + (h / d) * (c2.C.y - c1.C.y);
    y = P.y - (h / d) * (c2.C.x - c1.C.x);
    auto P1 = Point<T>{x, y};
    x = P.x - (h / d) * (c2.C.y - c1.C.y);
    y = P.y + (h / d) * (c2.C.x - c1.C.x);
    auto P2 = Point<T>{x, y};
    if (P1 == P2)
        result.push_back(P1); // Um ponto de interseção
    else{
        result.push_back(P1); // Dois pontos de interseção
        result.push_back(P2);
    }
    return result;
}
