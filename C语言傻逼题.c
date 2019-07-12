#include <stdio.h>

int main() {
    int n = 1000, m = 5000;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0;j  < m; j++) {
            sum += i * j;
        }
    }
}