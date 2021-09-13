// link: https://atcoder.jp/contests/dp/tasks/dp_p
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
int n;
vector<int> G[N];
ll dp[N][2];

void mul(ll& a, ll b) {
    a = a * b;
    a %= MOD;
}
void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = 1;
    for (int y : G[u]) {
        if (y != fa) {
            dfs(y, u);
            mul(dp[u][0], dp[y][0] + dp[y][1]);
            mul(dp[u][1], dp[y][0]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1, 1);
    cout << (dp[1][0] + dp[1][1]) % MOD << "\n";
}