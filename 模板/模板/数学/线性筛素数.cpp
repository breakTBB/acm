/*��� ģ�� ����ɸ����*/
/*�ǳ����ŵ������㷨*/
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
    for(int i=2;i<=sqrt(n)+1;i++)//����������
    {
        if(flag[i]==0)//���flag[i]û�б��κ���ɸ����
        {
            for(int j=i*2;j<=n;j+=i)
                flag[j]=1;//��ÿ��i�ı�����Ϊ���� ɸ��������iΪ�����ĺ��� 
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
