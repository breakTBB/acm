/*��� ģ�� �����������*/
/*�ǳ������LCA�㷨*/
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
//��inline��������ʶ���������ǰѺ���չ�������������У������Ż����� 
inline void add_edge(int u,int v){
    G[++tot].v=v;
    G[tot].next=head[u];
    head[u]=tot;
}//�ӱ� 

inline void init(int n) {
    for(int i=1; i<=n; i++)
        lg2[i]=lg2[i-1]+(1<<lg2[i-1]+1==i);//Ԥ�����log2(n)��ֵ
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
    }//Ԥ�������нڵ����Ⱥ�f 
}

int lca(int x,int y) {
    if(dep[x]<dep[y])
        swap(x,y);
    while(dep[x]>dep[y]) 
        x=f[x][lg2[dep[x]-dep[y]]];//�ñ�����˼����������ͬһ�߶� 
    if(x==y) return x;//�����ͬһ�߶�ʱ��ͬһ���㣬��Ȼ�����������ǵ�lca��ֱ�ӷ���
    for(int k=lg2[dep[x]];k>=0;k--)
        if(f[x][k]!=f[y][k])
            x=f[x][k],y=f[y][k];//��������൱��һ�����ޱƽ�lca���ӽڵ�Ĺ���
    return f[x][0];//�ҵ�������lca���ӽڵ㣬�������ĸ���qwq 
}

int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    init(n); 
    for(int i=1;i<n;i++)//��Ϊ����������n���ڵ���ζ����n���� 
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
