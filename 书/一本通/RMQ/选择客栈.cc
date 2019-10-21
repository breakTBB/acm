#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
int n, k, p, co, mo, las, now;
int last[N], cnt[N], sum[N];

int main() {
	scanf("%d%d%d", &n, &k, &p);
	ll ans = 0;
	rep(i, 1, n) {
		scanf("%d%d", &co, &mo);
		if (mo <= p) {
			now = i;
		}
		if (now >= last[co]) sum[co] = cnt[co];
		ans += sum[co];
		last[co] = i, cnt[co]++;
	}
	cout << ans;
	return 0;
}