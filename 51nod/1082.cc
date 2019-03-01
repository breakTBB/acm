#include <stdio.h>
#include <string.h>
#define N 1000009
bool B[N];
__int64 num[N];
void hehe()
{
    __int64 i, j, k, m;
    for (i = 7; i < N; i += 7) //7的倍数
        B[i] = true;


    for (i = 1; i < N; i *= 10) //数位上含7的数
    {
        m = i * 10;
        for (j = i * 7; j < N; j += m)
        {
            for (k = 0; k < i; k++)
                B[k + j] = true;
        }
    }

    
    num[0] = 0;
    num[1] = 1;
    for (i = 2; i < N; i++)
    {
        if (!B[i])
            num[i] = num[i - 1] + i * i;
        else
            num[i] = num[i - 1] + 0;
    }
}
int main()
{
    __int64 t, n;
    scanf("%I64d", &t);
    memset(B, 0, sizeof(B));
    hehe();
    while (t--)
    {
        scanf("%I64d", &n);
        printf("%I64d\n", num[n]);
    }
}
