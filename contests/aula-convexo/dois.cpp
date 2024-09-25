#include <bits/stdc++.h>
using namespace std;
bool hasOnlyZeroAndTwo(int number)
{
    if (number == 0)
    {
        return true;
    }

    while (number > 0)
    {
        int currentDigit = number % 10;

        if (currentDigit != 0 && currentDigit != 2)
        {
            return false;
        }

        number /= 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    long long x = 2;
    int qtd = 1;
    while (true)
    {
        x+=2;
        if (hasOnlyZeroAndTwo(x))
        {
            qtd++;
        }
        if (qtd == n)
            break;
    }
    cout << x;
}
// 2 --- 20 22 --- 200 202 220 222 --- 2000 2002 2020 2022 2200 2202 2220 2222
//  1*2*2*2