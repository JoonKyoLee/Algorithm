num1, num2 = map(int, input().split())

reversed_num1 = num1 - (num1 % 10) + (num1 % 10 * 100) - (num1 // 100 * 100) + (num1 // 100)
reversed_num2 = num2 - (num2 % 10) + (num2 % 10 * 100) - (num2 // 100 * 100) + (num2 // 100)

print(max(reversed_num1, reversed_num2))
