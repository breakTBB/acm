#include <bits/stdc++.h>

using namespace std;

int A[50010];

int main() {
	int K;
	int cnt;
	cin >> K >> cnt;
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + cnt);
	bool flag = false;
	int lft = 0;
	int rht = cnt - 1;
	while (lft < rht) {
		if (A[lft] + A[rht] == K) {
			flag = true;
			cout << A[lft] << " " << A[rht] << endl;
		}
		else if (A[lft] + A[rht] > K) rht--;
		else lft++;
	}
	if (!flag) cout << "No Solution";
}