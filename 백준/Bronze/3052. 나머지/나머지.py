numbers = [0] * 42

for _ in range(10):
    numbers[int(input()) % 42] += 1

different = 0

for number in numbers:
    if number != 0:
        different += 1

print(different)
