#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl;

using namespace std;

const int N = 5e5 + 10;
int cnt[N], a[N];
int p[N], v[N], tot;
int num;

void init() {
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            p[++tot] = i;
            for (int j = i; j < N / i; j++) {
                v[i * j] = 1;
            }
        }
    }
}

int main() {
    init();
    int t; cin >> t;
    int kase = 1;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        int n; cin >> n;
        rep(i, 1, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        
        for (int i = 1; i < N; i++) {
            if (cnt[i]) {
                for (int j = 2; i * j < N; j++) {
                    if (v[j]) cnt[i * j]++;
                }
            }
        }
        
        int mx = 0;
        rep(i, 1, n) {
            dbg(cnt[a[i]]);
            mx = max(cnt[a[i]], mx);
        }
        printf("Case %d: %d", kase++, mx);
    }
}