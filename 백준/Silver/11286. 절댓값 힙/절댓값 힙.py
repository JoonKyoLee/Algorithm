import sys
import heapq

N = int(sys.stdin.readline())
abs_list = []

for _ in range(N):
    num = int(sys.stdin.readline())

    if num:
        heapq.heappush(abs_list, (abs(num), num))
    else:
        if abs_list:
            print(heapq.heappop(abs_list)[1])
        else:
            print(0)
