#include <bits/stdc++.h>
using namespace std;
// Igualdade com maior precisão
template <typename T>
bool equals(T a, T b){
    constexpr double EPS{1e-9};
    return is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}
// PONTOS
// Usando pair para o ponto: ele já tem os operadores == e != implementados
template <typename T>
using PointPair = pair<T, T>;
#define x first
#define y second
// Usando struct para o ponto: precisamos definir os operadores == e !=
template <typename T>
struct Point {
    T x = 0, y = 0;
    bool operator==(const Point<T> &p) const noexcept {
        return equals(x, p.x) && equals(y, p.y);
    }
    bool operator!=(const Point<T> &p) const noexcept {
        return not(*this == p);
    }
};
// Translada o ponto no plano
template <typename T>
Point<T> translate(const Point<T> &P, T dx, T dy) {
    return {P.x + dx, P.y + dy};
}
// Rotaciona ponto X graus em sentido antihorário, em relação a origem
template <typename T>
Point<T> rotateO(const Point<T> &P, int angleDeg) {
    // acos(-1.0) = PI
    auto angleRad = acos(-1.0) * angleDeg / 180.0;
    auto rotatedX = cos(angleRad) * P.x - sin(angleRad) * P.y;
    auto rotatedY = sin(angleRad) * P.x + cos(angleRad) * P.y;
    // Para sentido horário, inverte o sinal de P.x em rotatedY
    return {rotatedX, rotatedY};
}
// Rotaciona ponto X graus em torno de outro ponto C
template <typename T>
Point<T> rotateP(const Point<T> &P, T angleDeg, const Point<T> &C) {
    auto Q = translate(P, -C.x, -C.y);
    Q = rotateO(Q, angleDeg);
    Q = translate(Q, C.x, C.y);
    return Q;
}
// Multiplica o ponto/vetor por um escalar, não preserva distâncias
template <typename T>
Point<T> scale(const Point<T> &v, T sx, T sy) {
    return {sx * v.x, sy * v.y};
}