#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
using Point = pair<ll, ll>;
// Função para calcular a equação primitiva da reta
vector<ll> lineEq(const Point &P1, const Point &P2) {
    ll A = P2.y - P1.y;
    ll B = P1.x - P2.x;
    ll C = P2.x * P1.y - P1.x * P2.y;
    ll gcd = __gcd(__gcd(A, B), C);
    A /= gcd;
    B /= gcd;
    C /= gcd;
    if (A < 0 || (A == 0 && B < 0)) {
        A = -A; B = -B; C = -C;
    }
    return {A, B, C};
}
// Recebe-se N pontos e um numero K
// Deve retornar quantas retas passam
// por K pontos.
int main() {
    int N, K;
    cin >> N >> K;
    vector<Point> points(N);
    for (int i = 0; i < N; i++){
        cin >> points[i].x >> points[i].y;
    }
    // Casos especiais
    if (K == 1){
        cout << "Infinity" << endl;
        return 0;
    }
    if (N == 1){
        cout << "0" << endl;
        return 0;
    }
    // Inclinação -> seu conjunto de pontos
    map<vector<ll>, set<Point>> lines;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Calcula a inclinação para dois pontos
            vector<ll> incl = lineEq(points[i], points[j]);
            // Se não tiver inclinação registrada ainda:
            if (lines[incl].empty()) {
                // Percorre todos os outros pontos diferentes
                for (int k = 0; k < N; k++) {
                    if (k != i && k != j) {
                        // Se esse ponto tiver a mesma inclinação
                        // adiciona o ponto na inclinação
                        if (lineEq(points[i], points[k]) == incl) {
                            lines[incl].insert(points[k]);
                        }
                    }
                }
            }
            // Insere os dois pontos na inclinação
            lines[incl].insert(points[i]);
            lines[incl].insert(points[j]);
        }
    }
    int count = 0;
    for (const auto &entry : lines) {
        // Percorre o map com as inclinações e soma se
        //  uma inclinação tiver K pontos na reta
        if (entry.second.size() >= K)
            count++;
    }
    cout << count << endl;
}
