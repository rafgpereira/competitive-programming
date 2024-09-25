#include <bits/stdc++.h>
using namespace std;

template <typename T>
using Point = pair<T, T>;
#define x first
#define y second
template <typename T>
class Polygon {
public:
    vector<Point<T>> vs;
    int n;
    // O parâmetro deve conter os n vértices do polígono
    Polygon(const vector<Point<T>> &ps) : vs(ps), n(vs.size()) {
        vs.push_back(vs.front());
    }
    // Determinante para ajudar na convexidade
    T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R) const {
        return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
    }
    // Retorna se o polígono é convexo
    bool convex() const {
        // Um polígono deve ter no mínimo três vértices
        if (n < 3)
            return false;
        int P = 0, N = 0, Z = 0;
        for (int i = 0; i < n; ++i){
            auto d = D(vs[i], vs[(i + 1) % n], vs[(i + 2) % n]);
            d ? (d > 0 ? ++P : ++N) : ++Z;
        }
        return P == n or N == n;
    }
    // Distância entre os vértices para ajudar no perímetro
    double distance(const Point<T> &P, const Point<T> &Q) {
        return hypot(P.x - Q.x, P.y - Q.y);
    }
    // Retorna o perímetro
    double perimeter() const {
        auto p = 0.0;
        for (int i = 0; i < n; ++i)
            p += distance(vs[i], vs[i + 1]);
        return p;
    }
    // Retorna a área
    double area() const {
        auto a = 0.0;
        for (int i = 0; i < n; ++i) {
            a += vs[i].x * vs[i + 1].y;
            a -= vs[i + 1].x * vs[i].y;
        }
        return 0.5 * fabs(a);
    }
    // Retorna o ângulo APB, em radianos, ajuda no contains
    double angle(const Point<T> &P, const Point<T> &A, const Point<T> &B) {
        auto ux = P.x - A.x;
        auto uy = P.y - A.y;
        auto vx = P.x - B.x;
        auto vy = P.y - B.y;
        auto num = ux * vx + uy * vy;
        auto den = hypot(ux, uy) * hypot(vx, vy);
        return acos(num / den);
    }
    // Igualdade com precisão para o contains
    bool equals(double x, double y) {
        static const double EPS{1e-6};
        return fabs(x - y) < EPS;
    }
    // Retorna se um ponto P está dentro do polígono
    bool contains(const Point<T> &P) const {
        if (n < 3)
            return false;
        auto sum = 0.0;
        for (int i = 0; i < n - 1; ++i) {
            auto d = D(P, vs[i], vs[i + 1]);
            auto a = angle(P, vs[i], vs[i + 1]);
            sum += d > 0 ? a : (d < 0 ? -a : 0);
        }
        static const double PI = acos(-1.0);
        return equals(fabs(sum), 2 * PI);
    }
    // Retorna o raio do círculo cincunscrito(externo)
    double circumradius() const {
        auto s = distance(vs[0], vs[1]);
        const double PI{acos(-1.0)};
        return (s / 2.0) * (1.0 / sin(PI / n));
    }
    //Retorna o raio do círculo inscrito(interno)
    double apothem() const {
        auto s = distance(vs[0], vs[1]);
        const double PI{acos(-1.0)};
        return (s / 2.0) * (1.0 / tan(PI / n));
    }
};