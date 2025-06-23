N = int(input())

numbers = [[0] * 10 for _ in range(N + 1)]

for i in range(1, 10):
    numbers[1][i] = 1

mod = 1000000000

for i in range(2, N + 1):
    for j in range(10):
        if j == 0:
            numbers[i][j] = numbers[i - 1][1]
        elif 1 <= j <= 8:
            numbers[i][j] = numbers[i - 1][j - 1] + numbers[i - 1][j + 1]
        else:
            numbers[i][j] = numbers[i - 1][8]

print(sum(numbers[N]) % mod)
