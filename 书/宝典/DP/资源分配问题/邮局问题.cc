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
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

int pos[400], sum[400][400], dis[400][400];

int main() {
    int V = read(), P = read();
    rep(i, 1, V) pos[i] = read();
    rep(i, 1, V) rep(j, i + 1, V) sum[i][j] = sum[i][j - 1] + pos[j] - pos[(i + j) / 2];
    rep(i, 1, V) dis[i][1] = sum[1][i];
    rep(j, 2, P) rep(i, j + 1, V) {
        dis[i][j] = inf;
        rep(k, j - 1, i - 1) dis[i][j] = min(dis[i][j], dis[k][j - 1] + sum[k + 1][i]);
    }
    printf("%d\n", dis[V][P]);
}