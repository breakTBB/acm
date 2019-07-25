#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long b[10000],n,k,tot,sum,a[1000],c[1000];
bool check(int y)
{
    if(y == 1) return false;
    for(int i = 2;i <= sqrt(y);i ++)
    if(y % i == 0) return false;
    return true;
}

//X己选的数的个数
//Y和
//J当前的下标
void dfs(int x,int y,int j)
{
    cout<<"已选"<<x<<"个数"<<"和为"<<y<<"当前第"<<j<<"个数"<<"\n";
    if(x == k)
    {
        if(check(y)) tot++;
        return ;
    }
    for(int i = j+1;i <= n;i ++)
    dfs(x + 1,y + a[i],i);
    return;
}
int main()
{
    //N个数中选K个数
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i ++)
        scanf("%d",&a[i]);
    dfs(0,0,0);
    printf("%d",tot);
    system("pause");
    return 0;
}