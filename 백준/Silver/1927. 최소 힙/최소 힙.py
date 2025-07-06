import heapq
import sys

N = int(sys.stdin.readline())

hq = []

for _ in range(N):
    num = int(sys.stdin.readline())

    if num == 0:
        if not hq:
            print(0)
        else:
            print(heapq.heappop(hq))
    else:
        heapq.heappush(hq, num)
