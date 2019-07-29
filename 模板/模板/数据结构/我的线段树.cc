//线段树维护区间增加（减少），区间最大值，区间最小值，区间和 

#include<bits/stdc++.h>

//宏命令替换常量和左右儿子标记，以及当前线段树节点表示的[l,r]的mid值 

#define lc (p<<1)
#define rc (p<<1|1)
#define mid (T[p].l+T[p].r>>1)
#define N 100005

using namespace std;

//线段树的储存以及其它变量的复制 
struct Node{int l,r,lz,sum,maxn,minn;}T[N<<2];
int n,m,a[N];

//向上合并 
inline void pushup(int p){
    T[p].sum=T[lc].sum+T[rc].sum;
    T[p].maxn=max(T[lc].maxn,T[rc].maxn);
    T[p].minn=min(T[lc].minn,T[rc].minn);
}

//修改当前节点的信息 
inline void pushnow(int p,int v){
    T[p].sum+=(T[p].r-T[p].l+1)*v;
    T[p].lz+=v,T[p].maxn+=v,T[p].minn+=v;
}

//向下传递标记 
inline void pushdown(int p){
    if(T[p].lz==0)return;
    pushnow(lc,T[p].lz),pushnow(rc,T[p].lz);
    T[p].lz=0;
}

//建树的函数 
inline void build(int p,int l,int r){

//计算当前线段树节点表示的左右端点，并给标记赋初值 
    T[p].l=l,T[p].r=r,T[p].lz=0;

//递归到叶节点初始化 
    if(l==r){T[p].sum=T[p].maxn=T[p].minn=a[l];return;}

//递归建树 
    build(lc,l,mid),build(rc,mid+1,r);
    pushup(p);
}

//区间修改函数 
inline void update(int p,int ql,int qr,int v){
    //不合法情况的剪枝 
    if(T[p].l>qr||T[p].r<ql)return;

    //可以直接修改当前整个区间 
    if(ql<=T[p].l&&T[p].r<=qr){pushnow(p,v);return;}

    //下传标记 
    pushdown(p);

    //递归修改左右儿子 
    if(qr<=mid)update(lc,ql,qr,v);
    else if(ql>mid)update(rc,ql,qr,v);
    else update(lc,ql,mid,v),update(rc,mid+1,qr,v);

    //信息合并 
    pushup(p);
}
inline int query_sum(int p,int ql,int qr){
    //不合法情况的剪枝 
    if(T[p].l>qr||T[p].r<ql)return 0;

    //可以直接返回当前整个区间和 
    if(ql<=T[p].l&&T[p].r<=qr)return T[p].sum;

    //下传标记
    pushdown(p);

    //递归询问左右儿子
    if(qr<=mid)return query_sum(lc,ql,qr);
    if(ql>mid)return query_sum(rc,ql,qr);
    return query_sum(lc,ql,mid)+query_sum(rc,mid+1,qr);
}
inline int query_max(int p,int ql,int qr){
    //不合法情况的剪枝 
    if(T[p].l>qr||T[p].r<ql)return -0x3f3f3f3f;

    //可以直接返回当前整个区间最大值 
    if(ql<=T[p].l&&T[p].r<=qr)return T[p].maxn;

    //下传标记
    pushdown(p);

    //递归询问左右儿子
    if(qr<=mid)return query_max(lc,ql,qr);
    if(ql>mid)return query_max(rc,ql,qr);
    return max(query_max(lc,ql,mid),query_max(rc,mid+1,qr));
}
inline int query_min(int p,int ql,int qr){
    //不合法情况的剪枝 
    if(T[p].l>qr||T[p].r<ql)return 0x3f3f3f3f;

    //可以直接返回当前整个区间最小值 
    if(ql<=T[p].l&&T[p].r<=qr)return T[p].minn;

    //下传标记
    pushdown(p);

    //递归询问左右儿子
    if(qr<=mid)return query_min(lc,ql,qr);
    if(ql>mid)return query_min(rc,ql,qr);
    return min(query_min(lc,ql,mid),query_min(rc,mid+1,qr));
}

int main(){return 0;}