#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N];
int vis[N];
int n, m;
int cal(ll mid)
{
    ll sum = 0;
    int cnt = 1;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i];
        if (sum > mid)
        {
            sum = a[i];
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        ll l = -1e9, r = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);

            l = max(l, a[i]); ///切记这里
            r += a[i];
        }
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (cal(mid) <= m)
                r = mid;
            else
                l = mid + 1;
        }
        //cout<<l<<endl;
        ll sum = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = n; i >= 1; i--)
        {
            if (m > i) ///不能大于等于
            /*
		   6
           6 4
           50 100 50 50 50 200
           */
            {

                for (int j = 1; j <= i; j++)
                    vis[j] = 1;
                break;
            }
            sum += a[i];
            if (sum > l)
            {
                vis[i] = 1;
                sum = a[i];
                m--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);

            if (vis[i] && i < n)
                printf(" /");
        }
        printf("\n");
    }
    return 0;
}