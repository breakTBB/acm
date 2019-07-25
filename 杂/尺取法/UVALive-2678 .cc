// 一定要注意conor case 这个输出0也说不过去啊...

#include <bits/stdc++.h>
#define lson (o<<1)
#define rson (o<<1|1)
#define fi first
#define sc second
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define rep(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const double eps = 1e-6;
inline int lowbit(int x) { return x & (-x); }
inline int read() {
	int f = 1, x = 0; char ch;
	do { ch = getchar(); if (ch == '-')f = -1; } while (ch<'0' || ch>'9');
	do { x = x * 10 + ch - '0'; ch = getchar(); } while (ch >= '0' && ch <= '9');
	return f * x;
}

const int N = 1e5;
int a[N + 1];
int n, s;

int main() {
	while (cin >> n >> s) {
		rep(i, 1, n) a[i] = read();
		int l = 1, r = 2, ans = 0x3f3f3f3f, sum = a[l];
		for (;;) {
			while (r <= n && sum < s) sum += a[r++];
			if (sum < s) break;
			ans = min(ans, r - l);
			sum -= a[l++];
		}
		if (ans == 0x3f3f3f3f) cout << 0 << endl;
		else cout << ans << endl;
	}
}