#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> s;
    string str;
    while(cin >> str) {
        if (isdigit(str)) s.push(atoi(str.c_str()));
        else {
            if (str == "+") {
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                s.push(a+b);
            }
            if (str == "-") {
                int a = s.top();s.pop();
                int b = s.top();s.pop();
                s.push(b-a);
            }
        }
    }
    cout << s.top();
    system("pause");
}