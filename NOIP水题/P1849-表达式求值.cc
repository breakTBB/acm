// 有限状态自动机
// https://vijos.org/p/1849

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

//status = 1 d
//status = 2 d + or d*
//status = 3 d + d
//status = 4 d + d *

const int mod = 10000;

int main() {
	ll o1, o2, o3, status;
	char op1, op2;
	scanf("%lld", &o1);
	o1 %= mod;
	status = 1;
	for (;;) {
		if (status == 1) {
			scanf("%c", &op1);
			if (op1 == '+' || op1 == '*') status = 2;
			else break;
		}
		else if (status == 2) {
			scanf("%lld", &o2);
			if (op1 == '*') {
				o1 *= o2;
				o1 %= mod;
				status = 1;
			}
			else if (op1 == '+') {
				status = 3;
			}
		}
		else if (status == 3) {
			scanf("%c", &op2);
			if (op2 == '*') status = 4;
			else if (op2 == '+') {
				o1 += o2;
				o1 %= mod;
				op1 = op2;
				status = 2;
			}
			else {
				o1 += o2;
				o1 %= mod;
				break;
			}
		}
		else if (status == 4) {
			scanf("%lld", &o3);
			o2 *= o3;
			o2 %= mod;
			status = 3;
		}
		else break;
	}
	printf("%lld", o1);
}