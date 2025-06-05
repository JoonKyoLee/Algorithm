x, y, w, h = map(int, input().split())

distance1 = x
distance2 = y
distance3 = w - x
distance4 = h - y

print(min(distance1, distance2, distance3, distance4))
