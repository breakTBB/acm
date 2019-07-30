/*
	Author : zpf_13516358919 
	Language : C++
	Problem : LG2888
	BlogUrl : https://www.luogu.org/blog/user18386/solution-p2888
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define LL long long
const int INF=0x7fffffff;
LL map[310][310];
int n,m,t,x,y,v;
using namespace std;
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    map[i][j]=INF;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&v);
        map[x][y]=v;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(map[i][j]>max(map[i][k],map[k][j]))//�㷨�ľ���
    map[i][j]=max(map[i][k],map[k][j]); 
         //��i��j��������·��i->k��k->j�������ֵ�����Һ�map[i][j]�Ƚϴ�С 
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        if(map[x][y]==INF)
        printf("-1\n");
        else
        printf("%d\n",map[x][y]);
    }
    return 0;
}
