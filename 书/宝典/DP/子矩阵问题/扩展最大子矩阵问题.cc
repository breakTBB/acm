#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int n, m;
int sum[1001][1001];
int temp[1001];
int a[1001][1001], b[1001][1001];

int solve(int up, int bottom) {
    int ret = INT_MIN;
    rep(i, up, bottom) rep(j, i, bottom) {
        int sm = 0;
        rep(k, 1, m) {
            sm += sum[j][k] - sum[i - 1][k];
            ret = max(ret, sm);
            sm = max(sm, 0);
        }
    }
    return ret;
}

int dp() {
    int max1, max2, max3 = -INT_MAX;
    rep(t, 1, n - 1) {
        max1 = max2 = -INT_MAX;
        rep(i, 1, t) rep(j, i, t) max1 = max(max1, solve(i, j));
        rep(i, t + 1, n) rep(j, i, n) max2 = max(max2, solve(i, j));
        max3 = max(max3, max2 + max1);
    }
    return max3;
}

void init() {
    int i, j, maxx1, maxx2;
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    maxx1 = dp();
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            sum[i][j] = sum[i - 1][j] + b[i][j];
    maxx2 = dp();
    cout << max(maxx1, maxx2);
}

int main() {
    init();
    return 0;
}
