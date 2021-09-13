#include <iostream>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl;
#define FILEIO freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

using namespace std;

typedef long long ll;

const int N = 1e7 + 7;
bool v[N];
int p[1000010];
int tot;

int t, n, cnt, kase = 1;

int main() {
    FILEIO
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            p[++tot] = i;
            for (int j = i; (ll)i * j < N; j++) {
                v[i * j] = true;
            }
        }
    }
    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n;
        rep(i, 1, tot) {
            if (p[i] > n / 2) break;
            if (!v[n - p[i]]) cnt++;
        }
        printf("Case %d: %d\n", kase++, cnt);
    }
}