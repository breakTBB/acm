/* 洛谷 模板 树状数组*/ 
#include<cstdio>
using namespace std;
int a[500010],t[500010];
int n,m;
int SUM(int x)//返回前x个元素和
{
    int s=0;
    while(x>0)
    {
        s+=t[x];
        x-=x&(-x);
    }
    return s;
}
int Sum(int l,int r)
{
    return SUM(r)-SUM(l-1);
}
void update(int x,int num)
{
    while(x<=n)
    {
        t[x]+=num;
        x+=x&(-x);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        update(i,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int cz;
        int l,r;
        scanf("%d%d%d",&cz,&l,&r);
        if(cz==1)update(l,r);
        if(cz==2)printf("%d\n",Sum(l,r));
    }
    return 0;
}
