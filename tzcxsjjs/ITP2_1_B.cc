#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> d;
    int _tmp;
    cin >> _tmp;
    int op;
    while(cin >> op) {
        if (0 == op) {
            cin >> op;
            if (0 == op) {
                cin >> op;
                d.push_front(op);
            } else {
                cin >> op;
                d.push_back(op);
            }
        } else if (1 == op) {
            cin >> op;
            cout << d[op] << endl;
        } else {
            cin >> op;
            if (0 == op) d.pop_front();
            else d.pop_back();
        }
    }
    system("pause");
    return 0;
}
