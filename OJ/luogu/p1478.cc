#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int height;
    int weight;
};

int main(int argc, char const *argv[])
{
    Tree tree[5010];
    int n, weight;
    cin >> n >> weight;
    int chair, height;
    cin >> chair >> height;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> tree[i].height >>  tree[i].weight;
    }
    sort(tree, tree+n, [](Tree a, Tree b) { return a.weight<b.weight; });
    for(int i = 0; i < n; i++) {
        if(height + chair < tree[i].height) continue;
        if(weight < tree[i].weight) continue;
        weight -= tree[i].weight;
        cnt++;
    }
    cout << cnt;
    system("pause");
    return 0;
}
