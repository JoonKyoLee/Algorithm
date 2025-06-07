import sys

N, M = map(int, input().split())

chess = [list(input()) for _ in range(N)]

change = sys.maxsize

for i in range(N - 7):
    for j in range(M - 7):
        count_w = 0
        count_b = 0

        for k in range(i, i + 8):
            for m in range(j, j + 8):  # k + m과 i + j 비교
                if (k + m) % 2 == (i + j) % 2:
                    if chess[k][m] != 'W': count_w += 1
                    if chess[k][m] != 'B': count_b += 1
                else:
                    if chess[k][m] == 'W': count_w += 1
                    if chess[k][m] == 'B': count_b += 1

        change = min(change, count_w, count_b)

print(change)
