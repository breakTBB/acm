#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string max = "0";
    int idx = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str.length() > max.length()) {
            max = str;
            idx = i;
        }
        else {
            if (str.length() == max.length() && str > max) {
                max = str;
                idx = i;
            }
        }
    }
    cout << idx << endl;
    cout << max;
    system("pause");
    return 0;
}
