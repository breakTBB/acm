#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	int num;
	bool flag = false;
	cin >> num;
	for (int i = 0; i < sqrt(num); i++) {
		if ((int)sqrt(num - i * i) * (int)sqrt(num - i * i) + i * i == num) {
		    flag = true;
			if (i <= sqrt(num - i * i))
			cout << i << " " << sqrt(num - i * i) << endl;
		}
	}
	if (!flag) cout << "No Solution";
	
}