N, K = map(int, input().split())

gugudan = []

for i in range(1, K + 1):
    gugudan.append(int(str(N * i)[::-1]))

print(max(gugudan))
