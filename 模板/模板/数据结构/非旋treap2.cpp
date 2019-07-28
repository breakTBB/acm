/*洛谷 模板 普通平衡树*/
/*用来实现普通平衡树的非旋treap 常数比treap大，但是仍然比splay优*/
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=500010;

int n,m,x,y,z,tot,opt;

struct fhq_treap{
    int rnd[maxn],sum[maxn],size[maxn],ls[maxn],rs[maxn],root,tmp;
    
    inline void build(int &x,int delta){
        rnd[x=++tot]=rand()<<15|rand();
        sum[x]=delta;
        size[x]=1;
    }
    
    inline void up(int x){
        if(!x) return ;
        size[x]=size[ls[x]]+size[rs[x]]+1;
    }
    
    void merge(int &x,int l,int r){
        if(!l||!r) x=l+r;
        else if(rnd[l]<rnd[r]) x=l,merge(rs[x],rs[x],r),up(x);
        else x=r,merge(ls[x],l,ls[x]),up(x);
    }
    
    void split(int x,int &l,int &r,int k){
        if(!k) l=0,r=x;
        else if(k==size[x]) l=x,r=0;
        else if(k<=size[ls[x]]) r=x,split(ls[x],l,ls[x],k),up(x);
        else                    l=x,split(rs[x],rs[x],r,k-size[ls[x]]-1),up(x);
    }
    
    int rank(int x,int w){
        if(!x) return 0;
        if(sum[x]>=w) return rank(ls[x],w);
        return rank(rs[x],w)+size[ls[x]]+1;
    }
    
    inline void insert(int delta){
        int x,y,rk=rank(root,delta);
        split(root,x,y,rk);
        build(tmp,delta);
        merge(x,x,tmp);
        merge(root,x,y);
    }
    
    inline void del(int delta){
        int x,y,z,rk=rank(root,delta)+1;
        split(root,x,y,rk);
        split(x,x,z,rk-1);
        merge(root,x,y);
    }
    
    inline int find(int delta)
    {
        int x,y,z,ans;
        split(root,x,y,delta);
        split(x,z,x,delta-1);
        ans=sum[x];
        merge(x,z,x);
        merge(root,x,y);
        return ans;
    }
    
    inline int pre(int delta){
        int x,y,z,ans,rk=rank(root,delta);
        split(root,x,y,rk);
        split(x,z,x,rk-1);
        ans=sum[x];
        merge(x,z,x);
        merge(root,x,y);
        return ans;
    }
    
    inline int sub(int delta){
        int x,y,z,ans,rk=rank(root,delta+1);
        split(root,x,y,rk+1);
        split(x,z,x,rk);
        ans=sum[x];
        merge(x,z,x);
        merge(root,x,y);
        return ans;
    }
}T;

int main()
{
    srand(2009);
    scanf("%d",&n);
    T.rnd[0]=T.sum[0]=(1<<30);
    while(n--){
        int opt;
        scanf("%d%d",&opt,&x);
        if(opt==1) T.insert(x);
        else if(opt==2) T.del(x);
        else if(opt==3)printf("%d\n",T.rank(T.root,x)+1);
        else if(opt==4)printf("%d\n",T.find(x));
        else if(opt==5)printf("%d\n",T.pre(x));
        else printf("%d\n", T.sub(x));
    }
} 
