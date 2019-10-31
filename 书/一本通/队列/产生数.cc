#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
#define gkd ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

using namespace std;

queue<string> q;
map<int, vector<int> > trans;
set<string> st;
int n, k;

string tos(int n) {
    string ret = "";
    while(n) {
        ret = string(1, '0' + (n % 10)) + ret;
        n /= 10;
    }
    return ret;
}

int main() {
    gkd;
    cin >> n >> k;
    rep(i, 1, k) {
        int x, y;
        cin >> x >> y;
        trans[x].push_back(y);
    }
    st.insert(tos(n));
    q.push(tos(n));
    while(q.size()) {
        string now = q.front(); q.pop();
        int sz = now.length();
        for (int i = 0; i < sz; i++) {
            if (trans[now[i] - '0'].size()) {
                int sz = trans[now[i] - '0'].size();
                for (int ii = 0; ii < sz; ii++) {
                    string s = now;
                    s[i] = '0' + trans[now[i] - '0'][ii];
                    if (!st.count(s)) {
                        st.insert(s);
                        q.push(s);
                    }
                }
            }
        }
    }
    cout << st.size() << endl;
}



// #include<cstdio>
// #define MAXN 10001
// #define MAXM 16
// int n,k;
// int exist[MAXN];
// int que[MAXN];
// int a[MAXM],b[MAXM];
// int main(void)
// {
// 	scanf("%d",&n);
// 	scanf("%d",&k);
// 	for (int i=0;i<k;i++)
// 		scanf("%d%d",&a[i],&b[i]);
// 	exist[n]=1;
// 	que[1]=n;
// 	int head=1;
// 	for (int tail=0;head>=tail;)
// 	{
// 		int x=que[++tail];
// 		int y=x,mod=1;
// 		while (x>0)
// 		{
// 			int tmp=x%10;
// 			x/=10;
// 			for (int i=0;i<k;i++)
// 				if (a[i]==tmp)
// 				{
// 					int p=y+(b[i]-tmp)*mod;
// 					if (exist[p]==0)
// 					{
// 						exist[p]=1;
// 						que[++head]=p;
// 					}
// 				}
// 			mod*=10;
// 		}
// 	}
// 	printf("%d\n",head);
// 	return 0;
// }

