#include <bits/stdc++.h>
using namespace std;

int cnt;
int dp[110][110];
int num[110][110];
int main(){
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j <= i; j++){
            scanf("%d", &num[i][j]);
        }
    }
    for(int i = 0; i < cnt; i++){
        dp[cnt-1][i] = num[cnt-1][i];
    }
    for(int i = cnt-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
        }
    }
    printf("%d",dp[0][0]);
}