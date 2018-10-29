#include <stdio.h>
//只会写01 完全背包都没写
int max(int a, int b){
    return a > b?a:b;
}
int weight[110];
int dp[110];
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
        sum += weight[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        for (int j = sum/2; j >= weight[i]; --j)
            dp[j] = max(dp[j], dp[j-weight[i]] + weight[i]);
    printf("%d\n", sum - dp[sum/2]*2);
    return 0;
}