/*
 *容斥原理的计数，有n个条件，n1||n2||n3||...||nn,即求n个条件的并集：
 *sum=满足一个条件的数目-满足两个条件的数目+...+满足奇数个条件的数目-满足偶数个条件的数目
*/
#include <iostream>
using namespace std;
typedef long long ll;
long long n;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        ll a=n/2,b=n/3,c=n/5,d=n/7; //满足一个条件
        ll ab=n/6,ac=n/10,ad=n/14,bc=n/15,bd=n/21,cd=n/35; //满足两个条件
        ll abc=n/30,abd=n/42,acd=n/70,bcd=n/105; //满足三个条件
        ll abcd=n/210; //满足四个条件
        ll ans=(a+b+c+d)-(ab+ac+ad+bc+bd+cd)+(abc+abd+acd+bcd)-(abcd);
        cout<<n-ans<<endl;
    }
    return 0;
}