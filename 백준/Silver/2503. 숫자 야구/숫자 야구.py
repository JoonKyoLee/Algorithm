from itertools import permutations

N = int(input())

answer = list(permutations([i for i in range(1, 10)], 3))

for _ in range(N):
    number, strike, ball = map(int, input().split())
    number = list(str(number))
    remove_number = []

    for ans in answer:
        ans = list(map(str, ans))
        s, b = 0, 0
        for i in range(3):
            if number[i] == ans[i]: s += 1
            elif number[i] in ans: b += 1

        if strike != s or ball != b:
            remove_number.append(tuple(map(int, ans)))

    for remove_num in remove_number:
        answer.remove(remove_num)

print(len(answer))
