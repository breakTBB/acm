#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 110
int a[N];
int dp[N * 10];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = m; j >= a[i]; --j)
                dp[j] += dp[j - a[i]];
        printf("%d\n", dp[m]);
    }
}