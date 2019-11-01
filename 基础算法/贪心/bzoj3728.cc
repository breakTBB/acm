#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define pii pair<int, int>
typedef long long ll;

using namespace std;

int read() {
	register int ret = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar(); }
	return ret;
}

const int N = 5e5 + 10;
int p[N], w[N];
multiset<int> st;
priority_queue<int, vector<int>> q;

int main() {
	int n, k;
    n = read(), k = read();
    rep(i, 1, n) p[i] = read();
    sort(p + 1, p + n + 1);
    rep(i, 1, n) w[i] = read(), st.insert(w[i]);
    rep(i, 1, n) {
        
    }
}