/*
	Author : Enstein_Jun
	Language : C++
	Problem : POJ3255
	BlogUrl : https://blog.csdn.net/luomingjun12315/article/details/51284224
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN (5000 + 10)
#define INF (5000*5000*2)
using namespace std;
 
struct edge{
    int to, cost;
    edge(int tv = 0, int tc = 0):
        to(tv), cost(tc){}
};
typedef pair<int ,int> P;
int N, R;
vector<edge> graph[MAXN];
int dist[MAXN];     //��̾���
int dist2[MAXN];    //�ζ̾���

void solve(){
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    //��С��������ȶ���
    //ʹ��pair������edge�ṹ��
    //����Ϊ�������ǲ���Ҫ���������
    //pair����firstΪ���ؼ��ֽ�������
    priority_queue<P, vector<P>, greater<P> > Q;
    //��ʼ��Դ����Ϣ
    dist[0] = 0;
    Q.push(P(0, 0));
    //ͬʱ������·�ʹζ�·
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        //firstΪs->to�ľ��룬secondΪedge�ṹ���to
        int v = p.second, d = p.first;
        //��ȡ����ֵ���ǵ�ǰ��̾����ζ̾��룬��������
        if(dist2[v] < d) continue;
        for(unsigned i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            int d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N-1]);
}
 
int main(){
    int A, B, D;
    scanf("%d%d", &N, &R);
    for(int i = 0; i < R; i++){
        scanf("%d%d%d", &A, &B, &D);
        graph[A-1].push_back(edge(B-1, D));
     //   graph[B-1].push_back(edge(A-1, D));
    }
    solve();
    return 0;
}

