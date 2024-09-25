#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int dif;
    if (a[0] <= b[0])
        dif = b[0] - a[0];
    else
        dif = 26 - (a[0] - b[0]);

    for (int i = 1; i < a.length(); i++)
    {
        int difI;
        if (a[i] <= b[i])
            difI = b[i] - a[i];
        else
            difI = 26 - (a[i] - b[i]);

        if (difI != dif)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}