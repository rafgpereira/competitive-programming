#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    string resp;
    cin >> N >> X;
    cin >> resp;

    for (char &ch : resp)
    {
        if (ch == 'o')
            X++;
        if (ch == 'x' && X > 0)
            X--;
    }

    cout << X << endl;
}