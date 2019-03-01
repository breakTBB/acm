#include <bits/stdc++.h>

using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	// int ans = cnt;
	stack<int> x;
	int size, direction;
	int ans = 0;
	for(;;) {
		cnt--;
		scanf("%d%d", &size, &direction);
		if (direction == 1) {
			x.push(size);
			break;
		} else {
			ans++;
		}
	}
	while (cnt--) {
		scanf("%d%d", &size, &direction);
		if (direction == 0) {
			// 向左 
			while (!x.empty()) {
				int left = x.top();
				if (size > left) {
					x.pop();
				} else {
					break;
				}
			}
			if (x.empty()) {
				ans++;
			}
		} else {
			// 向右 
			x.push(size);
		} 
	}
	cout << x.size() + ans;
}