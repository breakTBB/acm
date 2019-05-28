#include <bits/stdc++.h>

using namespace std;

int cmp(const void* a, const void*  b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int a[] = {1, 10, 2, 4, 0};
    qsort(a, sizeof(a) / sizeof(int), sizeof(int), cmp);
}