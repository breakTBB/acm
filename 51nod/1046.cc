// A^B%C
#include <stdio.h>
#include <stdlib.h>

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

struct x {
    int abcd;
    int xyz;
};

int main(int argc, const char * argv[])
{
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%ld\n", PowerMod(A, B, C));
    system("pause");
    return 0;
}
