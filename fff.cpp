#include <bits/stdc++.h>
using namespace std;

int num[105], dp[105][105];

int main()
{
    int i, j, len, k, n, ans = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (len = 1; len < n; len++){
        for (i = 0; i < n; i++) {
            j = (i + len) % n;
            for (k = i; k != j; k = (k + 1) % n) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[(k + 1) % n][j] + num[i] * num[(k + 1) % n] * num[(j + 1) % n]);
            }                
        }
    }

    for (i = 0; i < n; i++) {
        if (ans < dp[i][(i - 1 + n) % n])
        ans = dp[i][(i - 1 + n) % n];
    }
    printf("%d", ans);
    return 0;
}
