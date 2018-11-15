#include <bits/stdc++.h>

using namespace std;

int N, M;
const int maxn = 100010;
int F[maxn];

struct node {
    int x;
    int y;
    int time;
}Node[maxn];

int init() {
    for(int i = 0; i < maxn; i++)
        F[i] = i;
}

int findx(int x) {
    int son = x;
    // F[i] == i的才是BOSS
    while(F[x] != x) {
        x = F[x];
    }
    while(son != x) {
        int tmp = F[son];
        F[son] = x;
        son = tmp;
    }
    return x;
}

void unionx(int x, int y) {
    int fx = findx(x);
    int fy = findx(y);
    if (fx != fy) {
        F[fx] = fy;
    }
}

bool con() {
    int tmp = findx(1);
    for(int i = 1; i <= N; i++) {
        if(findx(i) != tmp) return false;
    }
    return true;
}

int main() {
    init();
    bool flag = false;
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> Node[i].x >> Node[i].y >> Node[i].time;
    }
    sort(Node+1, Node+M+1,[](node a, node b) { return a.time < b.time; });
    for(int i = 1; i <= M; i++) {
        unionx(Node[i].x, Node[i].y);
        if (con()) {
            cout << Node[i].time;
            // return 0;
            flag = true;
            break;
        }
    }
    if(!flag) cout << "-1";
    system("pause");
}