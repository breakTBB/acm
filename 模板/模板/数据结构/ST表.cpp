#include<iostream>
#include<cstdio>
using namespace std; 
const int maxn=1e5+10;
int n,m;
const int ch_top=4e7;
char ch[ch_top],*now_r=ch-1,*now_w=ch-1;
int mx[maxn][22];
int lg[maxn];
int max(int a,int b){return a>b?a:b;}
inline int query(int l,int r) {
    int k=lg[r-l+1];
    return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int main() {
    lg[0]=-1;for(int i=1;i<maxn;i++)lg[i]=lg[i>>1]+1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&mx[i][0]);
    for(int j=1;j<=22;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    while(m--){int l,r;scanf("%d%d",&l,&r);printf("%d\n",query(l,r));}
}

// #include<iostream>
// using namespace std;
// #define MAXN 100000
// int jump[MAXN][20];
// int a[MAXN];
// int ff[MAXN];

// //  a << b
// //  a >> b
// //
// //  00000000000011
// //  00000000000001
// //  00000000000110
// //  00000000001100

// int main() {
// 	scanf("%d",&n);
// 	for (int i=0;i<n;i++)
// 		scanf("%d",a+i);

// 	memset(ff,-1,sizeof(ff));
// 	for (int i=0;(1<<i)<MAXN;i++)
// 		ff[1<<i] = 1<<i;
// 	for (int i=1;i<MAXN;i++)
// 		if (ff[i] == -1)
// 			ff[i] = ff[i-1];

// 	// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// 	// . . . . . . . . . .  .  .  .  .  .  .  .  .
// 	//   1 2   4       8                     16
// 	// - 1 2 2 4 4 4 4 8 8  8  8  8  8  8  8 16 16
// 	for (int i=0;i<n;i++)
// 		jump[i][0] = a[i];
// 	for (int i=1;i<20;i++)
// 		for (int j=0;j+(1<<i)-1<n;j++)
// 			jump[j][i] = max(jump[j][i-1],jump[j+(1<<(i-1))][i-1]);
// 	//jump[i][0]->[i,i]
// 	//jump[i][j]
// 	//[3,3+2^4-1]
// 	//[3,3+2^3-1] [3+2^3,3+2^4-1]
// 	//
// 	// . . . . . . . . . . q q q q q q q q q q q . . . . . 
// 	// . . . . . . . . . . a a a a a a a a 
// 	// . . . . . . . . . . . . . a a a a a a a a . . . . .
// 	scanf("%d",&m);
// 	for (int i=0;i<m;i++) {
// 		scanf("%d%d",&l,&r);
// 		int len = r-l+1;
// 		int k = ff[len];
// 		int ans = max(jump[l][k],jump[r-(1<<k)+1][r]);
// 		printf("%d\n",ans);
// 	}
// }

// //jump[i][j] 表示区间[i,i+2^j-1]的最大值