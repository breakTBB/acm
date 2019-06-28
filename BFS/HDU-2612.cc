#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e2 + 10;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char mp[maxn][maxn];
bool vis[maxn][maxn];
int d[2][maxn][maxn];

int m, n;

void dfs(int x, int y, int k) {
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while(!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            d[k][tx][ty] = d[k][x][y] + 1;
            if (tx < 1 || tx > m || ty < 1 || ty > n || mp[tx][ty] == '#') continue;
            q.push(make_pair(tx, ty));
            vis[tx][ty] = true;
        }
    }

}

int main() {
    pair<int, int> n1, n2;
    while(cin >> m >> n) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == 'Y') {
                    n1.first = i; n2.second = j;
                }
                if (mp[i][j] == 'M') {
                    n1.first = i; n2.second = j;
                }
            }
        }
        dfs(n1.first, n1.first, 0);
        dfs(n2.first, n2.first, 1);
        int mn = INT_MAX;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mp[i][j] == '@') {
                    mn = min(mn, d[0][i][j] + d[0][i][j]);
                }
            }
        }
        cout << mn;
    }
}