#include <iostream>

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>

using namespace std;

int main() {
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(10);
    // v.push_back(30);
    // v.insert(v.end(), 40);
    // v.insert(v.begin(), 1);
    // // for(auto i : v) cout << i;
    // list<int> l;
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(2);
    
    // l.erase(l.begin() + 1 , l.end());
    // cout << l.back();
    // vector<int> n = {3,2,1,6,7,3,4,7,1,17};
    // sort(n.begin(), n.end(), greater<int>());
    // bool f = binary_search(n.begin(), n.end(),17);
    // if (f) cout << "yes";
    // else cout << "no";
    vector<int> n = {1, 2, 1, 2};
    int cnt = count(n.begin(), n.end(), 2);
    cout << cnt;
    // while(next_permutation(n.begin(), n.end())) {
    //     for (auto i : n) cout << i << " ";
    //     cout << endl;
    // }
    // while(prev_permutation(n.begin(), n.end()))
    //     cout << "can't execute";

    system("pause");
}