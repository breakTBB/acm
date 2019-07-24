// https://vjudge.net/problem/POJ-3278

#include <iostream>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 10;

bool vis[maxn << 1];

struct Node {
	int x, t;
	Node(int x, int t) : x(x), t(t) {}
};

queue<Node> q;

int main() {
	int n, k;
	while (cin >> n >> k) {
		memset(vis, 0, sizeof vis);
		while (!q.empty()) q.pop();
		q.push(Node(n, 0));
		while (!q.empty()) {
			Node cur = q.front(); q.pop();
			if (cur.x < 0 || cur.x > 100000 || vis[cur.x]) continue;
			vis[cur.x] = 1;
			if (cur.x == k) {
				cout << cur.t << endl;
				break;
			}
			q.push(Node(cur.x - 1, cur.t + 1));
			if (cur.x < k) {
				q.push(Node(cur.x + 1, cur.t + 1));
				q.push(Node(cur.x * 2, cur.t + 1));
			}
		}
	}
}