/*洛谷 模板 单源最短路径（标准版）*/
/*nlogn的最短路求法 然而我还加了个fread*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
/*---------------------------------------*/
#define ll int
namespace fib {
    char b[300000]= {},*f=b;
}
#define gc ((*fib::f)?(*(fib ::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
inline void in(ll &x) {
    x=0;
    char c;
    bool f=0;
    while((c=gc)>'9'||c<'0')if(c=='-')f=!f;
    x=c-48;
    while((c=gc)<='9'&&c>='0')x=x*10+c-48;
    if(f)x=-x;
}
namespace fob {
    char b[300000]= {},*f=b,*g=b+300000-2;
}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce {
    ~foce() {
        pob;
        fflush(stdout);
    }
} _foce;
namespace ib {
    char b[100];
}
inline void out(ll x) {
    if(x==0) {
        pc(48);
        return;
    }
    if(x<0) {
        pc('-');
        x=-x;
    }
    char *s=ib::b;
    while(x) *(++s)=x%10,x/=10;
    while(s!=ib::b) pc((*(s--))+48);
}
inline void outn(ll x) {
    out(x);
    pc('\n');
}
inline void swap(ll &x,ll &y) {
    ll t=x;
    x=y;
    y=t;
}
inline ll jdz(ll x) {
    return x>0?x:-x;
}
inline ll max(ll x,ll y) {
    return x>y?x:y;
}
inline ll min(ll x,ll y) {
    return x<y?x:y;
}
/*------------------------------------------------------------------------------------------------*/

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

