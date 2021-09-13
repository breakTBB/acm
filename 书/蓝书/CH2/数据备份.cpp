#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 1e5 + 7;
int n, k, a[N];
int pre[N], nxt[N], tot;
ll val[N];
struct node {
    ll v, id;
    bool operator < (const node& rhs) {
        return v > rhs.v;
    }
};
priority_queue<node> q;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i > 1; i--) a[i] -= a[i - 1];
    int lst = 0;
    for (int i = 2; i <= n; i++) {
        val[++tot] = a[i]; pre[tot] = lst; nxt[lst] = tot;
        lst = tot;
        q.push({ val[tot], tot });
    }
    ll ans = 0;
    while (k--) {
        dbg(q.top().v);
        node tp = q.top();
        ans += tp.v;
        ll v = val[pre[tp.id]] + val[nxt[tp.id]] - val[tp.id];
        val[++tot] = v;
        pre[tot] = pre[pre[tp.id]]; nxt[tot] = nxt[nxt[tp.id]];
        nxt[pre[pre[tp.id]]] = tot; pre[nxt[nxt[tp.id]]] = tot;
        q.push({ val[tot], tot });
    }
    cout << ans << endl;
    return 0;
}