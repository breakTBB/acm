#include <bits/stdc++.h>

using namespace std;

struct P {
    int n;
    int grade;
}p[5010];

bool cmp(P a, P b) {
    if (a.grade != b.grade)
    return a.grade > b.grade;
    else {
        return a.n < b.n;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        p[i].n = t1;
        p[i].grade = t2;
    }
    sort(p, p + n, cmp);
    int c_o_p = floor(m * 1.0 * 1.5);
    for (int i = c_o_p; i < n; i++) {
        if (p[i].grade == p[i - 1].grade) c_o_p++;
        else break;
    }
    cout << p[c_o_p - 1].grade << " " << c_o_p << endl;
    for (int i = 0; i < c_o_p; i++) {
        cout << p[i].n << " " << p[i].grade << endl;
    }
    system("pause");
}