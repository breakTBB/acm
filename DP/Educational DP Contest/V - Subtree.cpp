// link: https://atcoder.jp/contests/dp/tasks/dp_v
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
vector<int> G[N];
int n, mod;
ll dp[N], dp2[N];


void dfs(int u, int fa) {
    dp[u] = 1;
    for (int y : G[u]) {
        if (y != fa) {
            dfs(y, u);
            dp[u] *= dp[y];
        }
    }
    dp[u] += 1;
}

void dfs2(int u, int fa) {
    vector<ll> lft(G[u].size()), rht(G[u].size());
    for (int i = 0; i < G[u].size(); i++) {
        int y = G[u][i];
        if (y != fa) {
            if (i == 0) lft[i] = dp[y];
            else lft[i] = lft[i - 1] * dp[y] % mod;
        }
        else {
            lft[i] = i ? lft[i - 1] : 1;
        }
    }
    for (int i = G[u].size() - 1; i >= 0; i--) {
        int y = G[u][i];
        if (y != fa) {
            if (i == G[u].size() - 1) rht[i] = dp[y];
            else rht[i] = rht[i + 1] * dp[y] % mod;
        }
        else {
            rht[i] = (i == G[u].size() - 1 ? 1 : rht[i + 1]);
        }
    }
    for (int i = 0; i < G[u].size(); i++) {
        int y = G[u][i];
        if (y != fa) {
            dp2[y] = dp2[u];
            if (i) dp2[y] = dp2[y] * lft[i - 1] % mod;
            if (i != G[u].size() - 1) dp2[y] = dp2[y] * rht[i + 1] % mod;
            dp2[y] = (dp2[y] + 1) % mod;
            dfs2(y, u);
        }
    }
}

int main() {
    cin >> n >> mod;
    for (int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1, 1);
    dp2[1] = 1;
    dfs2(1, 1);
    for (int i = 1; i <= n; i++) cout << (dp[i] - 1) * dp2[i] % mod << endl;
}