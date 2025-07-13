import sys
from collections import deque

n = int(sys.stdin.readline())
v = int(sys.stdin.readline())
graph = [[] for i in range(n + 1)]
visited = [0] * (n + 1)

for i in range(v):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

visited[1] = 1
Q = deque([1])

while Q:
    c = Q.popleft()
    for nx in graph[c]:
        if visited[nx] == 0:
            Q.append(nx)
            visited[nx] = 1

print(sum(visited) - 1)
