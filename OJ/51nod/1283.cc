#include <bits/stdc++.h>

using namespace std;

int main() {
	int area;
	cin >> area;
	int c = 0, minc = INT_MAX;
	for (int i = 1; i * i <= area; i++) {
		int j = area / i;
		if (j * i != area) continue;
		if (i <= j) {
			c = i + j;
			minc = min(minc, c);
		}
	}
	cout << 2 * minc;
	
}