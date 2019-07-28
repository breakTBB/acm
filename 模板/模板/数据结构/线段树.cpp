/*Âå¹È Ä£°å Ïß¶ÎÊ÷1*/

#include<cstdio>
#include<iostream>
#include<algorithm>

#define lson (o<<1)
#define rson (o<<1|1)

using namespace std;


const int MAX=110000;
long long sumv[500000], add[500000];

void pushup(int o){
    sumv[o]=sumv[lson]+sumv[rson];
}

void pushdown(int o,int l,int r){
    int k=(l+r)>>1;
    if(!add[o]) return;
    add[lson]+=add[o];
    add[rson]+=add[o];
    sumv[lson]+=add[o]*(k-l+1);
    sumv[rson]+=add[o]*(r-k);
    add[o]=0;
}

void build(int o,int l,int r){
    add[o]=0;
    if(l==r){
        scanf("%lld",&sumv[o]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    pushup(o);
}

void optadd(int o,int l,int r,int ql,int qr,int v){
    if(ql<=l&&qr>=r){
        add[o]+=v;
        sumv[o]+=v*(r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    pushdown(o,l,r);
    if(ql<=mid) optadd(lson,l,mid,ql,qr,v);
    if(qr>mid)  optadd(rson,mid+1,r,ql,qr,v);
    pushup(o);
}

long long que(int o,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return sumv[o];
    pushdown(o,l,r);
    int mid=(l+r)>>1;
    long long ans=0;
    pushup(o);
    if(ql<=mid) ans+=que(lson,l,mid,ql,qr);
    if(qr>mid)  ans+=que(rson,mid+1,r,ql,qr);
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int L,R,C,Q;
        scanf("%d",&Q);
        if(Q==1){
            scanf("%d%d%d",&L,&R,&C);
            optadd(1,1,n,L,R,C);
        }
        else if(Q==2){
            scanf("%d%d",&L,&R);
            printf("%lld\n",que(1,1,n,L,R));
        }
    }
    return 0;
}
