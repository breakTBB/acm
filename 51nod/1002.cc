#include <bits/stdc++.h>

using namespace std;

int tower[510][510];
int dp[510][510];

int main() {
    int height;
    cin >> height;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &tower[i][j]);
        }
    }
    for (int i = height; i >= 1; i--) {
        for (int j = 1; j <= height; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + tower[i][j];
        }
    }
    cout << dp[1][1];
    system("pause");
}


__int64 a[505][505];
int main2()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin>>a[i][j];
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    cout<<a[0][0]<<endl;
    return 0;
}