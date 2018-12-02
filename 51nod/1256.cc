// 给出2个数M和N(M < N)，且M与N互质，找出一个数K满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。
#include <iostream>

using namespace std;

/*
 *  扩展欧几里得法（求ax + by = gcd）
 */
//  返回d = gcd(a, b);和对应于等式ax + by = d中的x、y
long long extendGcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
    {
        return -1;  //  无最大公约数
    }
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extendGcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//  求逆元 ax = 1(mod n)
long long modReverse(long long a, long long n)
{
    long long x, y;
    long long d = extendGcd(a, n, x, y);
    if (d == 1)
    {
        return (x % n + n) % n;
    }
    else
    {
        return -1;  //  无逆元
    }
}

int main(int argc, const char * argv[])
{
    long long M, N;

    while (cin >> M >> N)
    {
        cout << modReverse(M, N) << '\n';
    }

    return 0;
}