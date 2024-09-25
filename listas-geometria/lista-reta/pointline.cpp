#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
using Point = pair<ll, ll>;
// Para cada caso, recebe três pontos, os dois primeiros determinam uma reta
// Deve avaliar se o terceiro ponto está a direita, esquerda ou sobre a reta
// Usa o determinante (que retorna a área do triângulo)
// Se for 0 está sobre, negativo está a direita e positivo a esquerda
ll collinear(const Point &P, const Point &Q, const Point &R){
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}
int main() {
    int cases; cin >> cases;
    while (cases--) {
        Point P, Q, R; cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y;
        ll det = collinear(P, Q, R);
        if (det > 0) cout << "LEFT" << endl;
        else if (det < 0) cout << "RIGHT" << endl;
        else cout << "TOUCH" << endl;
    }
}