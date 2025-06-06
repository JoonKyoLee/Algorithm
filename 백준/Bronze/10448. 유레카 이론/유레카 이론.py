# 정확히 3개의 삼각수의 합으로 이루어지는지 판단(단, 삼각수는 모두 달라야 할 필요는 없음)

# 삼각수가 같아도 되기 때문에 combination 보다는 permutation 사용해서 합을 구함
# K는 1,000을 넘지 않으므로 삼각수를 미리 계산해두고 순열을 이용

from itertools import combinations_with_replacement

T = int(input())

limit = 1
eureka_nums = []

while True:
    eureka_num = (limit * (limit + 1)) // 2
    if eureka_num > 1000:
        break
    eureka_nums.append(eureka_num)
    limit += 1

for _ in range(T):
    K = int(input())
    found = False

    for combination in combinations_with_replacement(eureka_nums, 3):
        if sum(combination) == K:
            found = True
            break

    if not found:
        print(0)
    else:
        print(1)
