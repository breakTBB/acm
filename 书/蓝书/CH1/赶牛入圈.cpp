// link: https://www.acwing.com/problem/content/124/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int c, n;
vector<int> v;
const int N = 1010;
int sum[N][N];
int x[N], y[N];

int getid(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
bool check(int len) {
    n = v.size();
    for (int x1 = 1, x2 = 2; x2 < n; x2++) {
        while (v[x2] - v[x1] + 1 > len) ++x1;
        for (int y1 = 1, y2 = 2; y2 < n; y2++) {
            while (v[y2] - v[y1] + 1 > len) ++y1;
            if (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] >= c) return true;
        }
    }
    return false;
}
int main() {
    cin >> c >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 1; i <= n; i++) {
        sum[getid(x[i])][getid(y[i])]++;
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int l = 1, r = 1010;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}