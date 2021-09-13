#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
//#define WIN
#ifdef WIN
typedef __int64 LL;
#define iform "%I64d"
#define oform "%I64d\n"
#define oform1 "%I64d"
#else
typedef long long LL;
#define iform "%lld"
#define oform "%lld\n"
#define oform1 "%lld"
#endif
 
#define S64I(a) scanf(iform, &(a))
#define P64I(a) printf(oform, (a))
#define P64I1(a) printf(oform1, (a))
#define REP(i, n) for(int (i)=0; (i)<n; (i)++)
#define REP1(i, n) for(int (i)=1; (i)<=(n); (i)++)
#define FOR(i, s, t) for(int (i)=(s); (i)<=(t); (i)++)
 
const int INF = 0x3f3f3f3f;
const double eps = 10e-9;
const double PI = (4.0*atan(1.0));
 
const int maxc = 20;
const int maxs = 20;
const int maxk = 100 + 20;
int C, S;
int X[maxc], K[maxc];
int G[maxc][maxk];
int ans[maxs];
int sel[maxc];
vector<LL> sol;
 
void extendedGcd(LL a, LL b, LL & d, LL & x, LL & y) {
}

LL china(int n, int * a, int * m) {
}
 
void dfs(int cur) {
}
 
void solveChina() {
    sol.clear();
    dfs(0);
    sort(sol.begin(), sol.end());
    LL M = 1;
    for(int i=0; i<C; i++) M *= X[i];
    for(int i=0; S; i++) {
        for(int j=0; j<sol.size(); j++) {
            LL n = M * i + sol[j];
            if(n > 0) { P64I(n); if(--S == 0) break; }
        }
    }
}
 
set<int> values[maxc];
void solveEnum(int bc) {
    for(int i=0; i<C; i++) if(i != bc) {
        values[i].clear();
        for(int j=0; j<K[i]; j++) values[i].insert(G[i][j]);
    }
    for(int t = 0; S; t++) {
        for(int i=0; i<K[bc]; i++) {
            LL x = (LL)t * X[bc] + G[bc][i];
            if(!x) continue;
            bool ok = true;
            for(int c=0; c<C; c++) if(c != bc) {
                if(!values[c].count(x%X[c])) { ok = false; break; }
            }
            if(ok) { P64I(x); if(--S == 0) break; }
        }
    }
}
 
int main() {
 
    while(scanf("%d%d", &C, &S) != EOF && C) {
        int totK = 1;
        int tmini = 0;
        for(int i=0; i<C; i++) {
            scanf("%d%d", &X[i], &K[i]);
            totK *= K[i];
            if(K[i] * X[tmini] < X[i] * K[tmini]) tmini = i;
            for(int j=0; j<K[i]; j++) {
                scanf("%d", &G[i][j]);
            }
            sort(G[i], G[i]+K[i]);
        }
        if(totK <= 10000) solveChina();
        else solveEnum(tmini);
        putchar('\n');
    }
 
    return 0;
}