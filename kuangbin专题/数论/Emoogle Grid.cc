#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << (x) << endl;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int N = 2e5 + 7;
int p[10000010];
int mx;
int a[N];
int etot;

int dg[100010];
struct node {
    int num, cnt;
    bool operator < (const node& rhs) {
        return num < rhs.num;
    }
}nodes[N];

int nxt[N], edge[N], ver[N], head[N];

void add(int u, int v) {
    ver[++etot] = v;
    nxt[etot] = head[u]; head[u] = etot;
}
queue<int> q;
int vis[N];
int f[10000010];
vector<int> tt[100005];
int dfs(int u, int sum) {

int kk=0;
for(int i=0;i<tt[u].size();i++)
{
    kk=max(kk,dfs(tt[u][i],sum)+node[u].cnt);
}

if(kk==0)
    kk+=node[u].cnt;


    return kk;
}

int main() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        p[a[i]]++;
        mx = max(mx, a[i]);
    }
    int tot = 0;
    rep(i, 1, n) {
        if (!vis[a[i]]) vis[a[i]] = 1, nodes[++tot] = {a[i], p[a[i]]};
    }
    int tmp = mx;
    mx = sqrt(mx);

    sort(nodes + 1, nodes + tot + 1);

    rep(i, 1, tot) {
        f[nodes[i].num] = i;
    }

    rep(i, 1, tot) {
        int now = nodes[i].num;
        if (nodes[i].num <= mx) {
            rep(j, i + 1, tot) {
                if (nodes[j].num % now == 0) {

                tt[j].push_back(i);
                    dg[i]++;
                }
            }
        }
        if (nodes[i].num > mx) {
            for (int j = now * 2; j <= tmp; j += now) {
                if (p[j]) {

                    tt[f[j]].push_back(i);

                    dg[i]++;
                }
            }
        }
    }
    int mmx = 0;
    rep(i, 1, tot) {
        if (!dg[i]) {
            mmx = max(mmx, dfs(i, 0));
        }
    }
    cout << mmx << endl;



}
