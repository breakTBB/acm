// 按照这种思路写，不要纠结用哪种方式
// head = tail = 0;
// while(head < tail)
// q[tail - 1] < a[i];
// q[tail++] = i;

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int a[N], q[N], q2[N], head, tail, head2, tail2;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		while (head < tail && q[head] <= i - k) head++;
		while (head2 < tail2 && q2[head2] <= i - k) head2++;
		while (head < tail && a[q[tail - 1]] < a[i]) tail--;
		q[tail++] = i;
		while (head2 < tail2 && a[q2[tail2 - 1]] > a[i]) tail2--;
		q2[tail2++] = i;
		if (i >= k) printf("%d %d\n", a[q[head]], a[q2[head2]]);
	}
}