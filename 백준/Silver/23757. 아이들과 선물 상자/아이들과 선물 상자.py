import heapq
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

arr1 = list(map(int, input().split()))
gifts = []
for ele in arr1:
    heapq.heappush(gifts, -ele)

children = list(map(int, input().split()))
possible = True

for child in children:
    gift = -heapq.heappop(gifts)
    if gift < child:
        possible = False
        break
    elif gift == child:
        continue
    else:
        heapq.heappush(gifts, -(gift - child))

if not possible: print(0)
else: print(1)
