// 区间素数筛，枚举不超过sqrt(R)的所有质数p，
// 然后再去枚举[L, R]区间内p的倍数，将之划去，
// 最后区间内剩下的就都是素数了。注意一点，1需要特判不是素数。
#include <bits/stdc++.h>

using namespace std;

int not_prime[1000000];

int prime[1000000]; //质数表

int prime_count = 0; //质数的个数

int main()
{
    int n;
    cin >> n;
    memset(not_prime, 0, sizeof(not_prime));
    not_prime[1] = true; //1不是质数
    for (int i = 2; i <= n; i++) {

        if (!not_prime[i])
            prime[++prime_count] = i; //把i放入质数表prime[]
        for (int j = 1; j <= prime_count; ++j) //枚举质数表中的每一个数
        {
            if (prime[j] * i > n) break;
            not_prime[prime[j] * i] = true; //翻倍，一个数×另一个数一定为合数
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= prime_count; i++) cout << prime[i] << endl;
    system("pause");
}