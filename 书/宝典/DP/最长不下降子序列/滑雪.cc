#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

int f[110][110], mp[110][110];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
struct node {
    int x, y, num;
    bool operator < (const node& rhs) const {
        return num > rhs.num;
    }
};
priority_queue<node> q;

int get(int x, int y, int now) {
    return mp[x][y] < now ? f[x][y] + 1 : 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 1, n) rep(j, 1, m) {
        f[i][j] = 1;
        mp[i][j] = read();
        node now;
        now.x = i, now.y = j, now.num = mp[i][j];
        q.push(now);
    }
    int mx = 1;
    while(!q.empty()) {
        node now = q.top(); q.pop();
        int x = now.x, y = now.y;
        rep(i, 0, 3) f[x][y] = max(f[x][y], get(x + dx[i], y + dy[i], now.num));
        mx = max(mx, f[x][y]);
    }
    cout << mx << endl;
}