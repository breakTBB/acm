#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int dp[maxn], v[maxn];

int main(int argc, char const *argv[])
{
    fill(dp,dp+maxn,999999999);
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    dp[0] = 0;
    for(int i = 1; i <=n; i++)
        for(int j = m; j >= v[i]; j--)
            dp[j] = min(dp[j],dp[j-v[i]] + 1);
    cout << dp[m];
    system("pause");
    return 0;
}
