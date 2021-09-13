// link: https://www.acwing.com/problem/content/125/
#include <bits/stdc++.h>
#define dbg(x) cout << #x << " : " << x << "\n";
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    // 设最终点的横坐标为a, a + 1, a + 2;
    // 原始点的为x1, x2, x3
    // 则和为|(x1 - a)| + |(x2 - (a + 1))| + |(x3 - (a + 2))|
    // 分离变量 |x1 - a| + |(x2 - 1) - a| + |(x3 - 2) - a|
    // 则a为x1, x2 - 1, x3 - 2的中位数
}