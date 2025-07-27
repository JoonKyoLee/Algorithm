import sys
import collections

N = int(sys.stdin.readline().strip())
card = list(map(int, sys.stdin.readline().strip().split()))
card.sort()
card_dict = collections.Counter(card)

M = int(sys.stdin.readline().strip())
condition = list(map(int, sys.stdin.readline().strip().split()))

for num in condition:
    count = card_dict.get(num)
    if count is not None:
        print(count, end=" ")
    else:
        print(0, end=" ")
