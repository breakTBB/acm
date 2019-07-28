/*洛谷 模板 快速幂*/
/*非常入门的算法*/
#include<iostream>
using namespace std;
long long int x,p,m,i,result;
int main()
{
    cin>>x>>p>>m;
    long long int tmp1=x,tmp2=p,tmp3=m;
    result=1;
    while(p>0)
    {
        if(p%2==1)
            result=(x*result)%m;
        p/=2;
        x=(x*x)%m;
    }
    cout<<tmp1<<'^'<<tmp2<<" mod "<<tmp3<<'='<<result%tmp3;
}
