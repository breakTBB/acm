/*洛谷并没有割边模板 可以在https://www.luogu.org/problemnew/show/T31593提交*/
/*经典的tarjan算法用于求割边*/
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1000010,M=1000010;

int n,m;
int tot=1,head[M],head2[M],head3[M],cnt,Index,top;//cnt是强连通分量的个数，index是是搜索次序编号
int DFN[N],LOW[N];
bool is[M*2]; 
bool instack[N];

struct edge {
    int u,v,next,id;
    bool mul;
} G[M*2];

void add_edge(int u,int v,int id) {
    for(int i=head[u];i;i=G[i].next)  
    {  
        if(G[i].v==v)
        {
            G[i].mul=true;  
            return;  
        }  
    }//找重边 
    G[tot].id=id;  
    G[tot].v=v;  
    G[tot].next=head[u];  
    head[u]=tot++;  
  
    G[tot].id=id;  
    G[tot].v=u;  
    G[tot].next=head[v];  
    head[v]=tot++;  
}

void tarjan(int u,int fa) {
    DFN[u]=LOW[u]=++Index;
    for (int i=head[u]; i; i=G[i].next) {
        int v=G[i].v;
        if(!DFN[v]){
            tarjan(v,u);
            LOW[u]=min(LOW[u],LOW[v]);
            if(LOW[v]>DFN[u]&&!G[i].mul)
               is[G[i].id]=1;
        }
        else if(v!=fa)
            LOW[u]=min(LOW[u],DFN[v]);    
    }
}

int main() {
    scanf("%d%d",&n, &m);
    for(int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y,i);
    }
    tarjan(1,1);

    int ans=0;
    for (int i=1; i<=m; i++)
        if(is[i])
            ans++;

    for(int i=1; i<=m; i++)
        if(is[i])
            printf("%d\n",i);
    return 0;
}
