// https://vjudge.net/problem/POJ-2251
// MLE可能是爆栈了

#include <iostream>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 40;
int L, R, C;
int ans;

struct Node {
	int z, x, y, t;
	Node() {}
	Node(int z, int x, int y, int t) : z(z), x(x), y(y), t(t) {}
};

queue<Node> q;
int dir[][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };

char maze[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];

bool ok(int z, int x, int y) {
	if (z < 1 || z > L || x < 1 || x > R || y < 1 || y > C || vis[z][x][y] || maze[z][x][y] == '#') return false;
	return true;
}

void bfs(Node start) {
	while (!q.empty()) q.pop();
	q.push(start);
	while (!q.empty()) {
		Node cur = q.front(); 
		q.pop();
		if (maze[cur.z][cur.x][cur.y] == 'E') {
			ans = cur.t;
			break;
		}
		if (!ok(cur.z, cur.x, cur.y)) continue;
		vis[cur.z][cur.x][cur.y] = 1;
		for (int i = 0; i < 6; i++) {
			int dz = cur.z + dir[i][0];
			int dx = cur.x + dir[i][1];
			int dy = cur.y + dir[i][2];
			int dt = cur.t + 1;
			Node nxt = Node{ dz, dx, dy, dt };
			q.push(nxt);
		}
	}
}

int main() {
	bool first = true;
	while (cin >> L >> R >> C) {
		if (L == 0 || R == 0 || C == 0) return 0;
		memset(vis, 0, sizeof vis);
		ans = INT_MAX;
		Node start, end;
		for (int i = 1; i <= L; i++)
			for (int j = 1; j <= R; j++)
				for (int k = 1; k <= C; k++) {
                    cin >> maze[i][j][k];
					if (maze[i][j][k] == 'S') start = { i, j, k, 0 };
					if (maze[i][j][k] == 'E') end = { i, j, k, 0 };
				}
		bfs(start);
		if (!first) cout << endl;
		if (ans == INT_MAX) cout << "Trapped!";
		else cout << "Escaped in " << ans << " minute(s).";
		first = false;
	}
}