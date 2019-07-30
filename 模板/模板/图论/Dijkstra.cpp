/*洛谷 模板 单源最短路径（标准版）*/
/*nlogn的最短路求法 然而我还加了个fread*/
#include <bits/stdc++.h>
const int maxn=500100;
const int maxm=500100;
const int INF=1<<30;
int en=0,front[maxn];
int n,m,s,t;

struct edge {
    int v,w,next;
} e[maxm*2];

inline void Addedge(int u,int v,int w) {
    en++;
    e[en].v=v;
    e[en].w=w;
    e[en].next=front[u];
    front[u]=en;
}

struct HeapNode {
    int u,d;
    bool operator < ( const HeapNode& rhs ) const {
        return d>rhs.d;
    }
};

void Dijkstra() {
    int d[maxn];
    priority_queue<HeapNode> q;
    memset(d,127,sizeof(d));
    d[s]=0;
    q.push( (HeapNode) {
        s, d[s]
    } );
    while(!q.empty()) {
        HeapNode x=q.top();
        q.pop();
        if(x.d>d[x.u])continue;
        int u=x.u;
        if(x.d != d[u]) continue;
        for(int i=front[u]; i>=0; i=e[i].next) {
            int v=e[i].v,w=e[i].w;
            if(d[u]+w<d[v]) {
                d[v]=d[u]+w;
                q.push((HeapNode) {v, d[v]});
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        out(d[i]);
        pc(' ');
    }

}

int main() {
    int u,v,w;
    memset(front,-1,sizeof(front));
    in(n);
    in(m);
    in(s);
    for(int i=1; i<=m; ++i) {
        in(u);
        in(v);
        in(w);
        Addedge(u,v,w);
    }
    Dijkstra();
    return 0;
}

