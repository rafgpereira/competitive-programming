#include <bits/stdc++.h>
using namespace std;
// Um braço robótico de três segmentos partindo da origem, deve-se calcular a área máxima que a ponta do braço pode alcançar
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double area;
    double areaM = (a + b + c) * (a + b + c) * acos(-1.0);
    if (a + b > c and a + c > b and b + c > a)
        area = areaM;
    else
    {
        int a1 = fabs(a + b - c), a2 = fabs(a - b + c), a3 = fabs(a - b - c);
        int menor = min({a1, a2, a3});
        area = areaM - (menor * menor * acos(-1.0));
    }
    cout << fixed << setprecision(7) << area << endl;
}