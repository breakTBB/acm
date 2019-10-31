#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

string mid, post;

void solve(int lmid, int rmid, int lpost, int rpost) {
    cout << post[rpost - 1];
    int p = mid.find(post[rpost - 1]);
    if (lmid < p) solve(lmid, p, lpost, lpost + p - lmid);
    if (p + 1 < rmid) solve(p + 1, rmid, lpost + p - lmid, rpost - 1);
}

int main() {
    cin >> mid >> post;
    solve(0, mid.size(), 0, post.size());
}