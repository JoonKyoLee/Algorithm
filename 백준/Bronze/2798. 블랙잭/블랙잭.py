import sys
from itertools import combinations

N, M = map(int, input().split())

cards = list(map(int, input().split()))

difference = sys.maxsize
cards_sum = 0

for combination in combinations(cards, 3):
    temp = M - sum(combination)
    if temp < 0:
        continue

    if temp < difference:
        difference = temp
        cards_sum = sum(combination)

print(cards_sum)
