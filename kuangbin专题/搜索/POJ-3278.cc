// https://vjudge.net/problem/POJ-3278
// RE 检查数组下标是否为负

#include <iostream>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

struct Node {
    int x, t;
    Node(int x, int t) : x(x), t(t) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    queue<Node> q;
    q.push(Node(n, 0));
    while(q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.x == k) {
            cout << cur.t;
            return 0;
        }
        q.push(Node(cur.x - 1, cur.t + 1));
        q.push(Node(cur.x + 1, cur.t + 1));
        q.push(Node(cur.x * 2, cur.t + 1));
    }
}