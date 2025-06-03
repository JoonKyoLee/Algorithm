A, B, C = map(int, input().split())

one_per_money = C - B

if one_per_money <= 0:
    print(-1)
else:
    print(A // one_per_money + 1)
