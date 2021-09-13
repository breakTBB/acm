# include <bits/stdc++.h>
# define RG register
# define IL inline
# define Fill(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
const int _(1e5 + 5);

IL int Input() {
    RG int x = 0, z = 1; RG char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) z = c == '-' ? -1 : 1;
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x * z;
}

int n, k, rt[_], tot;
struct HJT {
    int ls, rs, sz;
} T[_ * 20];
vector <int> num[_];

IL void Modify(RG int& x, RG int l, RG int r, RG int p) {
    T[++tot] = T[x], ++T[x = tot].sz;
    if (l == r) return;
    RG int mid = (l + r) >> 1;
    if (p <= mid) Modify(T[x].ls, l, mid, p);
    else Modify(T[x].rs, mid + 1, r, p);
}

IL int Query(RG int x, RG int l, RG int r, RG int p) {
    if (!x) return 0;
    if (l == r) return T[x].sz;
    RG int mid = (l + r) >> 1;
    if (p <= mid) return Query(T[x].ls, l, mid, p);
    return T[T[x].ls].sz + Query(T[x].rs, mid + 1, r, p);
}

int main(RG int argc, RG char* argv[]) {
    n = Input(), k = Input();
    for (RG int i = 1, a, b; i <= n; ++i) {
        a = Input(), num[a].push_back(i);
        RG int l = num[a].size();
        if (l <= k) b = 0;
        else b = num[a][l - k - 1];
        rt[i] = rt[i - 1], Modify(rt[i], 0, n, b);
    }
    for (RG int q = Input(), ans = 0; q; --q) {
        RG int l = Input(), r = Input();
        l = (l + ans) % n + 1, r = (r + ans) % n + 1;
        if (l > r) swap(l, r);
        printf("%d\n", ans = Query(rt[r], 0, n, l - 1) - Query(rt[l - 1], 0, n, l - 1));
    }
    return 0;
}