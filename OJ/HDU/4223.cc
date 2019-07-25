#include <bits/stdc++.h>

using namespace std;

int num[1010];
int pre[1010];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int n;
		cin >> n;
		memset(num, 0, sizeof(num));
		memset(pre, 0, sizeof(pre));
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			if (i == 0) pre[i] = num[i];
			else pre[i] = pre[i - 1] + num[i];
		}
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) ans = min(abs(pre[i]), ans);
		sort(pre, pre + n);
		
		
		for (int i = 1; i < n; i++) {
			int tmp = abs(pre[i] - pre[i - 1]);
			if (tmp < ans) ans = tmp;
		}
		printf("Case %d: %d\n", cas, ans);
	}
}