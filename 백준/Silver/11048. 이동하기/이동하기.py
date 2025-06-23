n, m = map(int, input().split())

candy = []

for i in range(n):
    candy.append(list(map(int, input().split())))

for i in range(1, m):
    candy[0][i] = candy[0][i - 1] + candy[0][i]

for i in range(1, n):
    candy[i][0] = candy[i - 1][0] + candy[i][0]

for i in range(1, n):
    for j in range(1, m):
        candy[i][j] = max(candy[i - 1][j - 1], candy[i - 1][j], candy[i][j - 1]) + candy[i][j]

print(candy[n - 1][m - 1])
