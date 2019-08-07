import math

n = int(input())
a = list(map(int, input().split()))
f = [[math.inf for i in range(60)] for i in range(60)]
for i in range(0, n):
    f[i][i + 1] = 0
for len in range(2, n):
    for l in range(0, n - len):
        r = l + len;
        for k in range(l + 1, r):
            f[l][r] = min(f[l][r], f[l][k] + f[k][r] + a[l] * a[r] * a[k])

print(f[0][n - 1])

