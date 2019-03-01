#include <bits/stdc++.h>

using namespace std;

char py[11][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};

int main() {
    string num;
    cin >> num;
    int sum = 0;
    for (int i = 0; i < num.length(); i++) {
        sum += num[i] - '0';
    }
    string ans = to_string(sum);
    for (int i = 0; i < ans.length(); i++) {
        cout << py[ans[i] - '0'] << " ";
    }
    system("pause");
}