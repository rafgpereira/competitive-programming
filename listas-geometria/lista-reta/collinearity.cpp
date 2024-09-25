#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;
// Retorna se três pontos estão na mesma linha, são colineares
// Essa função usa determinante, para verificar
// se a área dos triâgulos formado pelos tres prontos é 0.
bool collinear(const Point &P, const Point &Q, const Point &R) {
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y) == 0;
}
// Recebe n pontos, deve retornar Yes se dentre eles, tres estiverem na mesma linha
int main() {
    int n;
    cin >> n;
    vector<Point> points;
    while (n--) {
        Point P;
        cin >> P.x >> P.y;
        points.push_back(P);
    }
    // Esses loops percorrem todas as combinações possíveis de três pontos da lista
    for (int i = 0; i < points.size()-2; i++){
        for(int j = i+1; j < points.size()-1; j++){
            for(int k = j+1; k < points.size(); k++) {
                if(collinear(points[i], points[j], points[k])){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}