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

const int N = 100010;
struct node {
    int id, x, y;
    bool operator < (const node& rhs) {
        if (x != rhs.x) return x < rhs.x;
        return y > rhs.y;
    }
}v[N];
int st[N], top;
int pre[N], ans[N];

void print(int now) {
    dbg(now);
    if (!now) return;
    print(pre[now]);
    printf("%d ", v[now].id);
}

int main() {
    int n = read();
    rep(i, 1, n) v[i].id = i, v[i].x = read(), v[i].y = read();
    sort(v + 1, v + n + 1);
    st[++top] = -inf;
    rep(i, 1, n) {
        if (v[i].y > st[top]) pre[i] = st[top - 1], st[++top] = i;
        else {
            int l = 1, r = top;
            while(l <= r) {
                int mid = (l + r) / 2;
                if (v[mid].y < v[i].y) l = mid + 1;
                else r = mid - 1;
            }
            st[l] = i;
            pre[i] = st[l - 1];
        }
    }
    printf("%d\n", top - 1);
    print(st[top]);
}