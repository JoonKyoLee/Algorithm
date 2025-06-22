n, k = map(int, input().split())

result = [[0] * (n + 1) for i in range(n + 1)]

for i in range(1, n + 1):
    result[i][0] = 1
    result[i][i] = 1

for i in range(2, n + 1):
    for j in range(1, i):
        result[i][j] = result[i - 1][j - 1] % 10007 + result[i - 1][j] % 10007

print(result[n][k] % 10007)
