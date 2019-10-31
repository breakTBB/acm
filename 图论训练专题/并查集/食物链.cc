#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

const int N = 1e6 + 10;
int fa[N * 3];
int op, x, y;

inline int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, 1, n * 3) fa[i] = i;
    int ans = 0;
    rep(i, 1, m) {
        cin >> op >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (op == 2 && x == y) {
            ans++;
            continue;
        }
        if (op - 1) {
            if (find(x) == find(y) || find(x + 2 * n) == find(y)) {
                ans++;
                continue;
            }
            fa[find(y)] = find(x + n);
            fa[find(y + n)] = find(x + 2 * n);
            fa[find(y + 2 * n)] = find(x);
        } else {
            if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
                ans++;
                continue;
            }
            fa[find(x)] = find(y);
            fa[find(x + n)] = find(y + n);
            fa[find(x + 2 * n)] = find(y + 2 * n);
        }
    }
    cout << ans << endl;
}