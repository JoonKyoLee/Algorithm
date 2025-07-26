import sys

N, M = map(int, sys.stdin.readline().strip().split())

not_here = [sys.stdin.readline().strip() for _ in range(N)]
not_see = [sys.stdin.readline().strip() for _ in range(M)]

not_here_see = set(not_here) & set(not_see)

print(len(not_here_see))

for word in sorted(not_here_see):
    print(word)
