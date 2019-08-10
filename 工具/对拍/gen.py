n, m = map(int, input().split())
a = [[0] for i in range(90)]
for i in range(n):
    a[i] = list(map(int, [i for i in input().split() if i != ' ']))
ans = 0
for i in range(n):
    dp = [[0 for i in range(60)] for i in range(60)]
    for len in range(1, m + 1):
        for l in range(m - len + 1):
            r = l + len - 1
            dp[l][r] = max(dp[l + 1][r] + a[i][l] * 2 ** (m - len + 1), dp[l][r - 1] + a[i][r] * 2 ** (m - len + 1))
    ans += dp[0][m - 1]
print(ans)
