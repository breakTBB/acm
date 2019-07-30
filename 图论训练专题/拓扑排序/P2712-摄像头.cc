// 注意看题目！！！
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
	ret = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = 0; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret = f ? ret : -ret;
}
inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret;
}
template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

const int N = 600;
int n;
int u, v, w, t, tt;
vector<int> G[N];
vector<int> head;
queue<int> q;
int in[N], vis[N], cnt;
int camera[N][N];

int main() {
	read(n);
	rep(i, 1, n) {
		read(u), read(t);
		head.push_back(u);
		rep(i, 1, t) {
			read(tt); in[tt]++;
			camera[u][tt] = 1;
		}
	}
	int sz = head.size();
	rep(i, 0, sz - 1) {
		if (!in[head[i]]) q.push(head[i]), cnt++;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 1;
		int sz = head.size();
		rep(i, 0, sz - 1) {
			if (camera[u][head[i]]) {
				in[head[i]]--;
				if (!in[head[i]] && !vis[head[i]]) q.push(head[i]), cnt++;
			}
		}
	}
	if (cnt == n) puts("YES");
	else printf("%d", n - cnt);
}