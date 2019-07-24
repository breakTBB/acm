// 每一位是一个int的字符串Hash

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int maxn = 1e6 + 10;

ull has[maxn], p[maxn] = { 1 };

const int base = 131;
int sa[maxn];
int sb[maxn];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> sa[i];
			p[i] = p[i - 1] * base;
			has[i] = has[i - 1] * base + (sa[i] + 1000000);
		}
		ull test = 0;
		for (int i = 1; i <= m; i++) {
			int c;
			cin >> c;
			test = test * base + (c + 1000000);
		}
		int ans = -1;
		for (int i = 1; i + m - 1 <= n; i++) {
			if (has[i + m - 1] - has[i - 1] * p[m] == test) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}