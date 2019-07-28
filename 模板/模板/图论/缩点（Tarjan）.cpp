/*洛谷 2341 受欢迎的牛*/
/*因为luogu的缩点模板题带了个DP，这题反而更裸一点*/
/*经典的tarjan 算法*/
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=10010,M=50010;

int n,m;
int tot=0,tot2=0,head[M],head2[M],Bcnt,Dindex,Stop;
int nn[N];
int DFN[N],LOW[N],Stap[N],Belong[N];
bool flag[N][N];
bool instack[N];

struct edge {
    int u,v,next;
} G[M],G2[M];

void add_edge(int u,int v) {
    G[++tot].u=u;
    G[tot].v=v;
    G[tot].next=head[u];
    head[u]=tot;
}

void xadd_edge(int u,int v) {
    G[++tot2].u=u;
    G2[tot2].v=v;
    G2[tot2].next=head2[u];
    head2[u]=tot2;
}

void tarjan(int i)
{
    int j;
    DFN[i]=LOW[i]=++Dindex;
    instack[i]=true;
    Stap[++Stop]=i;
    for (int e=head[i];e;e=G[e].next)
    {
        j=G[e].v;
        if (!DFN[j])
        {
            tarjan(j);
            LOW[i]=min(LOW[i],LOW[j]);
        }
        else if(!Belong[j]) {
            LOW[i]=min(LOW[i],LOW[j]);
        }
    }
    int x;
    if (DFN[i]==LOW[i])
    {
        Bcnt++;
        do
        {
            x=Stap[Stop--];
            instack[x]=false;
            Belong[x]=Bcnt;
            nn[Bcnt]++;
        }while (x!=i);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    for(int i=1; i<=n; i++) {
        if(!DFN[i])
            tarjan(i);
    }
    for(int i=1; i<=n; i++) {
        for(int j=head[i]; j; j=G[j].next) {
            if(Belong[i]!=Belong[G[j].v]&&!flag[Belong[i]][Belong[G[j].v]]) {
                xadd_edge(Belong[i],Belong[G[j].v]);
                flag[Belong[i]][Belong[G[j].v]]=1;
            }
        }
    }
    int num=0,ans=0;
    for(int i=1; i<=Bcnt; i++) {
        if(!head2[i]) { 
        	num++;
        	ans=i;
        }
    }
    if(num==1) {
        printf("%d\n",nn[ans]);
        return 0;
    }
    printf("0\n");
}
