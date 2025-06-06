from itertools import combinations

heights = [int(input()) for _ in range(9)]
heights.sort()

for combination in combinations(heights, 7):
    if sum(combination) == 100:
        for height in combination: print(height)
        break
