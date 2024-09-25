#include <bits/stdc++.h>
using namespace std;

template <typename T>
using Point = pair<T, T>;
#define x first
#define y second
template <typename T>
bool equals(T a, T b){
    constexpr double EPS{1e-9};
    return is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}
template <typename T>
double dist(const Point<T> &P, const Point<T> &Q){
    return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}
template <typename T>
T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R){
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
//Dado um conjunto de pontos, o envoltório convexo é o menor polígono convexo tal que cada ponto ou pertence ao interior ou é um dos vértices.
template <typename T>
class GrahamScan {
private:
    static Point<T> pivot(vector<Point<T>> &P) {
        size_t idx = 0;

        for (size_t i = 1; i < P.size(); ++i)
            if (P[i].y < P[idx].y or (equals(P[i].y, P[idx].y) and P[i].x > P[idx].x))
                idx = i;
        swap(P[0], P[idx]);
        return P[0];
    }
    static void sort_by_angle(vector<Point<T>> &P) {
        auto P0 = pivot(P);
        sort(P.begin() + 1, P.end(), [&](const Point<T> &A, const Point<T> &B) {
            if (equals(D(P0, A, B), 0))
                return dist(A, P0) < dist(B, P0);
            auto alfa = atan2(A.y - P0.y, A.x - P0.x);
            auto beta = atan2(B.y - P0.y, B.x - P0.x);
            return alfa < beta; });
    }
public:
    static vector<Point<T>> convex_hull(const vector<Point<T>> &points) {
        vector<Point<T>> P(points);
        auto N = P.size();
        // Corner case: com 3 vértices ou menos, P é o próprio convex hull
        if (N <= 3)
            return P;
        sort_by_angle(P);
        vector<Point<T>> ch;
        ch.push_back(P[N - 1]);
        ch.push_back(P[0]);
        ch.push_back(P[1]);
        size_t i = 2;
        while (i < N) {
            auto j = ch.size() - 1;
            if (D(ch[j - 1], ch[j], P[i]) > 0)
                ch.push_back(P[i++]);
            else
                ch.pop_back();
        }
        // O envoltório é um caminho fechado: o primeiro ponto é igual ao último
        return ch;
    }
};
int main() {
    vector<Point<int>> points = {{0, 0}, {2, 1}, {1, 3}, {4, 4}, {3, 2}, {5, 1}, {2, 2}};
    vector<Point<int>> hull = GrahamScan<int>::convex_hull(points);
    cout << "Convex Hull:" << endl;
    for (const auto &p : hull) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    if (hull.begin() == hull.cbegin()) {
        cout << "O primeiro e o ultimo pontos sao iguais = eh convexo" << endl;
        return 0;
    }
    cout << "Nao eh convexo" << endl;
}