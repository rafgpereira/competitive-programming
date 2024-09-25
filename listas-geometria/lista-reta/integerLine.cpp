#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//Usamos equação diofantina linear para resolver
// Para ter solução, é preciso que o mdc de a e b
// divida C, e para acha-la usa-se euclides estendido.
ll ext_gcd(ll a, ll b, ll &x, ll &y){
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;  y = x1 - y1 * (a / b);
    return d;
}
//Recebe-se os três coeficientes da reta, e deve-se
// retornar um ponto com cordenadas inteiras, se exitir
// entre +-5*10^18
int main() {
    ll A, B, C; cin >> A >> B >> C;
    ll x, y, d = ext_gcd(A, B, x, y);
    if (C % d)
        cout << -1 << endl;
    ll k = -C / d;
    x += k; y += k;
    cout << x << " " << y << endl;
}