#include <bits/stdc++.h>

using namespace std;

typedef struct{
    char name[10];
    char time[10];
}u;
u user[100010];

bool cmp(u a, u b) {
    if (a.name!=b.name)
        if (strcmp(a.name,b.name)<=0)
            return true;
        else return false;
    if (strcmp(a.time, b.time)<=0) return true;
    else return false;
}

int main() {
    int cnt;
    cin >> cnt;
    int n = cnt;
    getchar();
    while(cnt--) {
        scanf("%s%s", &user[cnt].name, &user[cnt].time);
    }
    sort(user, user+n, cmp);
    // cout << "ok" << endl;

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (user[i].name==user[i-1].name) {
            string str(user[i].name);
            cout << str;
        }
        cnt = 0;
    }
    system("pause");
}