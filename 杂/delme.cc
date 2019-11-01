#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define read(a) scanf("%d", &a)
const int maxn = 5 * 1e5 + 10;
int pre[maxn], nex[maxn], pos[maxn], f[maxn], b[maxn], a[maxn], n, k;
void dele(int p) //更新前驱和后继
{
	if (p == 1)
		pre[nex[p]] = pre[p];
	else if (p == n)
		nex[pre[p]] = nex[p];
	else
	{
		pre[nex[p]] = pre[p];
		nex[pre[p]] = nex[p];
	}
	pre[p] = nex[p] = 0;
}
void work()
{
	//  int n,k;
	memset(f, 0, sizeof(f));
	memset(b, 0, sizeof(b));

	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[a[i]] = i;  //记录a[i]的位置
		pre[i] = i - 1; //记录前驱
		nex[i] = i + 1; //记录后继
	}
	LL ans = 0;
	for (int i = 1; i <= n - k + 1; i++) //本代码的核心所在，因为是1-n的数所以可以是第k大的只可能是1-(n-k+1)这几个数
										 //从1开始找，因为1最小所以它的两边都是比他大的数，找完1之后，在dele()函数里面把1从链表里面拿下来
										 //这样继续找2，因为1不在链表里面了，所以2的两边都是比它大的数，以此类推直到n-k+1
	{
		int fro = 0, beh = 0; //front behind
		int p = pos[i];
		for (int v = p; v && fro <= k; v = pre[v])
			f[fro++] = v;
		for (int v = p; v <= n && beh <= k; v = nex[v])
			b[beh++] = v;
		f[fro] = 0, b[beh] = n + 1;
		for (int j = 0; j < fro && j < k; j++) //fro有可能是k+1,要有j<k限制他，MMP，找了半个多小时，烦躁
		{
			if (k - 1 - j > beh - 1)
				continue;
			{
				int lnum = f[j] - f[j + 1];
				int rnum = b[k - 1 - j + 1] - b[k - 1 - j];
				ans += 1ll * i * lnum * rnum;
			}
		}
		dele(p);
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	read(T);
	while (T--)
	{
		work();
	}
	return 0;
}