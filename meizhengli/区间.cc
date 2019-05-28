#include <bits/stdc++.h>
using namespace std;

const int Max_n = 100005;
typedef long long LL;

struct A
{
    int l, r;
} a[Max_n];

bool operator<(const A &a, const A &b)
{
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + m + 1);
    if (a[1].l > 1)
    {
        printf("-1\n");
        return 0;
    }

    int s=1,e=1,sum=1;
	for(int i=1;i<=m;i++){
		if(a[i].l<=s)//有多个区间与当前区间重合,找到终点最大的区间. 
			e = max(e,a[i].r);
		else{//如果没有此时没有了重合的区间,就去更新当前区间,继续寻找下一个区间. 
			sum++;
			s=e+1;//未更新过的区间的终点 
			if(a[i].l<=s)	e=max(e,a[i].r);//要选择的下一个区间最右边的点. 
			else{
            printf("-1\n");//没有符合条件的就出现了断层
				return 0;
			}
		}
		if(e>=n) break;
	} 
	printf("%d\n",e>=n?sum:-1);
    system("pause");
    return 0;
}