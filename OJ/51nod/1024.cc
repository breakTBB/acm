#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>
using namespace std;
set<double> s;

int main()
{
    int m, n, a, b;
    scanf("%d%d%d%d", &m, &n, &a, &b);
    for (int i = a; i <= a+n-1; i++)
        for (int j = b; j <= b+m-1; j++) {
            double tmp = double(j) * log10(double(i));
            s.insert(tmp);
        }
    cout << s.size();
    system("pause");
}
