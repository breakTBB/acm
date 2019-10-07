#include <iostream>
using namespace std;
#define LL long long
#define ll long long
LL w;
struct Point//x + y*sqrt(w)
{
    LL x;
    LL y;
};
  
LL mod(LL a, LL p)
{
    a %= p;
    if (a < 0)
    {
        a += p;
    }
    return a;
}
  
Point point_mul(Point a, Point b, LL p)
{
    Point res;
    res.x = mod(a.x * b.x, p);
    res.x += mod(w * mod(a.y * b.y, p), p);
    res.x = mod(res.x, p);
    res.y = mod(a.x * b.y, p);
    res.y += mod(a.y * b.x, p);
    res.y = mod(res.y , p);
    return res;
}
  
Point power(Point a, LL b, LL p)
{
    Point res;
    res.x = 1;
    res.y = 0;
    while(b)
    {
        if (b & 1)
        {
            res = point_mul(res, a, p);
        }
        a = point_mul(a, a, p);
        b = b >> 1;
    }

    return res;
}

LL quick_power(LL a, LL b, LL p)//(a^b)%p
{
    LL res = 1;
    while(b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b = b >> 1;
    }
    return res;
}
LL Legendre(LL a, LL p) // a^((p-1)/2)
{
    return quick_power(a, (p - 1) >> 1, p);
}

LL equation_solve(LL b, LL p)//求解x^2=b(%p)方程解
{
    if (b == 0)
        return 0;
    if ((Legendre(b, p) + 1) % p == 0)
    {
        return -1;//表示没有解
    }

    LL a, t;
    while(true)
    {
        a = rand() % p;
        t = a * a - b;
        t = mod(t, p);
        if ((Legendre(t, p) + 1) % p == 0)
        {
            break;
        }
    }

    w = t;
    Point temp, res;
    temp.x = a;
    temp.y = 1;
    res = power(temp, (p + 1) >> 1, p);
    return res.x;
}
int Mod = 1e9 + 7;
ll Pow(ll x, int y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res = res * x % Mod;
        x = x * x % Mod;
        y /= 2;
    }
    return res;
}

ll input(){
    ll x=0,f=0;char ch=getchar();
    while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return f? -x:x;
}

int main() {
    int T=input();
    while(T--){
        ll b=input(),c=input(),x,y,p=1e9+7;
        ll k=((b*b%p-4*c%p)+p)%p;//右边一堆 
        ll tmp=equation_solve(k,p);
        //tmp就是这个解，tmp*tmp=k%p 
  		//判断是否有解 
        if(tmp==-1){
            printf("-1 -1\n");
            continue;
        }

        ll inv=Pow(2,Mod-2);

        x=(b+tmp)%p*inv%p;
        y=(b-tmp+p)%p*inv%p;
 		//x最小时的解 
        if(x>y) swap(x,y);
        printf("%lld %lld\n",x,y);
    }  
    return 0;
}