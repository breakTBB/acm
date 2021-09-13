// link: https://cses.fi/problemset/task/1130/
// tutor: https://usaco.guide/gold/dp-trees?lang=cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
int n;
vector<int> G[N];
int dp[N][2];
int ans;

void dfs(int u, int fa) {
    for (int y : G[u]) {
        if (y != fa) {
            dfs(y, u);
            dp[u][0] += max(dp[y][0], dp[y][1]);
        }
    }
    for (int y : G[u]) {
        if (y != fa) {
            dp[u][1] = max(dp[u][0] - max(dp[y][0], dp[y][1]) + dp[y][0] + 1, dp[u][1]);
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
    cout << max(dp[1][0], dp[1][1]) << "\n";
}