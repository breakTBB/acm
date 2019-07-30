/*
	Author : feng_chengjie
	Language : C++
	Problem : LG1983
	BlogUrl : https://www.luogu.org/blog/cap-fcj/solution-p1983
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,ans=0,tot=0;
int a[1002],dep[1002],in[1002],is[1002],head[1002],vis[1002][1002];
struct point
{
    int to;
    int nxt;
}edge[3000010];
inline long long read()
{
    long long Sum=0;
    int F=1;
    char c=getchar();
    while(c>'9' || c<'0')
    {
        if(c=='-')
            F=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        Sum=Sum*10+c-'0';
        c=getchar();
    }
    return Sum*F;
}
void add(int u,int v)
{
    tot++;
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot;
}
void Topo_sort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    if(in[i]==0)
    {
        q.push(i);    
        dep[i]=1;        
    }
    while(!q.empty())
    {
        int tt=q.front();
        q.pop();
        for(int i=head[tt];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            dep[v]=dep[tt]+1;
            ans=max(ans,dep[v]);
            in[v]--;
            if(in[v]==0)
                q.push(v); 
        }
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        memset(a,0,sizeof(a));
        memset(is,0,sizeof(is));
        int nn;
        cin>>nn;
        for(int j=1;j<=nn;j++)
        {
            cin>>a[j];
            is[a[j]]=1;            
        }
        for(int j=a[1]+1;j<=a[nn];j++)
            if(!is[j])
                for(int p=1;p<=nn;p++)
                {
                    if(!vis[j][a[p]])
                    {
                        in[a[p]]++;
                        add(j,a[p]);
                        vis[j][a[p]]=1;
                    }
                }
    }
    Topo_sort();
    cout<<ans;
    return 0;
}
