#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define mid ((sgt[id].l + sgt[id].r) >> 1)
#define lc (mid << 1)
#define rc (mid << 1 | 1)
#define inf 0x3f3f3f3f
typedef long long ll;

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}
// TODO
const int N = 1e5 + 10;
struct SegmentTree {
    int l, r, col, sum;
}sgt[N << 2];

int main() {

}