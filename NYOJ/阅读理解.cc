// 线性筛 + 前缀和

#include <bits/stdc++.h>

const int maxn = 1e5 + 10;
int prime[10000];
bool not_prime[maxn];
int pre[maxn];
int prime_cnt;

using namespace std;

void init() {
    for (int i = 2; i < maxn; i++) {
        pre[i] = pre[i - 1];
        if (!not_prime[i]) {
            prime[++prime_cnt] = i;
            pre[i]++;
        }
        for (int j = 1; j <= prime_cnt; ++j) {
            if (i * prime[j] >= maxn) break;
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
        
    }
}

int main()
{
    pre[0] = 1;
    pre[1] = 2;
    init();
    not_prime[0] = not_prime[1] = false;
    int a,b,cnt=0;
    while(~scanf("%d%d", &a, &b))
    {
        printf("Case %%%d:",++cnt);
        printf("%d\n", pre[b] - pre[a - 1]);
    }
}