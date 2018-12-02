// A^B%C

#include <stdio.h>
// 1 1 1 1 1 1 1 1
// 2 4 8 6 2 4 8 6
// 3 9 7 1 3 9 7 1
// 4 6 4 6 4 6 4 6
// 5 5 5 5 5 5 5 5
// 6 6 6 6 6 6 6 6
// 7 9 3 1 7 9 3 1
// 8 4 2 6 8 4 2 6
// 9 1 9 1 9 1 9 1
// 0 0 0 0 0 0 0 0

long PowerMod(long long A, long long B, long long C)
{
    long ans = 1;
    A %= C;
    while (B > 0)
    {
        if (B % 2 == 1)
        {
            ans = (ans * A) % C;
        }
        B /= 2;
        A = (A * A) % C;
    }
    return ans;
}

int pm(int a, int b, int c) {     
    long ans = 1;
    a = a % c;
    while (b > 0) {
        if (b&1==1) {
            ans = (ans * a) %c;
        }
        b /= 2;
        a = (a * a) % c;
    }
}

int main(int argc, const char * argv[])
{
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%ld\n", PowerMod(A, B, C));
    return 0;
}
