#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using Point = pair<double, double>;

// Recebe-se quantos pontos tem a assinatura e
// quantos papéis serão assinados.
// Saõ assinados 50 mm por segundo,
// Deve retornar o tempo gasto para assinar
//Calcula a distância entre dois pontos:
double calcDist(Point &A, Point &B) {
    return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
}
int main() {
    int cases;
    double totalDist = 0.0, papers = 0.0;
    cin >> cases >> papers;
    vector<Point> points;
    for (int i = 0; i < cases; i++) {
        Point P; cin >> P.x >> P.y;
        if (points.size())
            totalDist += calcDist(points[i-1], P);
        points.push_back(P);
    }
    double temp = totalDist * papers / 50.0;
    // Estratégia para aumentar a precisão do cout:
    cout << fixed << setprecision(6) << temp << endl;
}