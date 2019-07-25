#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x;
    double y;
};

double mult(Point a, Point b, Point c)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool intersect(Point aa, Point bb, Point cc, Point dd)
{
    if (max(aa.x, bb.x) < min(cc.x, dd.x))
    {
        return false;
    }
    if (max(aa.y, bb.y) < min(cc.y, dd.y))
    {
        return false;
    }
    if (max(cc.x, dd.x) < min(aa.x, bb.x))
    {
        return false;
    }
    if (max(cc.y, dd.y) < min(aa.y, bb.y))
    {
        return false;
    }
    if (mult(cc, bb, aa) * mult(bb, dd, aa) < 0)
    {
        return false;
    }
    if (mult(aa, dd, cc) * mult(dd, bb, cc) < 0)
    {
        return false;
    }
    return true;
}

int main()
{
    int cas;
    Point a, b, c, d;
    cin >> cas;
    while (cas--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if (intersect(a, b, c, d))
            cout << "Yes\n";
        else
            printf("No\n");
    }
}