#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll invcnt[32][2];

void func(vector<int>& a, int ind) {
	if (a.empty())return;
	if (ind == -1)return;
	ll cnt1 = 0;
	ll cnt2 = 0;
	int ones = 0;
	int zers = 0;
	vector<int> left, right;
	for (auto x : a) {
		if ((x >> ind) & 1) {
			ones++;
			cnt2 += zers;
			right.push_back(x);
		}
		else {
			zers++;
			cnt1 += ones;
			left.push_back(x);
		}
	}
	invcnt[ind][0] += cnt1;
	invcnt[ind][1] += cnt2;
	func(left, ind - 1);
	func(right, ind - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(32);

	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	memset(invcnt, 0, sizeof(invcnt));
	func(a, 29);
	ll ans = 0;
	ll x = 0;
	for (int i = 0; i < 30; i++) {
		if (invcnt[i][0] <= invcnt[i][1]) {
			ans += invcnt[i][0];
		}
		else {
			ans += invcnt[i][1];
			x ^= (1 << i);
		}
	}
	cout << ans << " " << x << '\n';

	return 0;
}