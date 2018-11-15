#include <bits/stdc++.h>

using namespace std;

int price[100010];
int dp[1000010];

int main()
{
    int cnt;
    int tmp;
    int money;
    // vector<int> price;
    // vector<int> dp;
    while ((cin >> cnt))
    {
        fill(dp,dp+1010,0);
        fill(price, price+1010,0);
        if (!cnt)
            break;
        for (int i = 0; i < cnt; i++)
            cin >> price[i];
        cin >> money;
        if (money < 5)
        {
            cout << money << endl;
            continue;
        }
        money -= 5;
        sort(price, price + cnt);
        int maxn = price[cnt - 1];
        for (int i = 0; i < cnt - 1; i++)
            for (int j = money; j >= price[i]; j--)
                dp[j] = max(dp[j], dp[j - price[i]] + price[i]);
        int ans = money + 5 - dp[money] - maxn;
        cout << ans << endl;
    }
}