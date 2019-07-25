#include <bits/stdc++.h>
#define eps 1e-8
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define lson l,mid,rt<<1
#define rson mid+1,r,(rt<<1)+1
#define CLR(x,y) memset((x),y,sizeof(x))
#define fuck(x) cerr << #x << "=" << x << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int seed = 131;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int lowbit(int x) {
	return x & -x;
}
ll n, t;
ll bit[maxn];
ll a[maxn], b[maxn];
void add(ll i, ll x) {//第i個位置+x
	while (i <= (n + 1)) { //有n+1個前綴和數字
		bit[i] += x;
		i += lowbit(i);
	}
}
ll query(ll x) {
	ll ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	scanf("%lld%lld", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
		b[i] = a[i];
	}
	sort(b, b + 1 + n);//這樣子是爲了存b[0]=0;
	ll cnt = 0;
	int pos;
	for (int i = 1; i <= n; i++) {
		pos = lower_bound(b, b + 1 + n, a[i - 1]) - b + 1;
		//不加1的話從0開始,樹狀數組的下標從1開始
		add(pos, 1);
		pos = upper_bound(b, b + n + 1, a[i] - t ) - b ;//這個也行
		//pos = lower_bound(b, b + n + 1, a[i] - t + 1) - b;
		/*
		因爲是sum[i-1]>sum[j]-t,是大於號
		所以要麼low_bound裏面加1,要麼upper_bound
		*/
		cnt += i - query(pos);
	}
	printf("%lld\n", cnt);
	return 0;
}
