#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;
LL ans[maxn];

int main() {
	for (LL i = 1; i < maxn; i++) {
		int d1 = i % 10;
		int d2 = (i/10) % 10;
		int d3 = (i/100) % 10;
		int d4 = (i/1000) % 10;
		int d5 = (i/10000) % 10;
		int d6 = (i/100000) % 10;
		int d7 = (i/100000) % 10;
		if (i % 7 == 0||d1==7||d2==7
			||d3==7||d4==7||d5==7
			||d6==7||d7==7) {
				ans[i] = ans[i-1];
			}
		else {
			ans[i] = ans[i-1] + i * i;
		}
	}
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
} 