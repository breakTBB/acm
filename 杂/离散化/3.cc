#include <bits/stdc++.h>

using namespace std;

// void myswap(int x, int y)
// {
//     int t;
//     t = x;
//     x = y;
//     y = t;
// }

//��2������ַ
// void myswap(int *p1, int *p2)
// {
//     int t;
//     t = *p1;
//     *p1 = *p2;
//     *p2 = t;
// }
//��3���������β�
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
    printf("�����������������������");
    scanf("%d %d", &a, &b);
    myswap(a, b);
    printf("���ý���������Ľ���ǣ�%d �� %d\n", a, b);
    return 0;
}
