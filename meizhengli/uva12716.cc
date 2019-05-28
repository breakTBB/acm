#include <bits/stdc++.h>

using namespace std;

int n;
int num[110];
int dp[110][110][2];

int dfs(int idx, bool have, int player) {
    if (idx == n) return 0;
    if (player == 0) {
        if (have) return num[idx] + max(dfs(idx + 1, 0, 1), dfs(idx + 1, 1, 1));
        else return max(dfs(idx + 1, 0, 0), dfs(idx + 1, 1, 0));
    } else {
        if (have) return min(dfs(idx + 1, 0, 0), dfs(idx + 1, 1, 0));
        else return num[idx] + min(dfs(idx + 1, 0, 1), dfs(idx + 1, 1, 1));
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << max(dfs(0, 0, 0), dfs(0, 1, 0));
    system("pause");
}