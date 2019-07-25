// 给定两个正整数，计算这两个数的最小公倍数。
// Sample Input
// 10 14

// Sample Output
// 70

#include <bits/stdc++.h>

int gcd(int m, int n) {
    return n==0?m:gcd(n, m%n);
}

using namespace std;

int main() {
    int m, n;
    while(cin >> m >> n) {
        cout << (m*n)/gcd(m, n);
    }
    
}