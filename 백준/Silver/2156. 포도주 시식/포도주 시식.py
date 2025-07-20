import sys

n = int(sys.stdin.readline().strip())

wine = [int(sys.stdin.readline().strip()) for _ in range(n)]
dp = [0] * n

for i in range(0, n):
    if i == 0:
        dp[i] = wine[i]
    elif i == 1:
        dp[i] = dp[i - 1] + wine[i]
    elif i == 2:
        dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 1]), wine[i - 1] + wine[i])
    else:
        dp[i] = max(max(dp[i - 2] + wine[i], dp[i - 1]), dp[i - 3] + wine[i - 1] + wine[i])

print(dp[n - 1])
