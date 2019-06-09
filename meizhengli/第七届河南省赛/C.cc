#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        b = 0;
        return a;
    } else {
        y -= a/ b * x;
        ex_gcd(b, a % b, y, x);
    }
}

int main() {
    int k;
    scanf("%d", &k);
    int x, y, s, t;
    while(k--) {
        scanf("%d%d%d%d", &x, &y, &s, &t);
    }

}