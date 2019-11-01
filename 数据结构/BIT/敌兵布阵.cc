#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret;
}
const int N = 5e5 + 10;
int bit[N];
char op[10];
int le, ri, val;

int lowbit(int x) {
    return x & -x;
}
int add(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) bit[i] += v;
}
int ask(int x) {
    int ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) ret += bit[i];
    return ret;
}

int main() {
    int kase = 1;
    int T = read();
    while(T--) {
        printf("Case %d:\n", kase++);
        memset(bit, 0, sizeof bit);
        int n = read();
        rep(i, 1, n) add(i, read());
        while(scanf("%s", op), strcmp(op, "End")) {
            if (op[0] == 'Q') {
                le = read(), ri = read();
                printf("%d\n", ask(ri) - ask(le - 1));
            }
            if (op[0] == 'A') {
                le = read(), val = read();
                add(le, val);
            }
            if (op[0] == 'S') {
                le = read(), val = read();
                add(le, -val);
            }
        }
    }
}