#include <bits/stdc++.h>

using namespace std;

int const  maxn = 1010;
int F[maxn];
bool vis[maxn][maxn];
bool use[maxn];
int n, d;

struct Point {
    int x, y;
}p[maxn];

void init() {
    memset(vis, 0, sizeof(vis));
    fill(use, use+maxn, 0);
    for (int i = 0; i < maxn; i++)
        F[i] = i;
}

int find(int root) {
    int tmp, son = root;
    while(root != F[root])
        root = F[root];
    while (son != root) {
        tmp = F[son];
        F[son] = root;
        son = tmp;
    }
    return root;
}

void join(int u, int v) {
    int fu = find(u);
    int fv = find(v);
    if (fu != fv) {
        F[fu] = fv;
    }
}

bool isCom(Point u, Point v) {
    if ((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y)<=d*d)
        return true;
    return false;
}

int main() {
    init();
    while (cin >> n >> d) {
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &p[i].x, &p[i].y);
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; ++j) {
                if(isCom(p[i],p[j]))
                    vis[i][j] = true;
            }
        }
        char ch;
        int x, y;
        while (cin >> ch) {
            if (ch == 'o') {
                scanf("%d", &x);
                if (!use[x]) {
                    for (int j = 1; j <= n; j++) {
                        if (use[j] && vis[x][j])
                            join(x, j);
                    }
                    use[x] = true;
                }
            } else {
                scanf("%d%d", &x, &y);
                if (find(x) == find(y)) printf("SUCCESS\n");
                else printf("FAIL\n");
            }
        }
    }
}