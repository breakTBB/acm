#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) {ret = (ret << 3) + (ret << 1) + (c ^ 48); c = getchar();}
    return ret * f;
}

const int N = 2e6 + 10;
int a[N];
deque<int> q;
int n, m;

int main() {
    n = read(); m = read();
    rep(i, 1, n) {
        a[i] = read();
        printf("%d\n", a[q.front()]);
        while(q.size() && i - m >= q.front()) q.pop_front();
        while(q.size() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
    }
}