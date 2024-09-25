#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using Point = pair<int, int>;
// Recebe um conjunto de pontos e deve retornar se
// algum conjunto de pares tem todos
// o mesmo centro de simetria
bool hasCenterOfSymmetry(const set<Point> &S)
{
    auto a = *S.begin();  // Primeiro ponto (menor) do set
    auto b = *S.rbegin(); // Ultimo ponto (maior) do set
    // Eu pego o primeiro e ultimo para avaliar o centro
    //pois se todos os pares de pontos forem simétricos,
    // o maior e o menor são um par simétrico.
    // Candidato a ser o centro de simetria:
    Point _2s = {a.x + b.x, a.y + b.y};
    //Percorro todos os pontos
    for (auto &p : S) {
        //Para cada ponto da lista, eu subtraio o ponto
        // de simetria para avaliar se o outro ponto
        // que é simetrica a ele está na lista;
        Point q = {_2s.x - p.x, _2s.y - p.y};
        if (!S.count(q))
            return false;
    }
    return true;
}
int main() {
    int cases, n; cin >> cases;
    while (cases--) {
        cin >> n;
        // O set ordenará os pontos automáticamente
        // em ordem crescente
        set<Point> S;
        while (n--) {
            Point P; cin >> P.x >> P.y;
            S.insert(P);
        }
        cout << (hasCenterOfSymmetry(S) ? "yes" : "no") << endl;
    }
}