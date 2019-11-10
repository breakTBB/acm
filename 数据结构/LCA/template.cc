#include<cstdio>
#include<iostream>
using namespace std;
int n,m,s,num=0,head[1000001],dep[1000001],f[1000001][23];
int a1,a2;
struct edg{
    int next,to;
}edge[1000001];
void edge_add(int u,int v)//链式前向星存图 
{
    num++;
    edge[num].next=head[u];edge[num].to=v;head[u]=num;
    edge[++num].next=head[v];edge[num].to=u;head[v]=num;
}
void dfs(int u,int father)//对应深搜预处理f数组 
{
    dep[u]=dep[father]+1;
    for(int i=1;(1<<i)<=dep[u];i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father)continue;//双向图需要判断是不是父亲节点 
        f[v][0]=u;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)//从大到小枚举使x和y到了同一层 
    {
        if(dep[f[x][i]]>=dep[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=20;i>=0;i--)//从大到小枚举 
    {
        if(f[x][i]!=f[y][i])//尽可能接近 
        {
            x=f[x][i];y=f[y][i];
        } 
    } 
    return f[x][0];//随便找一个**输出 
}
int main() {
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++) {
        scanf("%d",&a1);scanf("%d",&a2);
        edge_add(a1,a2);//链式存边
    }
    dfs(s,0);
    for(int i=1;i<=m;i++) {
        scanf("%d %d",&a1,&a2);
        printf("%d\n",lca(a1,a2));//求两个节点的LCA 
    }
}