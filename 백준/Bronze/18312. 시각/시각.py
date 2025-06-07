N, K = map(int, input().split())

count = 0

for i in range(N + 1):
    for j in range(60):
        for k in range(60):
            time_str = f"{i:02}{j:02}{k:02}"
            if str(K) in time_str:
                count += 1
print(count)
