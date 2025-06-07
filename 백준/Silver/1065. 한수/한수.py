N = int(input())

count = 0

for i in range(1, N + 1):
    num_str = str(i)
    if len(num_str) == 1 or len(num_str) == 2:
        count += 1
    else:
        if int(num_str[0]) - int(num_str[1]) == int(num_str[1]) - int(num_str[2]):
            count += 1

print(count)
