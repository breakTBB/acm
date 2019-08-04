#include<bits/stdc++.h>
using namespace std;
int n;
string s[100011];
void init(){
    scanf("%d",&n);
    unordered_set<string> st;
    for (int i=1;i<=n;++i){
        static char ch[100];
        scanf("%s",ch);
        s[i]=ch;
        if (st.find(s[i])!=st.end())
            --i,--n;
        else st.insert(s[i]);
    }
    sort(s+1,s+n+1);
    n=unique(s+1,s+n+1)-s-1;
    shuffle(s+1,s+n+1,mt19937(19260817));
}
int A[100],used[100];
bool check(){
    for (int i=1;i<=n;++i){
        int y=0,m=0,d=0;
        for (int j=0;j<4;++j)
            y=y*10+A[s[i][j]-'A'];
        for (int j=5;j<7;++j)
            m=m*10+A[s[i][j]-'A'];
        for (int j=8;j<10;++j)
            d=d*10+A[s[i][j]-'A'];         
//      cerr<<y<<' '<<m<<' '<<d<<endl;
        if (y<1600) return false;
        if (m>12) return false;
        if (d>31) return false;
        if ((m==4 || m==6 || m==9 || m==11) && d==31) return false;
        if (m==2 && d>28+(y%4==0 && (y%100!=0 || y%400==0))) return false;
        if (m<3) --y,m+=12;
        if ((365*y+y/4-y/100+y/400+(153*(m-3)+2)/5+d-307+1)%7!=5) return false;
    }
    return true;
}
bool solved;
void DFS(int dep){
    if (solved) return;
    if (dep==10){
        if (check()){
            solved=1;
            for (int i=0;i<10;++i) printf("%d",A[i]);
            puts("");
        }
        return;
    }
    for (int i=0;i<10;++i) if (!used[i]){
        used[i]=1;
        A[dep]=i;
        DFS(dep+1);
        used[i]=0;
    }
}
void work(){
    solved=0;
    DFS(0);
    if (!solved) puts("Impossible");
}
int main(){
    int T; scanf("%d",&T);
    for (int i=1;i<=T;++i){
        init();
        printf("Case #%d: ",i);
        work();
    }
    return 0;
}