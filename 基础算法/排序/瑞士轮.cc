#include <bits/stdc++.h>

#define rep(i, a, b) for (register int i = a; i <= b; i++)
#define per(i, a, b) for (register int i = a; i >= b; i--)
#define dbg(x) cout << #x << ": " << x << endl;
typedef long long ll;

using namespace std;

int read() {
	register int ret = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar(); }
	return ret;
}

const int N = 2e5 + 10;
int n, r, q;

struct node {
    int score, power, id;
    bool operator < (const node& rhs) {
        if (score != rhs.score) {
            return score > rhs.score;
        }
        return id < rhs.score;
    }
}W[N], L[N], A[N];

int main() {
    n = read(), r = read(), q = read();
    rep(i, 1, 2 * n) {
        A[i].id = i;
        A[i].score = read();
    }
    rep(i, 1, 2 * n) {
        A[i].power = read();
    }
    sort(A + 1, A + n + 1);
    while(r--) {
        for (int i = 1; i <= 2 * n; i += 2) {
            if (A[i].power < A[i + 1].power) {
                A[i + 1].score++;
                L[i] = A[i];
                W[i] = A[i + 1];
            } else {
                A[i].score++;
                L[i] = A[i + 1];
                W[i] = A[i];
            }
        }
        merge(L + 1, L + n + 1, W + 1, W + n + 1, A + 1);
    }
    cout << A[q].id << endl;
}