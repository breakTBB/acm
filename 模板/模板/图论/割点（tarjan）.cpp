/*洛谷 模板 割点（割顶）*/
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1000010,M=1000010;

int n,m;
int tot=0,head[M],head2[M],head3[M],cnt,Index,top;//cnt是强连通分量的个数，index是是搜索次序编号
int DFN[N],LOW[N];
bool is[N]; 
bool instack[N];

struct edge {
    int u,v,next;
} G[M];

void add_edge(int u,int v) {
    G[++tot].u=u;
    G[tot].v=v;
    G[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u,int fa) {
    int son=0;
    DFN[u]=LOW[u]=++Index;
    for (int i=head[u]; i; i=G[i].next) {
        int v=G[i].v;
        if(!DFN[v]) { //v未被搜索
            tarjan(v,fa);
            LOW[u]=min(LOW[u],LOW[v]);//定义
            if(u==fa) son++;
            else if(LOW[v]>=DFN[u]) is[u]=1;
        }
        LOW[u]=min(LOW[u],DFN[v]);
    }
    if(son>=2) is[u]=1;
}

int main() {
    scanf("%d%d",&n, &m);
    for(int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(y,x);
        add_edge(x,y);
    }

    for(int i=1; i<=n; i++)
        if(!DFN[i])
            tarjan(i,i);

    int ans=0;
    for (int i=1; i<=n; i++)
        if(is[i])
            ans++;
    printf("%d\n",ans);
    for(int i=1; i<=n; i++)
        if(is[i])
            printf("%d ",i);
    return 0;
}
