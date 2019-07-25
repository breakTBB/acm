// 树状数组
// 离散

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;
int t[MAXN];


// 计算 a[1]+a[2]+...+a[x]
int getSum(int x) {
    int sum = 0;
    for(int i = x; i > 0; i-=x&(-x))
        sum += t[x];
    return sum;
}

// 执行[x]=changeValue
void modify2(int x, int changeValue) {
    for (int i = x; i <= MAXN; i+=x&(-x))
        t[i] += changeValue;
}

void modify(int x) {
    for (int i = x; i <= MAXN; i+=x&(-x))
        t[i] += 1;
}

int main() {
    pair<int, int> p[MAXN];
    int gg[MAXN];
    int n, num, ans;
    scanf("%d", &n);
    // hash 

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++) {
        gg[p[i].second] = i;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num);
        modify(num);
        ans += i - getSum(i);
    }
    printf("%d", ans);
}


