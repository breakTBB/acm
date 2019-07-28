/*洛谷 模板 最近公共祖先*/
/*非常经典的LCA算法*/
#include <cstdio>
#include <algorithm>
#include <cctype>

using namespace std;

const int maxn=500000+10;
int lg2[maxn],dep[maxn],f[maxn][22];
int head[maxn],tot=0;
int n,m,s;
struct Edge{
    int v,next;
}G[maxn*2];
//↓inline是内联标识符，作用是把函数展开到其它函数中，可以优化代码 
inline void add_edge(int u,int v){
    G[++tot].v=v;
    G[tot].next=head[u];
    head[u]=tot;
}//加边 

inline void init(int n) {
    for(int i=1; i<=n; i++)
        lg2[i]=lg2[i-1]+(1<<lg2[i-1]+1==i);//预处理出log2(n)的值
}

void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1; (1<<i)<=dep[u]; i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u]; i; i=G[i].next) {
        int v=G[i].v;
        if(v!=fa)
            dfs(v,u);
    }//预处理所有节点的深度和f 
}

int lca(int x,int y) {
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y]) 
        x=f[x][lg2[dep[x]-dep[y]]];//用倍增的思想向上爬到同一高度 
    if(x==y) return x;//如果在同一高度时在同一个点，显然这个点就是它们的lca，直接返回
    for(int k=lg2[dep[x]];k>=0;k--)
        if(f[x][k]!=f[y][k])
            x=f[x][k],y=f[y][k];//这个倍增相当于一个无限逼近lca的子节点的过程
    return f[x][0];//找到了它们lca的子节点，返回它的父亲qwq 
}

int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    init(n); 
    for(int i=1;i<n;i++)//因为是树，所以n个节点意味着有n条边 
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
} 
