/*洛谷 AC自动机（简单版）*/
/*经典的一对多字符串匹配算法*/
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=1000010;
int cnt=0;;
int vis[maxn][26];
int val[maxn],fail[maxn];
char s[maxn];

void insert(char *s){
    int len=strlen(s);int now=0;
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!vis[now][v])vis[now][v]=++cnt;
        now=vis[now][v];
    }
    val[now]++;
}
inline void getfail()
{
    queue<int> q;
    for(int i=0;i<26;i++){
        if(vis[0][i])fail[vis[0][i]]=0,q.push(vis[0][i]);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(vis[u][i]){
                fail[vis[u][i]]=vis[fail[u]][i];
                q.push(vis[u][i]);
            }
            else vis[u][i]=vis[fail[u]][i];
        }
    }
}

int query(char s[]){
    int n=strlen(s),ans=0;
    int now=0;
    for(int i=0;i<n;i++){
        now=vis[now][s[i]-'a'];
        for(int p=now;p&&~val[p];p=fail[p]){
            ans+=val[p];
            val[p]=-1;
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        scanf(" %s ",s);
        insert(s);
    }
    getfail();
    scanf("%s",s);
    printf("%d",query(s));
    return 0;
}
