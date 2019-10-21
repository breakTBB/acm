#include <bits/stdc++.h>

#ifdef _DEBUG
#define dbg(x) cout << #x << " = " << (x) << endl;
#define hi puts("hi!");
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#endif // _DEBUG

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)

const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

ll x, y;
ll ex_gcd(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = ex_gcd(b, a % b);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
int main(void) {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll a, b, c;
    a = w, b = d, c = p;
    ll g = ex_gcd(a, b);
    if (c % g) {
        puts("-1");
        return 0;
    }
    ll x1, y1, x2, y2;

    ll t = b / g;
    if (t < 0)
        t = -t;
    x1 = ((x * c / g) % t + t) % t;
    y1 = (c - a * x1) / b;
    if (y1 < 0) y1 = -y1;

    t = a / g;
    if (t < 0)
        t = -t;
    y2 = ((y * c / g) % t + t) % t;
    x2 = (c - b * y2) / a;
    if (x2 < 0) x2 = -x2;

    int mx, my;

    if (x1 + y1 < x2 + y2)
        mx = x1, my = y1;
    else
        mx = x2, my = y2;
    if (mx + my > n) {
        puts("-1");
        return 0;
    }
    cout << mx << ' ' << my << ' ' << n - mx - my << endl;
    return 0;
}
