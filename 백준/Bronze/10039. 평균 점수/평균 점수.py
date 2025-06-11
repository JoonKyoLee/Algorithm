a = []
for i in range(5):
    a.append(int(input()))

sum = 0

for i in range(5):
    if a[i] < 40:
        sum += 40
    else:
        sum += a[i]

print(int (sum / 5))
