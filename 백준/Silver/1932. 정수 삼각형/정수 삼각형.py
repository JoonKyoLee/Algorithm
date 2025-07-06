import sys

N = int(sys.stdin.readline())

triangle = []
triangle_sum = [[0] * N for i in range(N)]

for _ in range(N):
    triangle.append(list(map(int, sys.stdin.readline().split())))

triangle_sum[0][0] = triangle[0][0]

for i in range(1, N):
    for j in range(i + 1):
        if j == 0 and j == i:
            triangle_sum[i][j] = triangle_sum[i - 1][j] + triangle[i + 1][j]
        else:
            triangle_sum[i][j] = max(triangle_sum[i - 1][j - 1], triangle_sum[i - 1][j]) + triangle[i][j]

print(max(triangle_sum[N - 1]))
