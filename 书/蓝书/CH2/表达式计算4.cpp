#define POJ
#define DEBUG

#ifdef POJ
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#else
#include <bits/stdc++.h>
#endif // POJ

#ifdef _DEBUG
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define dbg(x)
#endif // _DEBUG

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define hi puts("hi!");
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIN freopen("C:\\Users\\prism\\Desktop\\interval0.in", "r", stdin);
#define FOUT freopen("C:\\Users\\prism\\Desktop\\out.txt", "w", stdout);
#define STINIT(st) while(st.size()) st.pop();
#define lc (id << 1)
#define rc (id << 1 | 1)
#define mid (t[id].l + t[id].r >> 1)
inline int inc(int x, int v, int mod) { x += v; return x >= mod ? x - mod : x; }
inline int dec(int x, int v, int mod) { x -= v; return x < 0 ? x + mod : x; }
const int inf = 0x3f3f3f3f;
int _, __, ___;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template<typename T> inline void read(T& ret) {
    ret = 0; T f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
    ret *= f;
}
template <typename T, typename... Args> inline void reads(T& t, Args& ... args) {
    redi(t); redi(args...);
}
ll read() {
    ll ret = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar(); }
    return ret * f;
}

vector<int> num;
vector<char> op;

int level(char ch) {
    if (ch == ')' || ch == '(') return 1;
    if (ch == '^') return 2;
    if (ch == '*' || ch == '/') return 3;
    return 4;
}

int main() {
    string str; cin >> str;
    int n = str.length();
    int f = 0, num = 0;
    char ch;
    for (int i = 0; i < n; i++) {
        ch = str[i];
        if (c)
    }
}