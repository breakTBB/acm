// 模拟 + 二叉树
// https://nanti.jisuanke.com/t/A1840

#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left, *right;
};
node* root;

node* insert(node* root, int x) {
	if (!root) {
		node* q = new node;
		q->data = x;
		q->left = q->right = NULL;
		return q;
	}
	if (x < root->data) root->left = insert(root->left, x);
	else root->right = insert(root->right, x);
	return root;
}

void find(node* root, int x) {
	if (root->data == x) return;
	if (x < root->data) { printf("E"); find(root->left, x); }
	else { printf("W"); find(root->right, x); }
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		root = NULL;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			root = insert(root, tmp);
		}
		int q;
		cin >> q;
		while (q--) {
			int val;
			cin >> val;
			find(root, val);
			puts("");
		}
	}
}