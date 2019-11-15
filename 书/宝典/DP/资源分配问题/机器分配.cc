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

int value[20][20];
int f[20][20];

int main() {
    int n, m;
    m = read(), n = read();
    swap(n, m);
    rep(i, 1, n) rep(j, 1, m) value[i][j] = read();
    rep(i, 1, n) rep(j, 1, m) {
        int mx = 0;
        rep(k, 0, j) mx = max(mx, f[i - 1][k] + value[i][j - k]);
        f[i][j] = mx;
    }
    printf("%d\n", f[n][m]);
}