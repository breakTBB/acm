// 思考每次要查询，这个数据是怎么变的？每次被覆盖到的操作的次数的奇偶
// 然后发现和校门外的树一样的

// 再抽象一点 所有的区间操作全想在差分的维度上去思考
// 所以这题一个Bit维护差分序列就行 不用两个

#include <bits/stdc++.h>

using namespace std;

struct BitTree {
	static const int N = 1e5 + 10;
	int bit[N];
	BitTree() {
		memset(bit, 0, sizeof bit);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x) {
		for (int i = x; i <= N; i += lowbit(i)) bit[i] += 1;
	}
	int ask(int x) {
		int ret = 0;
		for (int i = x; i >= 1; i -= lowbit(i)) ret += bit[i];
		return ret;
	}

};


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	BitTree left, right;
	int op, l, r;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			left.add(l), right.add(r);
		}
		else {
			scanf("%d", &l);
			r = l;
			printf("%d\n", (left.ask(r) - right.ask(l - 1)) % 2 == 0 ? 0 : 1);
		}
	}
}



// 简化版
#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 100010
using namespace std;
int n,m,val[MAXN];
inline int read(){
    int date=0,w=1;char c=0;
    while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
    while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
    return date*w;
}
inline int lowbit(int x){return x&(-x);}
inline void update(int x){for(;x<=n;x+=lowbit(x))val[x]^=1;}
inline int query(int x){int s=0;for(;x;x-=lowbit(x))s^=val[x];return s;}
void work(){
    int f,x,y;
    n=read();m=read();
    while(m--){
        f=read();x=read();
        if(f==1){
            y=read();
            update(x);update(y+1);
        }
        else printf("%d\n",query(x));
    }
}
int main(){
    work();
    return 0;
}