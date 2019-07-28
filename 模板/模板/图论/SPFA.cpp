/*洛谷 模板 单源最短路径（弱化版）*/
/*玄学而广为人知的最短路求法*/
#include<bits/stdc++.h>
using namespace std;

const int inf=2147483647;
const int maxn=10005;
int n,m,b,e=0,i,j;
int dis[maxn],head[500005];
bool vis[maxn];
struct node
{
  int next,to,dis;
}edge[500005]; 

queue<int> q;
void addedge(int from,int to,int dis)
{
    edge[++e].next=head[from];
    edge[e].dis=dis;
    edge[e].to=to;
    head[from]=e;
}

void spfa()
{
    for(i=1;i<=n;i++) dis[i]=inf;
    dis[b]=0;
    q.push(b),vis[b]=1;
    while(!q.empty())
    {
        int begin=q.front();
        q.pop(); 
        for(i=head[begin];i;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[begin]+edge[i].dis)
            {
                dis[edge[i].to]=dis[begin]+edge[i].dis;
                if(!vis[edge[i].to]) 
                {
                    vis[edge[i].to]=1;
                    q.push(edge[i].to);
                }
            }
        }
        vis[begin]=0;
    }
}
int main()
{
    cin>>n>>m>>b;
    for(int i=1; i<=m; i++)
    {
        int f,t,d;
        cin>>f>>t>>d; 
        addedge(f,t,d); 
    }
    spfa(); 
    for(int i=1; i<=n; i++)
        if(b==i) cout<<0<<' '; 
        else cout<<dis[i]<<' ';
    return 0;
}
