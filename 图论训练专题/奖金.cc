#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}
const int N = 100010;
struct edge {
    int nxt, v, to;
}E[N];
int n, m;
int head[N], in[N];
int q[N], tot;
int mo[N];

int main() {
    n = read(), m = read();
    rep(i, 1, m) {
        int u = read(), v = read();
        in[u]++;
        E[i].to = u, E[i].nxt = head[v], head[v] = i;
    }
    rep(i, 1, n) if (!in[i]) q[++tot] = i, mo[i] = 100;
    rep(i, 1, tot) {
        int now = q[i];
        for (int i = head[now]; i; i = E[i].nxt) {
            int nxt = E[i].to;
            mo[nxt] = mo[now] + 1;
            if (--in[nxt] == 0) q[++tot] = nxt;
        }
    }
    if (tot == n) {
        ll ans = 0;
        rep(i, 1, n) ans += mo[i];
        cout << ans << endl;
    } else {
        puts("Poor Xed");
    }
}