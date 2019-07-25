#include <bits/stdc++.h>

using namespace std;

int power[50010];

int main()
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
        scanf("%d", &power[i]);
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (power[i] > 0)
        {
            cnt--;
        }
        else
        {
            break;
        }
    }
    int need = 0;
    int p = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (power[i] > 0)
            p += power[i];
        else
        {
            if (p + power[i] < 0)
            {
                need += p + power[i];
                p = 0;
            }
            else
            {
                p = p + power[i];
            }
        }
    }
    cout << -need;
    system("pause");
}


int main2()
{
    int n;
    scanf("%d", &n);
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        scanf("%lld", &x);
        sum += x;
        ans = min(ans, sum);
    }
    cout << -ans << endl;
}
