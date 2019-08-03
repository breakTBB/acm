// https://vijos.org/p/1597
// 极度不正经的打表

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define hi puts("hi");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\in.txt", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
	ret = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = 0; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	ret = f ? ret : -ret;
}
inline int read() {
	int ret = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
	return ret;
}
template<typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar((x % 10) ^ 48);
}

char str[][100] = { "0", "2(0)","2", "2+2(0)", "2(2)", "2(2)+2(0)", "2(2)+2", "2(2)+2+2(0)", "2(2+2(0))", "2(2+2(0))+2(0)", "2(2+2(0))+2", "2(2+2(0))+2+2(0)", "2(2+2(0))+2(2)", "2(2+2(0))+2(2)+2(0)", "2(2+2(0))+2(2)+2", "2(2+2(0))+2(2)+2+2(0)" };
char b[20];

int main() {
	int n;
	char s[10];
	scanf("%s", s);
	n = atoi(s);
	int idx = 0;
	while (n) {
		if (n & 1) b[idx] = '1';
		else b[idx] = '0';
		idx++;
		n >>= 1;
	}
	int first = 0;
	for (int i = idx - 1; i >= 0; i--) {
		if (b[i] == '1') {
			if (first) putchar('+');
			first = 1;
			if (i == 1) printf("2");
			else printf("2(%s)", str[i]);
		}
	}
}


// #include<iostream>
// #include<cstdio>
// using namespace std;
// void mici(int n){
//     if(n==1) return;                    //递归终止条件 
//     if(n==0) { printf("0"); return ; }    //递归终止条件 
//     for(int i=16, mask=0x00008000, first=1; i>=1; i--){
//         if(mask&n){                        //位运算进行分解 
//             if(!first) printf("+");        //第一次不输出加号 
//             printf("2");
//             if(i!=2) printf("(");        //2^1时不需要括号 
//             mici(i-1);                    //递归幂次 
//             if(i!=2) printf(")");        //2^1时不需要括号
//             if(first) first=0;            //控制加号的变量 
//         }
//         mask>>=1;                        //掩码右移一位 
//     }
// }
// int main(){
//     int n;
//     scanf("%d", &n);
//     mici(n);
//     return 0;
// }