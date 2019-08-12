#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
const int inf = 0x3f3f3f3f;
int _, __, ___;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
	ret = 0; T f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
}
ll read() {
	ll ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret * f;
}

const int N = 1e5 + 10;
char str[N];
int len;

int go(char* str) {
	len = strlen(str);
	for (int i = 0; i + 2 < len; i++) {
		if (str[i] == str[i + 1] && str[i] == str[i + 2]) {
			strcpy(str + i, str + i + 3);
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%s", str);
	int cnt = 0;
	while (go(str)) cnt++;
	printf("%d", cnt);
}