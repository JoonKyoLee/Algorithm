A = int(input())
B = int(input())
C = int(input())

result = A * B * C

numbers = [0] * 10

while result != 0:
    number = result % 10
    numbers[number] += 1
    result = result // 10

for number in numbers:
    print(number)
