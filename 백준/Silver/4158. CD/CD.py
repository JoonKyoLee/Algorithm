import sys
input = sys.stdin.readline

while (cds := input().strip()) != '0 0':
    N, M = map(int, cds.split())
    A = set()
    for _ in range(N):
        cd = int(input())
        A.add(cd)

    count = 0
    for _ in range(M):
        cd = int(input())
        if cd in A:
            count += 1

    print(count)
