/*洛谷 模板 最小生成树*/
/*最大众的最小生成树算法*/
#include<iostream>
#include<algorithm>
using namespace std;
int fa[200005],size[200005];
struct edge
{
    int x,y,v;
}a[200005];
void init(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
inline int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(size[xx]<size[yy])swap(xx,yy);
    fa[yy]=xx;size[xx]+=size[yy];
}
bool both(int x,int y)
{
    if(find(x)==find(y))
        return 1;
    else return 0;
}
bool cmp(edge a,edge b)
{
    return a.v<b.v;
}
int main()
{
    int sum=0;
    int n,m;
    cin>>n>>m;
    init(m);
    for(int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y>>a[i].v;
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(!both(a[i].x,a[i].y))
        {
            merge(a[i].x,a[i].y);
            sum+=a[i].v;
        }
        else continue;
    }
    cout<<sum;
}


