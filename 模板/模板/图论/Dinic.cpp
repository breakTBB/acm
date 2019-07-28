/*��� ģ�� ���������*/
/*Dinic ������������㷨*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=10010;
const int maxm=200010;
const int inf=1<<30;
int head[maxn],tot=-1;
int maxflow=0;
int n,m,s,t;

struct edge {
    int v,w,next;
} G[maxm];

void addedge(int u,int v,int w,bool flag) {
    G[++tot].v=v;
    if(flag) G[tot].w=w;//��ͼ�ı�ȨΪ0
    G[tot].next=head[u];
    head[u]=tot;
}

int dep[maxn],head2[maxn];
int que[maxn*2];

bool bfs(int s,int t) {
    queue<int> q;
    memset(dep,0x7f,sizeof(dep));
    while(!q.empty())
        q.pop();
    dep[s]=0;
    q.push(s);
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        for (int i=head[now]; i; i=G[i].next) {
            if(dep[G[i].v]>inf&&G[i].w) {
                dep[G[i].v]=dep[now]+1;
                q.push(G[i].v);
            }
        }
    }
    return dep[t]<inf;
}

int dfs(int now,int t,int limit) {//now�ǵ�ǰ�ڵ㣬t�ǻ�㣬limit�ǵ�ǰ����
    if (!limit||now==t) return limit;
    int flow=0,f;
    for (int i=head[now]; i; i=G[i].next) {
        if (dep[G[i].v]==dep[now]+1&&(f=dfs(G[i].v,t,min(limit,G[i].w)))) {
            flow+=f;
            limit-=f;
            G[i].w-=f;
            G[i|1].w+=f;//��Ϊÿ�μ������ߣ�����^1�ͱ����+1���Ƿ���� 
            if(!limit) break;
        }
    }
    return flow;
}

void dinic(int s,int t) {
    while (bfs(s,t))
        maxflow+=dfs(s,t,inf);
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1; i<=m; i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w,1);
        addedge(v,u,w,0);
    }
    dinic(s,t);
    printf("%d",maxflow);
    return 0;
}

