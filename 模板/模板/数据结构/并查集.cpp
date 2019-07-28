#include<iostream>
using namespace std;
const int N=10000;
int n,m;
int fa[N],size[N];
inline void init()
{
    for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
}
inline int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(size[xx]<size[yy])swap(xx,yy);
    fa[yy]=xx;size[xx]+=size[yy];
}
inline bool both(int x,int y)
{
    if(find(x)==find(y))
        return 1;
    else return 0;
}
int main()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b,tmp;
        cin>>tmp;
        if(tmp==1)
        {
            cin>>a>>b;
            merge(a,b);
        }
        if(tmp==2)
        {
            cin>>a>>b;
            if(both(a,b))
                cout<<'Y'<<endl;
            else cout<<'N'<<endl;
        }
    }
    return 0;
}
