#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double INF = 1e10;
const int N = 1e5 + 7;
int t, n;
struct node {
    double x, y;
    int tp;
    bool operator < (const node& rhs) {
        return x < rhs.x;
    }
}P[N], tmp[N];
double md = 1e10;
double dist(node i, node j) {
    if (i.tp == j.tp) return md;
    return sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
}
double dfs(int l, int r) {
    if (l >= r) return INF;
    int mid = l + r >> 1, midx = P[mid].x;
    double mn = min(dfs(l, mid), dfs(mid + 1, r));
    {
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r) {
            if (P[i].y < P[j].y) tmp[k++] = P[i++];
            else tmp[k++] = P[j++];
        }
        while (i <= mid) tmp[k++] = P[i++]; while (j <= r) tmp[k++] = P[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++) P[i] = tmp[i - l];
    int k = 0;
    for (int i = l; i <= r; i++) {
        if (P[i].x <= midx + mn && P[i].x >= midx - mn) tmp[k++] = P[i];
    }
    for (int i = 0; i < k; i++) {
        for (int j = i - 1; j >= 0 && tmp[i].y - tmp[j].y < mn; j--) {
            mn = min(dist(tmp[i], tmp[j]), mn);
        }
    }
    md = min(mn, md);
    return mn;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("C:\\Users\\PRISM17\\CLionProjects\\untitled\\cmake-build-debug\\inq.txt", "r", stdin);
    cin >> t;
    while (t--) {
        md = 1e10;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y; P[i].tp = 0;
        }
        for (int i = n; i < 2 * n; i++) {
            cin >> P[i].x >> P[i].y; P[i].tp = 1;
        }
        random_shuffle(P, P + 2 * n);
        sort(P, P + 2 * n);
        printf("%.3lf\n", dfs(0, 2 * n - 1));
    }
}