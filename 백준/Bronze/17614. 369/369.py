N = int(input())

count = 0

for i in range(1, N + 1):
    number = i
    while number != 0:
        a = number % 10
        if a == 3 or a == 6 or a == 9:
            count += 1
        number = number // 10

print(count)
