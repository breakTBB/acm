#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

typedef long long ll;
typedef std::pair<ll,ll> pll;
const ll INF=1ll<<58;

const ll MAXN=10011,MAXE=ll(1e9+1);
struct Segment_Tree
{
private:
    ll cnt;
    struct node
    {
        ll v,numl,numr;
        node(ll _v=0)
        {
            numl=numr=0;
            v=_v;
        }
    }t[MAXN*40+1];

#define tl t[rt.numl]
#define tr t[rt.numr]
    void pushup(node& rt)
    {
        rt.v=tl.v+tr.v;
    }
    void modify(ll p,ll val,node& rt,ll l=-MAXE,ll r=MAXE)
    {
        if(l==r)
        {
            if(l==p)rt.v+=val;
            return;
        }
        ll mid=(l+r)>>1;
        if(p<=mid)
        {
            if(!rt.numl)rt.numl=++cnt;
            modify(p,val,tl,l,mid);
        }
        else
        {
            if(!rt.numr)rt.numr=++cnt;
            modify(p,val,tr,mid+1,r);
        }
        pushup(rt);
    }
    ll Qkth(ll k,node& rt,ll l=-MAXE,ll r=MAXE)
    {
        if(l==r)
            return l;
        ll mid=(l+r)>>1;
        if(tl.v>=k)return Qkth(k,tl,l,mid);
        else return Qkth(k-tl.v,tr,mid+1,r);
    }

public:
    void build()
    {
        cnt=1;
        memset(t,0,sizeof t);
    }
    void modify(ll p,ll val)
    {
        modify(p,val,t[1]);
    }
    ll Qkth(ll k)
    {
        return Qkth(k,t[1]);
    }
}sgt;
int main()
{
    ll T=read();
    for(ll w=1;w<=T;++w)
    {
        sgt.build();
        ll num=read(),n=read(),tot=0;
        printf("%lld %lld\n",num,(n+1)>>1);
        for(ll i=1;i<=n;++i)
        {
            ll val=read();
            sgt.modify(val,1);
            if(i&1)
            {
                printf("%lld ",sgt.Qkth((i+1)>>1));
                ++tot;
                if(tot==10)tot=0,putchar('\n');
            }
        }
        if(tot)putchar('\n');
    }
    return 0;
}