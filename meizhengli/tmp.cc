#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int mx = -inf;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while(isdigit(c)) ret = (ret << 3) + (ret << 1) + c ^ 48, c = getchar();
    return ret * f;
}

int main() {
    int sum = 0;
    int n, k;
    cin >> n >> k;
    int t = k;
    deque<int> d(k);
    while(k--) {
        int tmp = read();
        d.push_back(tmp);
        sum += tmp;
    }
    mx = max(sum, mx);
    for (int i = 1; i <= n - t; i++) {
        int num = read();
        sum -= d.front();
        sum += num;
        mx = max(sum, mx);
        d.pop_front();
        d.push_back(num);
    }
    cout << mx;
}
