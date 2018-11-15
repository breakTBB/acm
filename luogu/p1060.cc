#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int dp[maxn], w[maxn], v[maxn];

int main() {
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);
    // for(int i = 1; i <= n; i++)
    //     v[i] *= w[i];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j-w[i]]+w[i]*v[i], dp[j]);
    cout << dp[m];
    system("pause");
}


