#include <bits/stdc++.h>
#define N 30001
#define r(i, x) for (int i = 1; i <= x; i++)
using namespace std;
bitset<N> b[6][N], a;
int n, x[6][N], y[6][N];
int main()
{
    cin >> n;
    r(i, n) r(j, 5) cin >> x[j][i], y[j][x[j][i]] = i;
    r(i, n) r(j, 5) b[j][i] = b[j][i - 1], b[j][i][y[j][i]] = 1;
    r(i, n) {
        a.set();
        r(j, 5) a = a & b[j][x[j][i]];
        cout << a.count() - 1 << endl;
    }
    return 0;
}