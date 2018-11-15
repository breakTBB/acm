#include <bits/stdc++.h>

using namespace std;

int v[1000010];
int dp[100010];

int main(int argc, char const *argv[])
{
    int cas;
    cin >> cas;
    while(cas--) {
        int cnt;
        cin >> cnt;
        fill(dp, dp+100010, 0);
        for (int i = 0; i < cnt; i++) cin >> v[i];
        int package;
        cin >> package;
        for(int i = 0; i < cnt; i++)
            for(int j = v[i]; j <= package; j++)
                dp[j] = min(dp[j], dp[j - v[i]] + 1);
        if (dp[package] == ) cout << -1;
        else cout << dp[package];
    }
    system("pause");
    return 0;
}
