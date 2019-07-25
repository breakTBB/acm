#include <cstdio>
#include <cctype>
#include <algorithm>

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) {ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar();}
    return ret * f;
}

const int N = 1e6 + 10;
const int M = 2e3 + 10;
int a[N], cnt[M];
int n, m;

int main() {
    n = read(); m = read();
    rep(i, 1, n) a[i] = read();
    int s = 1, t = 1, num = 0, res = n, l = 1, r  = n;
    for(;;) {
        while(t <= n && num < m) {
            if (cnt[a[t++]]++ == 0) num++;
        }
        if (num < m) break;
        if (t - s < res) {
            res = t - s;
            l = s; r = t - 1;
        }
        if (--cnt[a[s++]]==0) num--;
    }
    printf("%d %d", l , r);
}