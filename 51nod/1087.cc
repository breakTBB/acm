#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9 + 10;

int main() {
	int cnt = 0;
	cin >> cnt;
	while (cnt--) {
		int idx = 0;
		cin >> idx;
		idx--;
		int d = 0;
		for (int i = 0; i < maxn; i+=d) {
			d++;
			if (i == idx) {
				cout << "1" << endl;
				break;
			}
			if (i > idx) {
				cout << "0" << endl;
				break;
			}
		}	
	}
} 