#include <bits/stdc++.h>

using namespace std;

const int x = 1e9 + 7;
long long dp[1010][1010];

int main() {
    long long m, n;
    cin >> m >> n;
    for (long long i = 1; i <= n; i++)
        dp[1][i] = 1;
    for (long long i = 1; i <= m; i++)
        dp[i][1] = 1;
    for (long long i = 2; i <= m; i++)
        for (long long j = 2; j <=n; j++)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%x;
    cout << dp[m][n] % x;
    system("pause");
}