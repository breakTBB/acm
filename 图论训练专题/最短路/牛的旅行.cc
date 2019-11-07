#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}

double dist(int x1, int y1, int x2, int y2) {
    double x = (x1 - x2);
    double y = (y1 - y2);
    return sqrt(1.0 * x * x + 1.0 * y * y);
}
const int N = 160;
double dis[N][N], d[N], far[N];
pair<int, int> P[N];

int main() {
    int n = read();
    rep(i, 1, n) P[i].first = read(), P[i].second = read();
    rep(i, 1, n) rep(j, 1, n) {
        int t; scanf("%1d", &t);
        if (t) dis[i][j] = dist(P[i].first, P[i].second, P[j].first, P[j].second);
        else dis[i][j] = dis[j][i] = DBL_MAX / 2;
    }
    rep(i, 1, n) dis[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        if (dis[i][j] > dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (dis[i][j] != DBL_MAX / 2) far[i] = max(far[i], dis[i][j]);
        }
    }
    double ans = DBL_MAX;
    rep(i, 1, n) rep(j, 1, n) {
        if (dis[i][j] == DBL_MAX / 2) {
            ans = min(ans, far[i] + far[j] + dist(P[i].first, P[i].second, P[j].first, P[j].second));
        }
    }
    rep(i, 1, n) ans = max(ans, far[i]);
    printf("%.6f\n", ans);
}