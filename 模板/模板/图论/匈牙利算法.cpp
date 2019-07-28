/*洛谷 模板 二分图匹配*/
/*经典的二分图匹配算法*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N=10005;
const int M=500005;
int tot,head[N];
int num_nodes;
int num_left;
int num_right;
int num_edges;
int matching_Left[N],matching_Right[N];
bool check[M];

struct Edge{
    int u,v,next;
}G[M];

inline void addedge(int u,int v){
    G[++tot].u=u;
    G[tot].v=v;
    G[tot].next=head[u];
    head[u]=tot;
}

bool dfs(int u){
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].v;
        if(!check[v]){
            check[v]=true;
            if(matching_Left[v]==-1||dfs(matching_Left[v])){
                matching_Left[v]=u;
                matching_Right[u]=v;
                return 1;
            }
        }
    }
    return 0;
}

int hungarian(){
    int ans=0;
    memset(matching_Left,-1,sizeof(matching_Left));
    memset(matching_Right,-1,sizeof(matching_Right));
    for(int u=1;u<=num_left;++u){
        memset(check,0,sizeof(check));
        if(dfs(u))
            ans++;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d",&num_left,&num_right,&num_edges);
    num_nodes=num_left+num_right;
    for(int i=1;i<=num_edges;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>num_left) continue;
        if(v>num_right) continue;
        addedge(u,v);
    }
    printf("%d",hungarian());
    return 0; 
}

