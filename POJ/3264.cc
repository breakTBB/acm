// #include <bits/stdc++.h>

// using namespace std;

// const int maxn = 2 * 1e5 + 10;

// int mx[maxn][20];
// int mn[maxn][20];
// int a[maxn];

// int n, q;


// void init() {
//     for (int i = 1; i <= n; ++i) mx[i][0] = mn[i][0] = a[i];
//     int t = log(n) / log(2) + 1;
//     for (int j = 1; j < t; j++)
//         for (int i = 1; i <= n - (i << j) + 1; i++) {
//             mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
//             mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
//         }
// }

// int qmx(int l, int r) {
//     int k = log(r - l + 1) / log(2);
//     return max(mx[l][k], mx[r - (1 << k + 1)][k]);
// }

// int qmn(int l, int r) {
//     int k = log(r - l + 1) / log(2);
//     return min(mn[l][k], mn[r - (1 << k + 1)][k]);
// }

// int main() {
//     cin >> n >> q;
//     for (int i = 1; i <= n; ++i) cin >> a[i];
//     init();
//     while(q--) {
//         int a, b;
//         cin >> a >> b;
//         cout << qmx(a, b) - qmn(a, b) << endl;
//     }
// }