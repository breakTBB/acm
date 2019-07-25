#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define LL long long
int dp[20000005];
int main()
{
	int n;
	int num[22];
	int k;
	int sum = 0;
	scanf ("%d %d",&n,&k);
	for (int i = 1 ; i <= n ; i++)
	{
		scanf ("%d",&num[i]);
		sum += num[i];
	}
	if (sum < k)
		printf ("No\n");
	else if (sum == k)
		printf ("Yes\n");
	else
	{
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = k ; j >= num[i] ; j--)
				dp[j] = max(dp[j] , dp[j-num[i]] + num[i]);
		}
		if (dp[k] == k)
			printf ("Yes\n");
		else
			printf ("No\n");
	}
	return 0;
}

//  深度优先搜索解法

#include <iostream>
#include <cstdio>

const int MAXN = 22;

int N, K;
int A[MAXN];


// 从a[dep]开始搜索， 剩K
bool dfs(int rest, int dep)
{
    // 搜索完毕
    if (dep == N)
    {
        return false;
    }
    // 这个数加上之前的数能组成K
    if (rest == A[dep])
    {
        return true;
    }
    // 这个数比需要的数小
    if (rest > A[dep])
    {
        rest -= A[dep];
        // 加到和中去 继续搜索
        if (dfs(rest, dep + 1))
        {
            return true;
        }
        rest += A[dep];
    }
    return dfs(rest, dep + 1);
}

int main1()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
    }

    if (dfs(K, 0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

