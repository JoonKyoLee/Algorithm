from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])

    visited = [[False] * m for _ in range(n)]
    q = deque()

    q.append((0, 0, 1))  # row, col, distance
    visited[0][0] = True

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    while q:
        r, c, dist = q.popleft()

        if r == n - 1 and c == m - 1:
            return dist

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                continue

            if maps[nr][nc] == 1 and not visited[nr][nc]:
                visited[nr][nc] = True
                q.append((nr, nc, dist + 1))

    return -1
