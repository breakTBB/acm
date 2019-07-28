/*洛谷 模板 文艺平衡树*/
/*编者注：这东西比splay常数小了一堆*/ 
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn=500010;

int n,m,x,y,z,tot,opt;

inline void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}

struct fhq_treap{
    int rnd[maxn],sum[maxn],size[maxn],ls[maxn],rs[maxn],root,tmp;
    bool rev[maxn];
    
    inline void change(int x){
    	rev[x]^=1;
    	swap(ls[x],rs[x]);
    }
    
    inline void down(int x)
    {
    	if(!x) return;
    	if(rev[x]) change(ls[x]),change(rs[x]);
    	rev[x]=0;
    }
    
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
        else if(rnd[l]<rnd[r]) down(x=l),merge(rs[x],rs[x],r),up(x);
        else down(x=r),merge(ls[x],l,ls[x]),up(x);
    }
    
    void split(int x,int &l,int &r,int k){
        if(!k) l=0,r=x;
        else if(k==size[x]) l=x,r=0;
        else if(k<=size[ls[x]]) down(r=x),split(ls[x],l,ls[x],k),up(x);
        else                    down(l=x),split(rs[x],rs[x],r,k-size[ls[x]]-1),up(x);
    }
    
    inline void insert(int pos,int delta)
    {
    	int x,y;
    	split(root,x,y,pos);
    	merge(x,x,delta);
        merge(root,x,y);
    }
    
    inline void del(int pos,int delta){
        int x,y,z;
        split(root,x,y,pos);
        split(x,x,z,pos-1);
        merge(root,x,y);
    }
    
    inline void reverse(int l, int r)
    {
    	int x,y,z;
    	split(root,x,y,r);
        split(x,z,x,l-1);
    	change(x);
   	 	merge(x,z,x);
        merge(root,x,y);
    }
    
    void getans(int num){
        int x,y,z;
        split(root,x,y,num);
        split(x,z,x,num-1);
        printf("%d ",sum[x]);
        merge(x,z,x);
        merge(root,x,y);
    }
}T;

int main()
{
    srand(2009);
    read(n);
    read(m);
    T.rnd[0]=T.sum[0]=(1<<30);
    for(int i=1;i<=n;i++){
    	int tmp;
        T.build(tmp,i);
        T.merge(T.root,T.root,tmp);
    }
    while(m--){
        read(x);
        read(y);
        T.reverse(x,y);
    }
    for(int i=1;i<=n;i++){
    	T.getans(i);
    }
    return 0;
}
