// https://vijos.org/p/2010

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
	ret = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = 0; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret = f ? ret : -ret;
}
inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret;
}
template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

const int N = 3e4 + 10;
int a[N];
int w, n;

int isLeap(int n) {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) return 1;
	return 0;
}
int isBig(int m) {
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return true;
	return false;
}
int isDate(int n) {
	if (n < 10000000) return 0;
	int y = (n / 10000);
	int m = (n / 100) % 100;
	int d = n % 100;
	if (m < 1 || m > 12) return 0;
	if (m == 2) {
		if (isLeap(y)) {
			if (d < 1 || d > 29) return 0;
		} else {
			if (d < 1 || d > 28) return 0;
		}
	}
	if (isBig(m)) {
		if (d < 1 || d > 31) return 0;
	} else {
		if (d < 1 || d > 30) return 0;
	}
	return 1;
}

int reverse(int n) {
	int ret = n / 10000;
	n = n / 10000;
	while (n) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	/*int y1, m2, d2;
	scanf("%4d%2d%2d", &y1, &m2, &d2);
*/
	int d1 = 0, d2 = 0;
	scanf("%d%d", &d1, &d2);
	int ans = 0;
	for (int i = d1; i <= d2; i += 10000) {
		if (isDate(reverse(i))) ans++;
	}
	cout << ans;
}