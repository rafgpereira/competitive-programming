#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (y - x < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int rest = y - x;
    if (rest % 10 == 0)
    {
        cout << rest / 10 << endl;
    }
    else
    {
        cout << (rest / 10) + 1 << endl;
    }
}