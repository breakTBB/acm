#include <cstdio>
#include <cctype>
#include <algorithm>

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int N = 1e5 + 5;
int a[N];

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) {ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar();}
    return ret * f;
}

int main() {
    int T = read();
    while(T--) {
        int n, s;
        n = read(), s = read();
        rep(i, 1, n) a[i] = read();
        int ans = 0x3f3f3f3f;
        int l = 0, r = 0, sum = 0;
        for(;;) {
            // 一直加，没有每次更新是因为没有满足 > s 的条件
            while(r <= n && sum < s) sum += a[r++];
            if (sum < s) break;
            ans = min(ans, r - l);
            // 只能移动一位，因为每次要取最小值，每次移动都有可能满足
            sum -= a[l++];
        }
        if (ans == 0x3f3f3f3f) puts("0");
        else printf("%d\n", ans);
    }
    return 0;
}