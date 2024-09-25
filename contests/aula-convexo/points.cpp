#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;

double calcDist(Point &A, Point &B)
{
    return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
}

int main()
{
    vector<Point> points;
    vector<double> distances;
    Point P;
    int n;
    cin >> n;
    cin >> P.x >> P.y;
    points.push_back(P);
    n--;
    double maior = 0;
    while (n--)
    {
        cin >> P.x >> P.y;
        for (size_t i = 0; i < points.size(); i++)
        {
            double dist = calcDist(points[i], P);
            if (dist > maior)
            {
                maior = dist;
            }
        }
        points.push_back(P);
    }
    cout << fixed << setprecision(7) << maior << endl;
}
