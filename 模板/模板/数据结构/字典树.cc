#include<iostream>
#include<cstdio>
using namespace std;
#define MAXS 10000
#define MAXT 100000
char buffer[MAXS];

struct TrieNode {
	int total;
	int nxt[26];
}trie[MAXT];
int topt = 1;
int root = 1;

void AddTrie(char* ptr) {
	int now = root;
	while (*ptr) {
		//*ptr-'a'
		if (!trie[now].nxt[*ptr-'a'])
			trie[now].nxt[*ptr-'a'] = ++topt;
		now = trie[now].nxt[*ptr-'a'];
		trie[now].total ++;
		ptr++;
	}
}

int QryTrie(char *ptr) {
	int now = root;
	while (*ptr) {
		if (!trie[now].nxt[*ptr-'a'])
			return 0;
		now = trie[now].nxt[*ptr-'a'];
		ptr++;
	}
	return trie[now].total;
}
		
int main() {
	freopen("input.txt","r",stdin);
	int n,m;
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%s\n",buffer);
		AddTrie(buffer);
	}
	for (int i=0;i<m;i++) {
		scanf("%s\n",buffer);
		cout<<QryTrie(buffer)<<endl;
	}
}