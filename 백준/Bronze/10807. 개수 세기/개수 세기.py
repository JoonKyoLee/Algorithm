n = int(input())
numbers = list(map(int, input().split()))
target_number = int(input())

count = 0
for number in numbers:
    if number == target_number:
        count = count + 1

print(count)
