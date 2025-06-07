N = int(input())

found = False

for i in range(1, N + 1):
    split_sum = i
    number_str = str(i)

    for letter in number_str:
        split_sum += int(letter)

    if split_sum == N:
        print(i)
        found = True
        break

if not found:
    print(0)
