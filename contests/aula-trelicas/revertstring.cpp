#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int x, y;
    cin >> x >> y >> s;
    int i = x - 1;
    int lim = (i + ((y - x + 1) / 2));
    int limS = y - 1;
    for (; i < lim; i++)
    {
        char aux = s[i];
        s[i] = s[limS];
        s[limS] = aux;
        limS--;
    }
    for (char l : s)
    {
        cout << l;
    }
}