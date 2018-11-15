#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int v[maxn], f[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    f[0] = 1;
    for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <=n; ++i)
        for(int j = m; m >= v[i]; --j)
            f[j] += f[j-v[i]]; //现在的花费+=不点这个菜的花费
    cout << f[m] << endl;
    system("pause");
    

}