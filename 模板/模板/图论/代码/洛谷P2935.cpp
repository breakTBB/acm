/*
	Author : ws_fuweidong
	Language : C++
	Problem : LG2935
	BlogUrl : https://www.luogu.org/blog/user8629/solution-p2935 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define maxn 501
#define inf 99999999
using namespace std;
int dis[maxn][maxn],n,m,ff,f[maxn];
int main(){
    scanf("%d%d%d",&n,&ff,&m);
    for (int i=1;i<=ff;i++)
    scanf("%d",&f[i]);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    if (i==j) dis[i][j]=0;else
    dis[i][j]=inf;
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y]=z;
        dis[y][x]=z;
    }
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    if (dis[i][j]>dis[i][k]+dis[k][j])
    dis[i][j]=dis[i][k]+dis[k][j];
    int minn=0x7fffffff,l;
    for (int i=1;i<=n;i++)
    {
        int sum=0;
        for (int j=1;j<=ff;j++)
        if (dis[i][f[j]]!=inf)
        sum+=dis[i][f[j]];
        if (sum<minn){
            minn=sum;
            l=i;
        }
    }
    printf("%d",l);
    return 0;
}
