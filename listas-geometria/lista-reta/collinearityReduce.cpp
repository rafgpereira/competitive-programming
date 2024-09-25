#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;
// Função para calcular a inclinação entre dois pontos
// Usa a forma de fração reduzida para evitar problemas de precisão
vector<int> slope(const Point &P, const Point &Q) {
    int dy = Q.y - P.y;
    int dx = Q.x - P.x;
    int gcd = __gcd(dy, dx);
    //Usamos vector para evitar problemas com o map
    //Simplificamos pelo GDC para evitar float
    return {dy / gcd, dx / gcd};
}
// Recebe n pontos, deve retornar Yes se dentre eles,
//três estiverem na mesma linha
int main() {
    int n; cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    //Os loops percorrem todos os pares de pontos
    for (int i = 0; i < n; i++) {
        // A estrutura map, primeiro passamos o tipo da chave
        //que sera um vetor de int com a inclinação X e Y,
        //depois passamos o tipo do valor(geralmente int)
        map<vector<int>, int> slope_count;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Armazenamos em um vetor a inclinação X e Y da reta
                vector<int> slope_ij = slope(points[i], points[j]);
                // No map, para a nossa chave (elemento do vetor)
                // iremos adicionar 1 no valor, ou seja,
                // guardamos quantas vezes cada inclinação aparece
                slope_count[slope_ij]++;
                //Verificamos se o valor para aquela chave já é
                // >= 2, ou seja, se tem tres ou mais pontos com
                //a mesma inclinação (slope)
                if (slope_count[slope_ij] >= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
