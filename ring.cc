/* n个人，先去掉第M个人，然后从M+1开始报1
报到K的退出，剩下的继续从1开始报数
求胜利者的编号 */

/* 函数图像解法
N个人数到K出列，最后剩下的人编号 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k, m;
    while(cin >> n >> k >> m, n||k||m) {
        int i, d, s = 0;
        for(i = 2; i <= n; i++)
            s = (s + k) % i;
        k %= n;
        if(0 == k) {
            k = n;
        }
        d = (s + 1) + (m - k);
        if(d >= 1 && d <= n)
            cout << d << "\n";
        else if(d < 1)
            cout << n + d << "\n";
        else if(d > n)
            cout << d % n << "\n";
    }
    
    return 0;
}
