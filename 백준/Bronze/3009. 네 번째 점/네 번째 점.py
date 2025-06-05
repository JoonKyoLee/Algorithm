import collections

vertex1 = list(map(int, input().split()))
vertex2 = list(map(int, input().split()))
vertex3 = list(map(int, input().split()))

vertex_x = [vertex1[0], vertex2[0], vertex3[0]]
vertex_y = [vertex1[1], vertex2[1], vertex3[1]]

# 딕셔너리로 판단
x = dict(collections.Counter(vertex_x))
y = dict(collections.Counter(vertex_y))

vertex4_x, vertex4_y = 0, 0

for key, value in x.items():
    if value == 1:
        vertex4_x = key

for key, value in y.items():
    if value == 1:
        vertex4_y = key

print(f"{vertex4_x} {vertex4_y}")
