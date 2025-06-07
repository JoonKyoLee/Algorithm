X, Y, P1, P2 = map(int, input().split())

index = 0
found = False

for i in range(1000000):
    distance = P1 + X * i
    temp = (distance - P2)
    if temp >= 0 and temp % Y == 0:
        print(distance)
        found = True
        break

if not found:
    print(-1)
