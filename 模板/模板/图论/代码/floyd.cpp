#include <bits/stdc++.h>
#define MAXN 305
using namespace std;
int n;
int a[MAXN][MAXN];
void print()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			printf("%d%c",a[i][j],j==n?'\n':' ');
	putchar('\n');
}
int main()
{
	memset(a,-1,sizeof(a));
	printf("%d",a[2][2]);
	scanf("%d",&n);
	
	for (int i=1;i<=n;i++)
		a[i][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	//��ʼʱ�洢���Ǵ�i��j��ֱ�����ߵı�Ȩ 
	for (int k=1;k<=n;k++)//kΪ����ѭ����Ҫ����ĵ� 
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
	//��ʱa[i][j]��ʾ��i��j����̾��� 
	print();
}
