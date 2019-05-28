// d(i)表示i的约数个数
// num[i]表示i的最小素因子的个数
// prime[i]表示第i个素数

#include <bits/stdc++.h>

const int N=1e5+5;
bool mark[N];
int prim[N],d[N],num[N];
int cnt;

void Euler(){
    memset(isprime,1,sizeof isprime); sd[1]=1;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            prime[++tot]=i;
            sd[i]=1+i; num[i]=1+i;
        }
        for(int j=1;j<=tot&&prime[j]*i<=n;j++){
            isprime[i*prime[j]]=0;
            if(i%prime[j]!=0){
                sd[i*prime[j]]=sd[i]*sd[prime[j]];
                num[i*prime[j]]=prime[j]+1;
            }
            else{
                sd[i*prime[j]]=sd[i]/num[i]*(num[i]*prime[j]+1);
                num[i*prime[j]]=num[i]*prime[j]+1; break;
            }
        }
    }
}


void initial()
{
    cnt=0;
    d[1]=1;
    for (int i=2 ; i<N ; ++i)
    {
        if (!mark[i])
        {
            prim[cnt++]=i;
            num[i]=1;
            d[i]=2;
        }
        for (int j=0 ; j<cnt && i*prim[j]<N ; ++j)
        {
            mark[i*prim[j]]=1;
            if (!(i%prim[j]))
            {
                num[i*prim[j]]=num[i]+1; //加个prim[j]
                d[i*prim[j]]=d[i]/(num[i]+1)*(num[i*prim[j]]+1); //转移
                break;
            }
            d[i*prim[j]]=d[i]*d[prim[j]]; //两个加上
            num[i*prim[j]]=1; //最小的就是一个prim[j];
        }
    }
}