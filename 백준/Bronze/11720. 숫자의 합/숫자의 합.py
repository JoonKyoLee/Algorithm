N = int(input())
number = int(input())

sum = 0

for _ in range(N):
    sum += number % 10
    number //= 10

print(sum)
