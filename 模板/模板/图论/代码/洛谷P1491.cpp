/*
	Author : Frozen_Heart 
	Language : C++
	Problem : LG1491
	BlogUrl : https://www.luogu.org/blog/45206/solution-p1491
*/
#include<bits/stdc++.h>
using namespace std;
int read()//���
{
    int x=0,w=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*w;
}
int cnt;
int x[210],y[210],head[210],vis[210],team[500010],from[210],bian[210],s[500010];
double dis[210];//ע�⿪double
struct node{
int to,next;double v;
}edge[500010];
void add(int a,int b)
{
    cnt++;
    edge[cnt].to=b;
    edge[cnt].next=head[a];
    edge[cnt].v=sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
    head[a]=cnt;
}
void spfa()
{
    memset(dis,127,sizeof(dis));
    int l=0,r=1,u,v;
    team[1]=1;vis[1]=1;dis[1]=0;
    while(l<r)
    {
        l++;
        u=team[l];
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].next)
        {
            v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].v)
            {
                dis[v]=dis[u]+edge[i].v;
                from[v]=u;//��¼ǰ��
                if(!vis[v])
                {
                    vis[v]=1;
                    r++;
                    team[r]=v;
                }
            }
        }
    }
}
void spfa2(int x,int y)// ����ע����Ҫ��spfa��spfa2�ģ�pfa��spfa2�ģ���Ϊ��һ��Ҫ��¼ǰ���ڵ㡣���󼸴������Ȼ��¼�Ļ��������ĵݹ�ͻ�����ˣ���������Ϊ��һ��Ҫ��¼ǰ���ڵ㡣���󼸴������Ȼ��¼�Ļ��������ĵݹ�ͻ�����ˣ��������忴д����Ҳ���Ե�һ��spfa��ֱ�ӵݹ�ѱ�������������������Ͳ���Ҫ�ֿ�д������_
{
    memset(dis,127,sizeof(dis));
    int l=0,r=1,u,v;
    team[1]=1;vis[1]=1;dis[1]=0;
    while(l<r)
    {
        l++;
        u=team[l];
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].next)
        {
            v=edge[i].to;
            if((v==y&&u==x)||(v==x&&u==y)) continue;
            if(dis[v]>dis[u]+edge[i].v)
            {
                dis[v]=dis[u]+edge[i].v;
                if(!vis[v])
                {
                    vis[v]=1;
                    r++;
                    team[r]=v;
                }
            }
        }
    }
}
int main()
{
    int n,m,xi,yi;
    double minn=90000000;
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        x[i]=read();y[i]=read();
    }
    for(int i=1;i<=m;i++)
    {
        xi=read();yi=read();
        add(xi,yi);
        add(yi,xi);
    }
    spfa();
    int v=n;
    double tmp;
    while(v!=1)
    {
        spfa2(v,from[v]);
        if(dis[n]<minn) minn=dis[n];
        v=from[v];
    }
    if(minn==90000000)
    {
        printf("-1");
        return 0;
    }
    else
    printf("%.2lf\n",minn);
}
