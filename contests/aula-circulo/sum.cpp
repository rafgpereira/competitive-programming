#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    long long i = 1;
    for (; i * i <= n; i++)
    {
        sum += n / i;
    }
    for (long long k = 1; k < i; ++k)
    {
        sum += k * ((n / k) - (n / (k + 1)));
    }
    cout << sum << endl;
}