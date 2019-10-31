#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
typedef long long ll;

using namespace std;

int read() {
	register int ret = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar(); }
	return ret;
}

const int N = 5e4 + 10;
int dis[N];
int l, n, m;

int chk(int x) {
    int cnt = 0;
    int last = 0;
    rep(i, 1, n + 1) {
        if (dis[i] - last < x) cnt++;
        else last = dis[i];
    }
    return cnt <= m;
}

int main() {
	cin >> l >> n >> m;
    rep(i, 1, n) cin >> dis[i];
    dis[n + 1] = l;
    int l = 0, r = l;
    while(l < r) {
        int mid = l + (r - l) / 2 + 1;
        if (chk(mid)) l = mid;
        else r = mid - 1;
    }
}