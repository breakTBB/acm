#include <stdio.h>

long long gcd(long long m, long long n){
    return n==0?m:gcd(n,m%n);
}
void judge(long long a, long long b, long long c){
    if(a==0){
        puts("YES\n");
        return;
    }
    long long tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    while(b>1&&c>1){
        c = gcd(c, b);
        b /= c;
    }
    if(b==1){
        puts("YES\n");
    }else{
        puts("NO\n");
    }
}
int main(){
    long long cnt, a, b, c;
    scanf("%lld", &cnt);
    while(cnt--){
        scanf("%lld%lld%lld", &a, &b, &c);
        judge(a,b,c);
    }
}