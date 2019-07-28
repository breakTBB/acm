/* 洛谷 模板 树链剖分*/
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define lson (u<<1)
#define rson ((u<<1)+1)

const int maxn=300000;

struct tree{
    int l,r,v,lazy;
}node[2*maxn];

int first[maxn],last[maxn],nxt[maxn],a[maxn],w[maxn],tid[maxn],
    e[maxn],top[maxn],rank[maxn],size[maxn],r[maxn],tt[maxn],father[maxn],
    n,m,k,mod,x,y,g,i,s,tot,z;
    
inline void add(int x,int y) {
    a[++k]=y;
    tt[x]++;
    if(first[x]==0)
        first[x]=k;
    else
        nxt[last[x]]=k;
    last[x]=k;
}//加边 

void down(int u) {
    if(node[u].lazy==0) return;
    node[u].v+=node[u].lazy*(node[u].r-node[u].l+1)%mod;
    node[lson].lazy+=node[u].lazy;
    node[rson].lazy+=node[u].lazy;
    node[u].lazy=0;
}//线段树：下发 

void change(int u,int l,int r,int cont) {
    if(node[u].l>r||node[u].r<l) return;//不是所管辖区间
    if(node[u].l>=l&&node[u].r<=r) {
        node[u].lazy+=cont;
        down(u);
        return ;
    }
    change(lson,l,r,cont);
    change(rson,l,r,cont);
    down(lson);
    down(rson);
    node[u].v=(node[u*2].v+node[u*2+1].v)%mod;
}

void dfs(int u,int fa) {
    int i=0;
    size[u]=1;
    r[u]=r[fa]+1;//r：深度 
    father[u]=fa;
    for(i=first[u];i;i=nxt[i])//对i的每条出边 
        if(a[i]!=fa) {//若该出边连向儿子 
            dfs(a[i],u);
            size[u]+=size[a[i]];//size：子树大小 
        }
}

void dfs2(int u,int head) {
    int i,mson=0;
    top[u]=head;
    tid[u]=++tot;
    rank[tid[u]]=tot;
    change(1,tot,tot,w[u]);
    if(tt[u]==1&&u!=s) {
        e[u]=u;
        return;
    }
    for(i=first[u];i>0;i=nxt[i])
        if(size[a[i]]<size[u]&&size[a[i]]>size[mson])
            mson=a[i];//找重儿子
    dfs2(mson,head);
    e[u]=e[mson];
    for(i=first[u];i>0;i=nxt[i])
        if(size[a[i]]<size[u]&&a[i]!=mson){
            dfs2(a[i],a[i]);
            e[u]=e[a[i]];
        }
}

void build(int u,int l,int r) {
    int mid=(l+r)>>1;
    node[u].l=l;
    node[u].r=r;
    if(l==r) return;
    build(lson,l,mid);
    build(rson,mid+1,r);
}

int query(int u,int l,int r) {
    if(node[u].l>r||node[u].r<l) return 0;
    if(node[u].l>=l&&node[u].r<=r) return (node[u].v)%mod;
    down(lson);
    down(rson);
    return (query(lson,l,r)+query(rson,l,r))%mod;
}

void schange(int x,int y,int cont) {
    while(top[x]!=top[y]) {
        if(r[top[x]]<r[top[y]]) swap(x,y);
        change(1,tid[top[x]],tid[x],cont);
        x=father[top[x]];
    }
    if(tid[x]>tid[y]) swap(x,y);
    change(1,tid[x],tid[y],cont);
}

int squery(int x,int y){
    int ans=0;
    while(top[x]!=top[y]) {
        if(r[top[x]]<r[top[y]]) swap(x,y);
        ans+=query(1,tid[top[x]],tid[x]);
        ans%=mod;
        x=father[top[x]];
    }
    if(tid[x]>tid[y]) swap(x,y);
    ans+=query(1,tid[x],tid[y]);
    ans%=mod;
    return ans;
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&mod);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n-1;i++) {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    build(1,1,n);
    dfs(s,0);
    dfs2(s,s);
    for(int i=1;i<=m;i++) {
        scanf("%d",&g);
        if(g==1) {
            scanf("%d%d%d",&x,&y,&z);
            schange(x,y,z);
        }//将树从x到y结点最短路径上所有节点的值都加上z
        if(g==2) {
            scanf("%d%d",&x,&y);
            printf("%d\n",squery(x,y)%mod);
        }//表示求树从x到y结点最短路径上所有节点的值之和 
        if(g==3) {
            scanf("%d%d",&x,&y);
            change(1,tid[x],tid[e[x]],y);
        }//子树加
        if(g==4){
            scanf("%d",&x);
            printf("%d\n",query(1,tid[x],tid[e[x]])%mod);
        }//子树询问和 
    }
    return 0;
} 
