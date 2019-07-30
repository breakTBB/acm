/*
	Author : lovewhy
	Language : C++
	Problem : LG1195
	BlogUrl : https://www.luogu.org/blog/user39886/solution-p1195
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1005
using namespace std;
int n,m,k,x,y,l,sum,ans;
int fa[N];
struct Edge
{
    int u,v,w;
    bool operator <(Edge a) const    //����������ĺ���д������Ļ������const
    {
        return w<a.w;
    }
}edge[N*10];
/*bool operator <(Edge a,Edge b)    //����������ĺ���д������Ļ����ܼ�const
{
        return a.w<b.w;
}*/
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge+1,edge+m+1);    //�������������� 
    for(int i=1;i<=m;i++)
    {
        int fx=find(edge[i].u),fy=find(edge[i].v);
        if(fx!=fy)        //����������㲻��ͬһ������ 
        {
            fa[fx]=fy;
            sum++;        //��һ���ߣ������Ǻϲ���Ϊһ���� 
            ans+=edge[i].w;        //���Ϻϲ��Ĵ��� 
        }
        if(sum==n-k)        //�Ѿ�������k���� 
        {
            printf("%d",ans);
            return 0;
        }
    }
    puts("No Answer");    //���������� 
    return 0;
}
