apple, banana = map(int, input().split())

for i in range(1, min(apple, banana) + 1):
    if apple % i == 0 and banana % i == 0:
        print(f"{i} {apple // i} {banana // i}")
