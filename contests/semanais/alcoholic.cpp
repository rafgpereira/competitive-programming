#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, K;
    cin >> cases >> K;
    double total = 0;
    for (int i = 1; i <= cases; i++)
    {
        int ml, percent;
        cin >> ml >> percent;
        auto alcool = ml * percent / 100;
        total += alcool;
        if (total > K || (K == 0 and percent != 0))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}