// link: https://atcoder.jp/contests/dp/tasks/dp_w
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 7;
struct sgt {
#define lson (id << 1)
#define rson (id << 1 | 1)
#define mid (st[id].l + st[id].r >> 1)
    int index;
    struct node {
        int l, r;
        ll lz;
        ll mx;
    }st[N << 2];
    void pushnow(int id, ll val) {
        st[id].mx += val;
        st[id].lz += val;
    }
    void pushup(int id) {
        st[id].mx = max(st[lson].mx, st[rson].mx);
    }
    void pushdown(int id) {
        if (st[id].lz) {
            pushnow(lson, st[id].lz); pushnow(rson, st[id].lz);
            st[id].lz = 0;
        }
    }
    void build(int id, int l, int r) {
        st[id].l = l; st[id].r = r;
        if (l == r) {
            st[id].mx = 0;
            return;
        }
        build(lson, l, mid); build(rson, mid + 1, r); pushup(id);
    }
    void update(int id, int l, int r, ll val) {
        if (st[id].l > r || st[id].r < l) return;
        if (st[id].l >= l && st[id].r <= r) {
            pushnow(id, val);
            return;
        }
        pushdown(id);
        update(lson, l, r, val); update(rson, l, r, val);
        pushup(id);
    }
    ll query(int id, int l, int r) {
        if (st[id].l > r || st[id].r < l) return LONG_LONG_MIN;
        if (st[id].l >= l && st[id].r <= r) {
            return st[id].mx;
        }
        pushdown(id);
        return max(query(lson, l, r), query(rson, l, r));
    }
}st;
ll add[N];
vector<pii> del[N];
int n, m;
ll dp[N];

int main() {
    cin >> n >> m;
    for (int i = 1, l, r, a; i <= m; i++) {
        cin >> l >> r >> a;
        add[l] += a;
        del[r + 1].emplace_back(make_pair(l, a));
    }
    st.build(1, 0, n + 1);
    for (int i = 1; i <= n + 1; i++) {
        st.update(1, 0, i - 1, add[i]);
        for (pii x : del[i]) {
            st.update(1, 0, x.first - 1, -x.second);
        }
        st.update(1, i, i, st.query(1, 0, i - 1));
    }
    cout << st.query(1, 0, n) << endl;
}