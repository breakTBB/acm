#include <bits/stdc++.h>

#define maxn 100001

int id[maxn];
int appear[maxn];

using namespace std;

void init() {
	memset(id, -1, sizeof id);
	memset(appear, 0, sizeof appear);
}

int find(int x) {
	return -1 == id[x] ? x : id[x] = find(id[x]);
}

int judge(int x, int y) {
	return find(x) == find(y);
}

void join(int x, int y) {
	if (judge(x, y)) return;
	id[find(x)] = find(y);
}

int main() {
	int n, m, flag = 1, cnt = 0;
	init();
	while (~scanf("%d%d", &n, &m) && (n != -1 || m != -1)) {
		if (n == 0 && m == 0) {
			if (cnt == 0) {
				printf("Yes\n");
				continue;
			}
			int sum = 0;
			for (int i = 0; i < maxn; ++i) {
				if (appear[i] && id[i] == -1) {
					sum += 1;
					if (sum > 1) break;
				}
			}
			if (flag == 1 && sum == 1) puts("Yes");
			else puts("No");
			flag = 1;
			cnt = 0;
			init();
		}
		else {
			if (judge(n, m)) flag = 0;
			join(n, m);
			appear[n] = appear[m] = 1;
			cnt++;
		}

	}
}