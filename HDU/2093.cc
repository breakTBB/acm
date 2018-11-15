#include <bits/stdc++.h>

using namespace std;

struct Stu {
    int acnum, time;
    char name[10];
};

int n, m, i, num, wa, ac, x, y;
Stu data[100000];
char s[20];
bool pd;

bool cmp(Stu x, Stu y) {
    if (x.acnum > y.acnum) return true;
    if (x.acnum == y.acnum && x.time < y.time) return true;
    if (x.acnum == y.acnum && x.time == y.time && strcmp(x.name, y.name) <= 0) return true;
    return false;
}

int main() {
    freopen("in", "r", stdin);
    cin >> n >> m;
    num  = 1;
    while(~scanf("%s", data[num].name)) {
        wa = 0; ac = 0;
        for(i = 1; i <= n; i++) {
            memset(s, '\0', sizeof(s));
            pd = false;
            scanf("%s", s);
//            没有AC
            if (s[0] == '-' || s[0] == '0') pd = true;
            if (s[1] == '(' || strlen(s) >= 5) {
                pd = true;
                ++ac;
                sscanf(s, "%d(%d)", &x, &y);
                data[num].time += x;
                wa += y;
            }
            if (pd == false) {
                ++ac;
                sscanf(s, "%d", &x); data[num].time += x;
            }
        }
        data[num].time += wa * m;
        if (data[num].time < 0) data[num].time = 0;
        data[num].acnum = ac;
        ++num;
    }
    cout << "xxxxxxxxxxxxxxxxxxxx" << num << endl;
    sort(data + 1, data + num, cmp);
    //for (i = 1; i <= num - 1; i++) printf("%-10s %2d %4d\n", data[i].name, data[i].acnum, data[i].time);
    freopen("CON",'r',stdin);
    return 0;
}