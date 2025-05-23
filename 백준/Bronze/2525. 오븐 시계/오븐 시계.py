A, B = map(int, input().split())
C = int(input())

H = A
M = B + C

H = int(H + (M / 60))
M = M % 60

if H >= 24:
    H = H - 24

print(H, M)
