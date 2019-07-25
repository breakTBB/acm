#include <bits/stdc++.h>

using namespace std;

struct Line{
	int start;
	int end;
}line[50010];

bool cmp(Line a, Line b) {
	return a.start < b.start;
}
int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		scanf("%d%d", &line[i].start, &line[i].end);
	}
	sort(line, line+cnt, cmp);
	int e = line[0].end;
	int len = 0, maxlen = 0;
	for (int i = 1; i < cnt; i++) {
		if (line[i].end <= e) len = line[i].end - line[i].start;
		else {
			len = e - line[i].start;
			e = line[i].end;
		}
		maxlen = max(len, maxlen);
	}
	cout << maxlen;
}