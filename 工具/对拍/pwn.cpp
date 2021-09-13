#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, id;
} res[2000005];
vector<int> G[2000005];
int mp[2000005];
int v[2000005];
int sum[2000005];
int K[2000005];
int H[200005];
int c[200005];
int n, k;
void update(int x, int y)
{
    for (;x <= n;x += x & -x)
    {
        c[x] += y;
    }
}
int ask(int x)
{
    int ans = 0;
    for (;x;x -= x & -x)
        ans += c[x];
    return ans;
}
int main()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[i] = x;
    }
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1];
        v[mp[i]]++;
        if (v[mp[i]] == 1) {
            sum[i]++;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        H[mp[i]] = i;
    }
    memset(v, 0, sizeof v);
    for (int i = 1;i <= n;i++)
    {
        res[i] = { mp[i],sum[i],i };
    }
    sort(res + 1, res + 1 + n, [&](node a, node b) {
        if (a.y == b.y)
            if (a.x == b.x)
                return a.id < b.id;
            else
                return a.x < b.x;
        return a.y > b.y;
        });

    int u = k;
    int ans = 0;
    int l = 0;
    for (int i = 1;i <= n;i++)
    {
        if (v[res[i].x] == 0 && res[i].y - ans + ask(res[i].id) == k && l < res[i].id)
        {
            cout << res[i].x << ' ';
            k--;

            v[res[i].x] = 1;
            update(H[res[i].x] + 1, 1);
            ans++;
            l = res[i].id;
        }
    }
    return 0;
}
