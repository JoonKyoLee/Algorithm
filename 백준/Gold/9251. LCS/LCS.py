import sys

first_word = list(sys.stdin.readline().strip())
second_word = list(sys.stdin.readline().strip())

dp = [[0] * (len(first_word) + 1) for _ in range(len(second_word) + 1)]

for i in range(1, len(second_word) + 1):
    for j in range(1, len(first_word) + 1):
        if first_word[j - 1] == second_word[i - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[len(second_word)][len(first_word)])
