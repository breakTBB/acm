#include <bits/stdc++.h>

using namespace std;

int n, m;
stack<int> s1;
stack<char> s2;

int lev(char x) {
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x == '^')
		return 3;
	return 0;
}

void calculate(stack<int>& s1, stack<char>& s2) {
	int y = s1.top();
	s1.pop();
	int x = s1.top();
	s1.pop();
	char z = s2.top();
	s2.pop();

	if (z == '+') s1.push(x + y);
	if (z == '-') s1.push(x - y);
	if (z == '*') s1.push(x * y);
	if (z == '/') s1.push(x / y);
	if (z == '^') s1.push(pow(x, y));
}

char str[1000000];

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);

// 检查括号匹配
// 检查++ -- /+ 这种符号连用
// 检查首个不为符号

	stack<int> s1;
	stack<char> s2;
	int temp = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			temp = temp * 10 + str[i] - '0';
			flag = true;
		}
		else {
			if (flag) {
				s1.push(temp);
				temp = 0;
				flag = false;
			}
			if (str[i] == '(') {
				s2.push(str[i]);
				continue;
			}
			if (str[i] == ')') {
				while (s2.top() != '(')
					calculate(s1, s2);
				s2.pop();
				continue;
			}
			while (!s2.empty() && lev(s2.top()) >= lev(str[i]))
				calculate(s1, s2);
			s2.push(str[i]);
		}
	}
	if (flag) {
		s1.push(temp);
	}
	while (!s2.empty())
		calculate(s1, s2);
	cout << s1.top() << endl;
	return 0;
}