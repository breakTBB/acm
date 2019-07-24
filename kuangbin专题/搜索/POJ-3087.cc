// Shuffle'm Up
// https://vjudge.net/problem/POJ-3087
// 不能用!vis[s1] || !vis[s2]
// 因为s1 和 s2 跟顺序有关 s1 s2 和s2 s1洗出来的牌是不一样的

#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, len, ans, cas, reachable;
char s1[110], s2[110], res[300], tmp[300];

int main() {
	scanf("%d", &t);
	while (t--) {
		map<string, bool> vis;
		ans = 0;
		scanf("%d%s%s%s", &len, s1, s2, res);
		reachable = false;

		while (!vis[tmp]) {
			vis[tmp] = true;
			vis[s1] = vis[s2] = true;
			ans++;
			int ia = 0, ib = 0;
			for (int i = 0; i < len * 2; i++) {
				if (i & 1) tmp[i] = s1[ia++];
				else tmp[i] = s2[ib++];
			}
			tmp[len * 2] = '\0';
			if (strcmp(res, tmp) == 0) {
				reachable = true;
				break;
			}
			ia = 0; ib = 0;
			for (int i = 0; i < len; i++) {
				s1[ia++] = tmp[i];
			}
			for (int i = len; i < len * 2; i++) {
				s2[ib++] = tmp[i];
			}
			s1[ib] = s2[ia] = '\0';
		}
		cout << ++cas << " ";
		if (reachable) cout << ans << endl;
		else cout << -1 << endl;
	}
}