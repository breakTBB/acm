#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 110;
int n, k;
int fa[N], num[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    cin >> n >> k;
    rep(i, 1, n) fa[i] = i, num[i] = 1;
    rep(i, 1, k) {
        int u, v;
        cin >> u >> v;
        int tu = find(u), tv = find(v);
        if (tu != tv) {
            fa[tu] = tv;
            num[tv] += num[tu];
        }
    }
    int ans = 0, mx = 0;
    rep(i, 1, n) {
        if (find(i) == i) ans++;
        mx = max(num[i], mx);
    }
    cout << ans << ' ' << mx << endl;

}