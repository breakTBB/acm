#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define inf 0x3f3f3f3f
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) { ret = ret * 10 + c - '0'; c = getchar(); }
    return ret * f;
}

int main() {
    double v[2], m = 1;
    int n = read();
    scanf("%lf", &v[0]);
    rep(i, 2, n) {
        scanf("%lf", &v[i - 1 & 1]);
        if (v[i - 1 & 1] > v[i & 1]) m = m / v[i & 1] * v[i - 1 & 1];
    }
    printf("%.4f\n", m);
}