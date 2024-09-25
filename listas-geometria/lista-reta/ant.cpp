#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using Point = pair<int, int>;
using Segment = pair<Point, Point>;

int D(Point, Point, Point);
bool contains(Point);
bool intersect(Segment, Segment);

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        vector<Segment> segments;
        int lines, steps;
        cin >> lines >> steps;
        while (lines--)
        {
            Point P, Q;
            cin >> P.x >> P.y >> Q.x >> Q.y;
            segments.push_back(Segment{P, Q});
        }
        while (steps--)
        {
            int x, y;
            cin >> x >> y;
            bool possible = true;
            for(int i = 0; i < segments.size(); i++){
                if(i+1 == x){
                    for(int j = 0; j < segments.size(); j++){
                        if(i != j and !intersect(segments[i+1], segments[j+1])){
                            possible = false;
                        }
                    }
                }
            }

            possible ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
}

int D(Point P, Point Q, Point R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

bool contains(Point A, Point B, Point P)
{
    return (A.x == B.x) ? min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y) : min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
}

bool intersect(Segment A, Segment B)
{
    auto d1 = D(A.first, A.second, B.first);
    auto d2 = D(A.first, A.second, B.second);

    if ((d1 == 0 and contains(A.first, A.second, B.first)) || (d2 == 0 and contains(A.first, A.second, B.second)))
        return true;

    auto d3 = D(B.first, B.second, A.first);
    auto d4 = D(B.first, B.second, A.second);

    if ((d3 == 0 and contains(B.first, B.second, A.first)) || (d4 == 0 and contains(B.first, B.second, A.second)))
        return true;

    return (d1 * d2 < 0) and (d3 * d4 < 0);
}