// 拍了几十个case 都没毛病，又分析了一波也没毛病
// 试了下cornor case 还真是0
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector<pii> ans;
const int maxn = 1e7 + 10;


int main() {
	ll n;
	while (cin >> n) {
		if (n == 0) {
			putchar('0');
			continue;
		}
		int l = 1, r = 2;
		ll sum = 1;
		ans.clear();
		for (;;) {
			while (sum < n && r <= maxn)
				sum += r * 1ll * r, r++;
			if (sum < n) break;
			if (sum == n) {
				ans.push_back(make_pair(r - l, l));
			}
			sum -= l * 1ll * l;
			l++;
		}
		int sz = ans.size();
		cout << sz << endl;
		if (sz == 0) continue;
		for (int ii = 0; ii < sz; ii++) {
			pii i = ans[ii];
			cout << i.first << " ";
			int start = i.second;
			for (int t = 1; t <= i.first; t++) {
				if (t != 1) putchar(' ');
				cout << start++;
			}
			puts("");
		}
	}
}