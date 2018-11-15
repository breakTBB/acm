// --------------------- 
// 作者：f_zyj 
// 来源：CSDN 
// 原文：https://blog.csdn.net/f_zyj/article/details/51187056 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
#include <bits/stdc++.h>
#include <stdio.h>
#define _MAX 100000000
int main()
{
    int n, i, j, m;
    long long a[10000], c;
    scanf("%d",&n);

    m = 0;
    a[0] = 1;
    for(i = 1; i <= n; i++)
    {
        c = 0;
        for(j = 0; j <= m; j++)
        {
            a[j] = a[j] * i + c;
            c = a[j] / _MAX;
            a[j] %= _MAX;
        }
        if(c > 0)
        {
            m++;
            a[m] = c;
        }
    }
    printf("%lld", a[m]);
    for(i = m - 1; i >= 0; i--)
        printf("%0.8lld", a[i]);
    printf("\n");
    system("pause");
    return 0;
}