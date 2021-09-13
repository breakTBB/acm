#include <bits/stdc++.h>

using namespace std;

// void myswap(int x, int y)
// {
//     int t;
//     t = x;
//     x = y;
//     y = t;
// }

//（2）传地址
// void myswap(int *p1, int *p2)
// {
//     int t;
//     t = *p1;
//     *p1 = *p2;
//     *p2 = t;
// }
//（3）引用作形参
void myswap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

int main()
{
    int a, b;
    printf("请输入待交换的两个整数：");
    scanf("%d %d", &a, &b);
    myswap(a, b);
    printf("调用交换函数后的结果是：%d 和 %d\n", a, b);
    return 0;
}
