#include <bits/stdc++.h>

using namespace std;


int main() {
    int num;
    //p q
    string s = "abcdefghijklmnopqrstuvwxyz";
    cin >> num;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        int tmp = str[i] - 'a';
        //24 27
        char chr = s[(tmp + num) % 26];
        printf("%c", chr);
    }
    system("pause");
}