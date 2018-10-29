// #include<cstdio>
// #include<iostream>
// using namespace std;
// int main()
// {
//     //留k+1个给别人就能赢
//     int n,k;
//     cin>>n>>k;
//     if(n%(k+1)) cout<<1;else cout<<2;
//     return 0;
// }
//剩 1 和另一堆偶数
//将奇数拆成1 另一个偶数
//a&1==0 偶数 else 奇数
//统计非1奇数的个数a和所有非1数的个数b
//求出拆分次数和合并次数，根据操作次数的奇偶性判断

//实现的代码是如下原理
// 分别计算出奇数和偶数的数目，当没有偶数的时候，只要有一个可分（即不全为1）的Alice就可赢，否则Bob赢。

// 当有偶数且个数也为偶数的时候Alice就可赢，否则Bob赢。
// 1 3 A
// 1 1 2 B

#include <stdio.h>
int main()
{
    //na  odd
    //nb 1' counts
    int a, n, na, nb;
    scanf("%d", &n);
    na = nb = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if ((a & 1)==0)
            na++;
        if (a == 1)
            nb++;
    }
    //nb != n 即不全为1
    if (na==0 && nb != n || na && (na & 1)==0)
        puts("Alice");
    else puts("Bob");

    return 0;
}

//if(an==0) --> if(!an)
