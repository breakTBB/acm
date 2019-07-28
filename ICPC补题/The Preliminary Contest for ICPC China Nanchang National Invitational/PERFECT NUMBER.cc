// 比赛的时候不要傻等着
// 线性筛更快，要带板子

#include <bits/stdc++.h>

using namespace std;

const int N = 50000000;
int f[N + 1];

void init() {
	for (int i = 2; i <= N; i++) {
		f[i]++;
		for (int j = 2 * i; j <= N; j += i) {
			f[j] += i;
		}
	}
}

int main() {
	init();
	for (int i = 2; i <= N; i++) {
		if (f[i] == i) cout << i << endl;
	}
}