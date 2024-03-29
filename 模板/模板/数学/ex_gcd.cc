// https://amoshyc.github.io/ojsolution-build/template/math/crt.html


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Item {
    ll m, r;
};

ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        ll d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

Item extcrt(const vector<Item>& v) {
    ll m1 = v[0].m, r1 = v[0].r, x, y;

    for (int i = 1; i < int(v.size()); i++) {
        ll m2 = v[i].m, r2 = v[i].r;
        ll g = extgcd(m1, m2, x, y); // now x = (m/g)^(-1)

        if ((r2 - r1) % g != 0)
            return { -1, -1 };

        ll k = (r2 - r1) / g * x % (m2 / g);
        k = (k + m2 / g) % (m2 / g); // for the case k is negative

        ll m = m1 * m2 / g;
        ll r = (m1 * k + r1) % m;

        m1 = m;
        r1 = (r + m) % m; // for the case r is negative
    }

    return (Item) { m1, r1 };
}

int main() {
    int K;
    while (scanf("%d", &K) != EOF) {
        vector<Item> v;
        for (int i = 0; i < K; i++) {
            Item item;
            scanf("%lld %lld", &item.m, &item.r);
            v.push_back(item);
        }

        printf("%lld\n", extcrt(v).r);
    }

    return 0;
}