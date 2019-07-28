#include<iostream>
#include<cstdio>
using namespace std; 
const int maxn=1e5+10;
int n,m;
const int ch_top=4e7;
char ch[ch_top],*now_r=ch-1,*now_w=ch-1;
int mx[maxn][22];
int lg[maxn];
int max(int a,int b){return a>b?a:b;}
inline int query(int l,int r)
{
    int k=lg[r-l+1];
    return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int main()
{
    lg[0]=-1;for(int i=1;i<maxn;i++)lg[i]=lg[i>>1]+1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&mx[i][0]);
    for(int j=1;j<=22;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    while(m--){int l,r;scanf("%d%d",&l,&r);printf("%d\n",query(l,r));}
}
