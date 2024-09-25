#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "oxxoxxoxxoxx";
    string s;
    cin >> s;
    string r = a.find(s) <= 12 ? "Yes" : "No";
    cout << r << endl;
}