#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
template <typename T>
using Point = pair<T, T>;
template <typename T>
bool equals(T a, T b) {
    constexpr double EPS{1e-9};
    return is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}
// Retorna o valor absoluto independente do tipo
template <typename T>
T absolute_value(T x){
    if (is_floating_point<T>::value){
        return fabs(x);
    }
    else{
        return llabs(static_cast<long long>(x));
    }
}
//--------------------------------------------------------------
// RETA
template <typename T>
struct Line {
    T a, b, c;
    // Construtor que gera a equação a partir de dois pontos.
    Line(const Point<T> &P, const Point<T> &Q)
        : a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y) {}

    // Define o operador  == para retas
    bool operator==(const Line<T> &r) const {
        auto k = a ? a : b;
        auto s = r.a ? r.a : r.b;
        return equals(a * s, r.a * k) && equals(b * s, r.b * k) && equals(c * s, r.c * k);
    }
    // Retorna se duas retas são paralelas
    bool parallel(const Line<T> &r) const {
        auto det = a * r.b - b * r.a;
        return det == 0 and !(*this == r);
    }
    // Retorna se duas retas são perpendiculares
    bool orthogonal(const Line<T> &r) const {
        return equals(a * r.a + b * r.b, 0);
    }
    // Retorna se um ponto P está contido na reta
    bool contains(const Point<T> &P) const {
        return equals(a * P.x + b * P.y + c, 0);
    }
    // Retorna a distância de um Ponto P à reta
    double distance(const Point<T> &p) const {
        return fabs(a * p.x + b * p.y + c) / hypot(a, b);
    }
    // Retorna o ponto da reta mais próximo de P
    Point<T> closest(const Point<T> &p) const {
        auto den = (a * a + b * b);
        auto x = (b * (b * p.x - a * p.y) - a * c) / den;
        auto y = (a * (-b * p.x + a * p.y) - b * c) / den;
        return Point<T>{x, y};
    }
};
// Interseção entre duas retas, retorna 1 se intercepta e a coordenada
const int oo{-1};
template <typename T>
pair<int, Point<T>> intersections(const Line<T> &r, const Line<T> &s){
    auto det = r.a * s.b - r.b * s.a;
    if (equals(det, 0)) {
        return {(r == s) ? oo : 0, {}};
    }
    else{
        auto x = (-r.c * s.b + s.c * r.b) / det;
        auto y = (-s.c * r.a + r.c * s.a) / det;
        return {1, {x, y}};
    }
}
// Retorna a posição de um ponto R em relação a reta PQ
// D = 0: R pertence a reta PQ
// D > 0: R à esquerda da reta PQ | D < 0: R à direita da reta PQ
template <typename T>
T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R) {
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
// ----------------------------------------------
// SEGMENTOS DE RETA
// Distância entre dois pontos - comprimento do segmento
template <typename T>
double dist(const Point<T> &P, const Point<T> &Q) {
    return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}
// Distância ao quadrado para evitar imprecisão
template <typename T>
T dist2(const Point<T> &P, const Point<T> &Q) {
    return (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
}
// Distância indo pela horizontal e verical apenas
template <typename T>
T taxicab(const Point<T> &P, const Point<T> &Q) {
    return absolute_value(P.x - Q.x) + absolute_value(P.y - Q.y);
}
// O raio de alcance do segmento
template <typename T>
T max_norm(const Point<T> &P, const Point<T> &Q) {
    return max(absolute_value(P.x - Q.x), absolute_value(P.y - Q.y));
}
// Retorna o ângulo em RAD entre os segmentos de reta PQ e RS
template <typename T>
double angle(const Point<T> &P, const Point<T> &Q, const Point<T> &R, const Point<T> &S) {
    auto ux = P.x - Q.x;
    auto uy = P.y - Q.y;
    auto vx = R.x - S.x;
    auto vy = R.y - S.y;
    auto num = ux * vx + uy * vy;
    auto den = hypot(ux, uy) * hypot(vx, vy);
    return acos(num / den);
}
// Retorna a reta que divide o segmento PQ no meio.
template <typename T>
Line<T> perpendicular_bisector(const Point<T> &P, const Point<T> &Q){
    auto a = 2 * (Q.x - P.x);
    auto b = 2 * (Q.y - P.y);
    auto c = (P.x * P.x + P.y * P.y) - (Q.x * Q.x + Q.y * Q.y);
    return {a, b, c};
}
// Retorna se o ponto P pertence ao segmento de reta AB
template <typename T>
bool contains(const Point<T> &A, const Point<T> &B, const Point<T> &P){
    auto xmin = min(A.x, B.x);
    auto xmax = max(A.x, B.x);
    auto ymin = min(A.y, B.y);
    auto ymax = max(A.y, B.y);
    if (P.x < xmin || P.x > xmax || P.y < ymin || P.y > ymax)
        return false;
    return equals((P.y - A.y) * (B.x - A.x), (P.x - A.x) * (B.y - A.y));
}
// Definição de segmento de reta
template <typename T>
struct Segment {
    Point<T> A, B;
    // Retorna se o ponto P da reta r que contém A e B pertence ao segmento
    bool contains(const Point<T> &P) const{
        return equals(A.x, B.x) ? min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y): min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x); }
    // Esta abordagem não exige que P esteja sobre a reta formada por AB
    bool contains2(const Point<T> &P) const {
        double dAB = dist(A, B), dAP = dist(A, P), dPB = dist(P, B);
        return equals(dAP + dPB, dAB);}
    // Retorna o ponto de AB mais próximo de P
    Point<T> closest(const Point<T> &P){
        Line<T> r(A, B);
        auto Q = r.closest(P);
        if (this->contains(Q))
            return Q;
        auto distA = dist(P, A);
        auto distB = dist(P, B);
        if (distA <= distB)
            return A;
        else
            return B; }
    // Retorna se dois segmentos de reta se interceptam
    bool intersect(const Segment<T> &s) const {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);
        if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B)))
            return true;
        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);
        if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B)))
            return true;
        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }
};
