#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long b[10000],n,k,tot,sum,a[1000],c[1000];
bool check(int y)
{
    if(y == 1) return false;
    for(int i = 2;i <= sqrt(y);i ++)
    if(y % i == 0) return false;
    return true;
}

//X��ѡ�����ĸ���
//Y��
//J��ǰ���±�
void dfs(int x,int y,int j)
{
    cout<<"��ѡ"<<x<<"����"<<"��Ϊ"<<y<<"��ǰ��"<<j<<"����"<<"\n";
    if(x == k)
    {
        if(check(y)) tot++;
        return ;
    }
    for(int i = j+1;i <= n;i ++)
    dfs(x + 1,y + a[i],i);
    return;
}
int main()
{
    //N������ѡK����
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i ++)
        scanf("%d",&a[i]);
    dfs(0,0,0);
    printf("%d",tot);
    system("pause");
    return 0;
}