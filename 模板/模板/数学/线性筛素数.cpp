/*洛谷 模板 线性筛素数*/
/*非常入门的素数算法*/
#include<iostream>
#include<cmath>
using namespace std;
bool flag[10000000];
int main()
{
    int n,m,a;
    cin>>n>>m;;
    flag[1]=1;
    flag[0]=1;
    for(int i=2;i<=sqrt(n)+1;i++)//制作素数表
    {
        if(flag[i]==0)//如果flag[i]没有被任何数筛掉过
        {
            for(int j=i*2;j<=n;j+=i)
                flag[j]=1;//将每个i的倍数设为合数 筛掉所有以i为因数的合数 
        } 
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        if(flag[a])
            cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
