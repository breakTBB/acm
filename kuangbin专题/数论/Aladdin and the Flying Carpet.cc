#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=1e6+5;
const int INF=0x3f3f3f3f;
int cnt;
bool v[N];
LL prime[80000];

void getprime()
{
    for(int i=2; i*i<=N-5; ++i)
        if(!v[i])
            for(int j=i*i; j<=N-5; j+=i)
                v[j]=1;
    for(int i=2; i<=N-5; ++i)
        if(!v[i])
            prime[++cnt]=i;
}
vector<LL>fac[2];
int divisors[5000],tot;
LL k;


void dfs(int pos,LL res)
{
    if(pos==fac[0].size())
    {
        divisors[++tot]=res;
        return;
    }
    for(LL i=0,now=1; i<=fac[1][pos]; now*=fac[0][pos],++i)
    {
        if(now*res>=k)
            break;
        dfs(pos+1,res*now);
    }
}


int main()
{
    getprime();
    int cas=0,T;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d: ",++cas);
        LL a,b;
        scanf("%lld%lld",&a,&b);
        k=sqrt(a);
        if(k*k!=a)++k;
        if(b>=k)
        {
            printf("0\n");
            continue;
        }
        LL t=a;
        fac[0].clear(),fac[1].clear();
        for(int i=1; i<=cnt&&prime[i]*prime[i]<=t; ++i)  ///质因数分解
        {
            if(t%prime[i])
                continue;
            int tmp=0;
            fac[0].push_back(prime[i]);
            while(t%prime[i]==0)
                ++tmp,t/=prime[i];
            fac[1].push_back(tmp);
        }
        if(t>1)
        {
            fac[0].push_back(t);
            fac[1].push_back(1);
        }
        tot=0;
        dfs(0,1);
        int ans=0;
        for(int i=1; i<=tot; ++i)
            if(divisors[i]>=b)
                ++ans;
        printf("%d\n",ans);
    }
    return 0;
}