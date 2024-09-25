#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using Point = pair<int, int>;

//Para cada caso, recebe N segmentos e um ponto K,
// deve retornar se é possível que K seja ideal:
// ele aparece em mais seguimentos que qualquer outro.
// Para torná-lo ideal pode-se remover seguimentos.
int main() {
    int cases; cin >> cases;
    while (cases--) {
        int N, K; cin >> N >> K;
        // Map vai guardar quantas vezes cada ponto aparece
        map<int, int> points;
        while (N--){
            Point P; cin >> P.x >> P.y;
            //Se o segmento recebido contém K, adicionamos todos
            //os seus pontos no map
            if (P.x <= K && K <= P.y) {
                for (int i = P.x; i <= P.y; i++) {
                    points[i]++;
                }
            }
        }
        // Se o map nao está vazio, ou seja, tem pelo menos um K,
        // e os numeros mais próximos de K estão menos presentes que ele,
        // quer dizer que foi possível torná-lo ideal.
        if (!points.empty() && points[K] > points[K + 1] && points[K] > points[K - 1]) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}