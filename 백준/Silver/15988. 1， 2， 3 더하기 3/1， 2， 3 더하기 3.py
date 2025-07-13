import sys

MOD_NUM = 1_000_000_009

T = int(sys.stdin.readline())
num = []

for _ in range(T):
    n = int(sys.stdin.readline())
    num.append(n)

dp = [0] * (max(num) + 1)
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4, max(num) + 1):
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    dp[i] %= MOD_NUM

for n in num:
    print(dp[n])
