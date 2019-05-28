#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int min_prime_factor[60000], not_prime[60000], cnt_prime;
bool composite[2000000];
int tmp[2000000], len_tmp;
// 预处理
void primes(int upper) {
    for (int i = 2; i <= upper; i++) {
        if (not_prime[i] == 0) {
            min_prime_factor[i] = i;
            prime[++cnt_prime] = i;
        }
        int tmp = upper / i;
        for (int j = 1; j <= cnt_prime; j++) {
            if (prime[j] > minimal_prime_factor[i] || prime[j] > tmp) break;
            minimal_prime_factor[i * prime[j]] = prime[j];
        }
    }
}

int main() {
    primes();
    int L, U;
    while(cin >> L >> U) {
        int upper = sqrt(U) + 1;
        memset(composite, 0, sizeof(composite));
        if (L == 1) composite[0] = true;
        for (int i = 1; min_prime_factor[i] <= upper; i++) {
            ll j = L / min_prime_factor[i];
            for (; j * min_prime_factor[i] <= U; j++) {
                if (j * min_prime_factor[i] < L || j < 2) continue;
                composite[j * min_prime_factor[i] - L] = true;
            }
        }
        len_tmp = 0;
        for (int i = L, cur = 0; i < U; i++, cur++) if (!composite[cur]) tmp[++len_tmp] = i;
        if (len_tmp > 1) {
            ll max_dist = -1, min_dist = 0x3f3f3f3f;
            pair<int, int> max_pair, min_pair;
            for (int i = 2; i <= len_tmp; i++) {
                if (tmp[i] - tmp[i - 1] > max_dist) {
                    max_dist = tmp[i] - tmp[i - 1];
                    max_pair.first = tmp[i - 1];
                    max_pair.second = tmp[i];
                }
                if (tmp[i] - tmp[i - 1] < min_dist) {
                    min_dist = tmp[i] - tmp[i - 1];
                    min_pair.first = tmp[i - 1];
                    min_pair.second = tmp[i];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", min_pair.first, min_pair.second, max_pair.first, max_pair.second);
        } else {
            cout << "There are no adjacent primes.\n";
        }
    }
}