#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int fa[N];
inline int read() {
	int f = 1, x = 0; char ch;
	do { ch = getchar(); if (ch == '-')f = -1; } while (ch<'0' || ch>'9');
	do { x = x * 10 + ch - '0'; ch = getchar(); } while (ch >= '0'&&ch <= '9');
	return f * x;
}
int size[N];
inline int find(int x) { if (fa[x] != x)return find(fa[x]); else return x; }
//inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx == yy)return;
	if (size[xx]>size[yy])swap(xx, yy);
	fa[xx] = yy; size[yy] += size[xx];
}
int n, m, q;
int main() {
	n = read(); m = read();
	for (int i = 1; i <= n; i++)fa[i] = i, size[i] = 1;
	while (m--) {
		int opt = read(), x = read(), y = read();
		if (opt == 1)merge(x, y);
		else {
			int xx = find(x), yy = find(y);
			if (xx == yy)puts("Y"); else puts("N");
		}
	}
}