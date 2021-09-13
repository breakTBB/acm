// link: https://cses.fi/problemset/task/1131
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
vector<int> G[N];
int n;
int down[N], up[N], sec[N];

void dfs(int u, int fa) {
    for (int y : G[u]) {
        if (y != fa) {
            dfs(y, u);
            if (down[y] + 1 > down[u]) {
                sec[u] = down[u];
                down[u] = down[y] + 1;
            }
            else if (down[y] + 1 > sec[u]) {
                sec[u] = down[y] + 1;
            }
        }
    }
}

void dp(int u, int fa) {
    for (int y : G[u]) {
        if (y != fa) {
            up[y] = max(up[u] + 1, down[u] == down[y] + 1 ? sec[u] + 1 : down[u] + 1);
            dp(y, u);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1, 1);
    dp(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) cout << max(down[i], up[i]) << ' ';
}