#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    //HISTOGRAMA - ESTUDAR
    unordered_map<long long, int> prefix_sum_count;
    long long current_sum = 0;
    long long count = 0;

    prefix_sum_count[0] = 1;

    for (int i = 0; i < n; i++)
    {
        current_sum += s[i];

        if (prefix_sum_count.find(current_sum - k) != prefix_sum_count.end())
        {
            count += prefix_sum_count[current_sum - k];
        }

        prefix_sum_count[current_sum]++;
    }

    cout << count << endl;
    return 0;
}