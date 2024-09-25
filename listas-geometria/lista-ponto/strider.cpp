#include <bits/stdc++.h>
using namespace std;
// Maior divisor comum etre A e B
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
// O strider sai da origem, anda 1 unidade para frente e gira X graus.
// Retornar quantas vezes ele precisa fazer o passo para voltar a origem.
int main() {
    int X; cin >> X;
    int ans = 360 / gcd(X, 360);
    cout << ans << endl;
}