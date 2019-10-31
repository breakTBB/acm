#include <bits/stdc++.h>
using namespace std;

const int INF  = 0x3f3f3f3f;
const int maxn = 500002;
const int Mod  = 1e9 + 7;

#define ll       long long
#define mem(x,y) memset(x,y,sizeof(x))
#define IO       ios_base::sync_with_stdio(0);

struct node {
    int v, type, id;
    node(int a, int b): v(a), type(b) {}
    node(int a, int b, int c): v(a), type(b), id(c) {}
};

vector<node>edge[maxn];
int type[maxn], ans = 0, vis[maxn];
int dfs1(int x) {
    vis[x] = 1;
    for (int i = 0; i < edge[x].size(); i++) {
        node t = edge[x][i];
        if (vis[t.v]) continue;
        ans++;
        if (t.type == 1) dfs1(t.v);
        else if (t.type == 2) type[t.id] = 1, dfs1(t.v);
        else if (t.type == 3) type[t.id] = 0, dfs1(t.v);
    }
    return ans;
}
int dfs2(int x) {
    vis[x] = 1;
    for (int i = 0; i < edge[x].size(); i++) {
        node t = edge[x][i];
        if (vis[t.v]) continue;
        if (t.type == 1) dfs2(t.v), ans++;
        else if (t.type == 2) type[t.id] = 0;
        else if (t.type == 3) type[t.id] = 1;
    }
    return ans;
}
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    int a, b, c, cnt = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1) edge[b].push_back(node(c, 1));
        else {
            edge[b].push_back(node(c, 2, ++cnt));
            edge[c].push_back(node(b, 3, cnt));
        }
    }
    cout << dfs1(x) + 1 << endl;
    for (int i = 1; i <= cnt; i++)
        printf("%c", type[i] ? '+' : '-' );
    printf("\n");

    mem(vis, 0);
    ans = 0;
    cout << dfs2(x) + 1 << endl;
    for (int i = 1; i <= cnt; i++)
        printf("%c", type[i] ? '+' : '-');
    printf("\n");

}